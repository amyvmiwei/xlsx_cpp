#include "WorkBook.h"
#include "Sheet.h"
#include "error.h"

#include "unzip.h"

#include "../pugixml/pugiconfig.hpp"
#include "../pugixml/pugixml.hpp"

#include <string>
#include <iostream>
#include <assert.h>

static void parseShardString(char* data, unsigned int size)
{
	WorkBook::Inst().loadSharedStrings(data, size);
}

static void parseWorkbook(char* data, unsigned int size)
{
	WorkBook::Inst().loadWorkbook(data, size);
}

static void parseSheet(char* data, unsigned int size)
{
	WorkBook::Inst().loadSheetData(data, size);
}


WorkBook& WorkBook::Inst()
{
	static WorkBook _wbInst;
	return _wbInst;
}

WorkBook::WorkBook()
{
	m_mapSheets.clear();
	m_zipfile = NULL;
}


WorkBook::~WorkBook()
{
	std::map<std::string, Sheet*>::iterator it = m_mapSheets.begin();
	for (; it != m_mapSheets.end(); ++it)
	{
		if (it->second)
			delete it->second;
	}
	m_mapSheets.clear();
	unzClose(m_zipfile);
}

bool WorkBook::load(const char* const filename)
{
	if (0 == filename)
		return false;

	m_zipfile = unzOpen64(filename);
	bool b;
	b = _extrafile(&m_zipfile, "xl/sharedStrings.xml", parseShardString);
	assert(b);
	b = _extrafile(&m_zipfile, "xl/workbook.xml", parseWorkbook);
	assert(b);

	//	do_extract_onefile(uf, "xl/workbook.xml", 0, 0, 0);

	return true;
}


Sheet* WorkBook::getSheet(const char* const name)
{
	if (!name)
		return NULL;

	std::map<std::string, Sheet*>::iterator itFind = m_mapSheets.find(name);
	if (itFind != m_mapSheets.end())
		return itFind->second;

	return NULL;
}

void WorkBook::getSheetNames(std::vector<std::string>& v)
{
	std::map<std::string, Sheet*>::iterator it = m_mapSheets.begin();
	for ( ; it != m_mapSheets.end(); ++it)
	{
		v.push_back(it->first);
	}
}

bool WorkBook::loadWorkbook(const char* data, unsigned int size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);//doc.load_file(filename, pugi::parse_default, pugi::encoding_auto);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	pugi::xml_node sheetNode;
	for (pugi::xml_node tmpNode = root.first_child(); tmpNode; tmpNode = tmpNode.next_sibling())
	{
		if (tmpNode.name() == std::string("sheets")) {
			sheetNode = tmpNode;
			break;
		}
	}
	if (sheetNode.empty())
	{
	}
	else
	{
		for (pugi::xml_node sheet = sheetNode.first_child(); sheet; sheet=sheet.next_sibling())
		{
			std::string name = sheet.attribute("name").as_string();
			Sheet* newSheet = new Sheet(name.c_str());
			if (!newSheet) {
				error_code = ERROR_CODE_MEMORY_FULL;
				return false;
			}

			// shaderstrings.xml
			// sheet[i].xml

			std::string _sheetfilename = "xl/worksheets/";
			_sheetfilename += name;
			_sheetfilename += ".xml";

			bool b = _extrafile(&m_zipfile, _sheetfilename.c_str(), parseSheet);

			//loadSheetData(newSheet, _sheetfilename.c_str());
		}
	}

	return true;
}

bool WorkBook::loadSharedStrings(char* data, unsigned size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);//doc.load_file("G:\\zData\\openxml_xlsx\\员工通讯录abc\\xl\\sharedStrings.xml", pugi::parse_default, pugi::encoding_auto);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	assert(root.name() == std::string("sst"));
	
	for (pugi::xml_node si = root.first_child(); si; si = si.next_sibling())
	{
		if (si.name() == std::string("si"))
		{
			const char* svalue = si.child_value("t");
			

			std::string strValue = svalue;
			std::string strRetValue = svalue;
			UTF8ToGBK(strRetValue , strValue);

			std::cout << strRetValue.c_str() << std::endl;

			//utf8 -> ascII. or not.
			m_sharedStrings.m_sharedStrings.push_back(strRetValue);
		}
	}
	return true;
}

bool WorkBook::loadSheetData(char* data, unsigned size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);//doc.load_file(filename);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	pugi::xml_node sheetNode;
	for (pugi::xml_node tmpNode = root.first_child(); tmpNode; tmpNode = tmpNode.next_sibling())
	{
		if (tmpNode.name() == std::string("sheetData")) {
			sheetNode = tmpNode;
			break;
		}
	}
	
	if (sheetNode.empty())
	{
	}
	else
	{
		for (pugi::xml_node row = sheetNode.first_child(); row; row = row.next_sibling())
		{
			std::string r = row.attribute("r").as_string();
			
			for (pugi::xml_node c = row.first_child(); c; c = c.next_sibling())
			{
				if (c.name() != std::string("c"))
				{
					continue;
				}

				std::string cr = c.attribute("r").as_string();
				int			cs = c.attribute("s").as_int();
				std::string ct = c.attribute("t").as_string();

				//获得<v>value</v>
				const char* svalue = c.child_value("v");

				if (ct == std::string("s"))
				{
					int tvalue = atoi(svalue);
					
					std::cout << m_sharedStrings.m_sharedStrings[tvalue] << std::endl;
				}
				else if (ct == std::string("b"))
				{
					int tvalue = atoi(svalue);
					std::cout << ((tvalue==1) ?  "true" : "false") << std::endl;
				}
				else
				{
					std::string strIsFloat = svalue;
					int findDot = strIsFloat.find(".");
					if (-1 != findDot)
					{
						std::cout << atof(svalue) << std::endl;
					}
					else
					{
						std::cout << atoll(svalue) << std::endl;

						// 日期，年月日等格式。
					}
				}
			
				/* append value.
				pugi::xml_node new_node = window.append_child(vecNode[i].first.c_str());
				new_node.append_child(pugi::node_pcdata).set_value(vecNode[i].second.c_str());
				*/

// 				for (pugi::xml_node v = c.first_child(); v ; v = v.next_sibling())
// 				{
// 					if (v.name() != std::string("v"))
// 						continue;
// 					
// 					const char* svalue = v.value();
// 
// 
// 				}
			}
		}
	}

	return true;
}




bool WorkBook::_extrafile(void* pZip, const char* filename, funParser pfun)
{
	unzFile* puf = (unzFile*)pZip;
	assert(puf);
	unzFile& uf = *puf;
	unz_file_info64 file_info;
	char filename_inzip[256];
	char* filename_withoutpath;
	char* p;

	char* buf;
	unsigned int size_buf;

	int err = UNZ_OK;
	#define CASESENSITIVITY (0)
	if (unzLocateFile(uf, filename, CASESENSITIVITY) != UNZ_OK)
	{
		assert(false);
		return false;
	}

	err = unzGetCurrentFileInfo64(uf, &file_info, filename_inzip, sizeof(filename_inzip), NULL, 0, NULL, 0);
	if (err != UNZ_OK)
	{
		assert(false);
		return false;
	}
	p = filename_withoutpath = filename_inzip;
	while ((*p) != '\0')
	{
		if (((*p) == '/') || (*p) == '\\')
			filename_withoutpath = p + 1;
		p++;
	}

	//一定要走这里...扫后阅读它的源码;
	err = unzOpenCurrentFilePassword(uf, 0);
	if (err != UNZ_OK)
	{
		printf("error %d with zipfile in unzOpenCurrentFilePassword\n", err);
	}

	assert(err == UNZ_OK);

	printf("parse [%s] uncompress size is [%d]\n", filename, file_info.uncompressed_size);
	buf = (char*)malloc(static_cast<size_t>(file_info.uncompressed_size));
	size_buf = static_cast<unsigned int>(file_info.uncompressed_size);
	//#define WRITEBUFFERSIZE (8192)
	//size_buf = WRITEBUFFERSIZE;
	//buf = (char*)malloc(size_buf);
	do
	{
		err = unzReadCurrentFile(uf, (void*)buf, size_buf);
		if (err < 0)
		{
			printf("error %d with zipfile in unzReadCurrentFile\n", err);
			break;
		}
		if (err > 0)
		{
			pfun(buf, size_buf);
		}
	} while (err > 0);

	free(buf);
	err = unzCloseCurrentFile(uf);
	return true;
}
#include "WorkBook.h"
#include "Sheet.h"
#include "error.h"

#include "../pugixml/pugiconfig.hpp"
#include "../pugixml/pugixml.hpp"

#include <string>
#include <iostream>
#include <assert.h>

WorkBook& WorkBook::Inst()
{
	static WorkBook _wbInst;
	return _wbInst;
}

WorkBook::WorkBook()
{
	m_mapSheets.clear();
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

bool WorkBook::load(const char* const filename)
{
	if (NULL == filename)
		return false;

	this->loadSharedStrings();

	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_file(filename, pugi::parse_default, pugi::encoding_auto);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	//pugi::xml_node sheetNode = root.find_node("sheets");
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

			std::string _sheetfilename = "G:\\zData\\openxml_xlsx\\员工通讯录abc\\xl\\worksheets\\";
			_sheetfilename += name;
			_sheetfilename += ".xml";
			loadSheetData(newSheet, _sheetfilename.c_str());
		}
	}

	return true;
}

bool WorkBook::loadSharedStrings()
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_file("G:\\zData\\openxml_xlsx\\员工通讯录abc\\xl\\sharedStrings.xml", pugi::parse_default, pugi::encoding_auto);
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

bool WorkBook::loadSheetData(Sheet* sheet, const char* const filename)
{
	sheet = NULL;
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_file(filename);
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
}
#pragma once
#include "SharedStrings.h"
#include <vector>
#include <map>
#include <string>
#include "unzip.h"

typedef void (*funParser)(char* data, unsigned int size);
class Sheet;
class WorkBook
{
public:
	static WorkBook& Inst();

	bool		load(const char* const filename);

	//TODO:miwei add ignore cast.
	Sheet*		getSheet(const char* const name);

	void		getSheetNames(std::vector<std::string>& v);

	//TODO:miwei add setSheet or addSheet, for write interface.

private:
	WorkBook();
	~WorkBook();

public:
	bool		loadWorkbook		(const char* data, unsigned int size);
	bool		loadSharedStrings	(char* pdata, unsigned size);
	bool		loadSheetData		(char* pdata, unsigned size);
	bool		loadStyle			(char* pdata, unsigned size);

private:
	bool		_extrafile(void* pZip, const char* filename, funParser pfun);

private:
	std::map<std::string, Sheet*>	m_mapSheets;
	SharedStrings					m_sharedStrings;
	std::vector<int>				m_styleID;

	unzFile		m_zipfile;
};


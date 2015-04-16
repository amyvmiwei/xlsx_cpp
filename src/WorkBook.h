#pragma once
#include "SharedStrings.h"
#include <vector>
#include <map>
#include <string>

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


private:
	bool		loadSharedStrings();
	bool		loadSheetData(Sheet* sheet, const char* const filename);

private:
	std::map<std::string, Sheet*>	m_mapSheets;
	SharedStrings					m_sharedStrings;
};


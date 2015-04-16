#pragma once

#include <vector>
#include <map>
#include <string>

class ExcelOpenXml
{
public:
	ExcelOpenXml();
	~ExcelOpenXml();

	bool OpenBook(const char* const filename);
};


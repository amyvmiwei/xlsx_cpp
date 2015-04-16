#include "Sheet.h"


Sheet::Sheet(const char* const name) : m_maxCol(0)
{
	m_name = name;
	m_datas.clear();
}


Sheet::~Sheet()
{
}

int Sheet::getRows()
{
	return m_datas.size();
}

int Sheet::getCols()
{
	return m_maxCol;
}

// int Sheet::getMaxValidRow()
// {
// 	return 0;
// }
// 
// int Sheet::getMaxValidCol()
// {
// 	return 0;
// }
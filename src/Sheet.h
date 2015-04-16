#pragma once
#include <vector>

class Cell;

typedef std::vector<Cell*>		ROWS;
typedef std::vector<ROWS>		COLS;

typedef ROWS::iterator			ROWS_ITER;
typedef COLS::iterator			COLS_ITER;


class Sheet
{
public:
	Sheet(const char* const name);
	~Sheet();

	int		getRows();
//	int		getMaxValidRow();
	int		getCols();
//	int		getMaxValidCol();

private:
	COLS	m_datas;
	int		m_maxCol;
	std::string m_name;
};


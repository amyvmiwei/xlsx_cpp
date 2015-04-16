#pragma once
#include <vector>
#include <string>

class SharedStrings
{
public:
	SharedStrings();
	~SharedStrings();

	std::vector<std::string>	m_sharedStrings;
};


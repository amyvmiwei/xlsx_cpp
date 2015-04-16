#pragma once
#include <string>
enum ERROR_CODE
{
	ERROR_CODE_INVALID=-1,

	ERROR_CODE_SUCCESS=0,
	ERROR_CODE_MEMORY_FULL,

	ERROR_CODE_COUNT,
};

extern int error_code;

int		getLastError();
void UTF8ToGBK(std::string &dst, const std::string& src);

#define LAST_ERROR error_code;
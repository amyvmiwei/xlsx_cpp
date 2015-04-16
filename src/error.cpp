#include "error.h"

#include <string>
#include <windows.h>

int error_code = 0;


int getLastError() {return error_code;}


void GBKToUTF8(std::string &dst, const std::string& src)
{
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	dst = str2;
	delete[]str1;
	delete[]str2;
}


void UTF8ToGBK(std::string &dst, const std::string& src)
{
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_ACP, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_ACP, 0, str1, -1, str2, n, NULL, NULL);
	dst = str2;
	delete[]str1;
	delete[]str2;
}
#include "Cell.h"
#include <string.h>

Cell::Cell(enum VALUE_TYPE vt, const char* const sValue)
{
	type = vt;
	value.str = new char[strlen(sValue)+1];
	//strcpy(value.str, sValue);
}


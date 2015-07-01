#pragma once

#include <stdio.h>

struct TimeDate
{
	TimeDate()
	:year(0), month(0), day(0), h(0), m(0), s(0), nanosecond(0)
	{}

	TimeDate(int _y, int _month, int _day, int _h, int _m, int _s, int _nanos)
		:year(_y), month(_month), day(_day), h(_h), m(_m), s(_s), nanosecond(_nanos)
	{}

	int year;
	int month;
	int day;
	int h;
	int m;
	int s;
	int nanosecond;

	//1年1月1日，00：00：00
	int daysOffset()
	{
		int y = year;
		int m = month;
		int d = day;
		unsigned char x[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int i, s = 0;
		for (i = 1; i < y; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			s += 366;//闰年
			else
				s += 365;//平年
		}

		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			x[2] = 29;
		else
			x[2] = 28;

		for (i = 1; i < m; i++)
			s += x[i];//整月的天数

		s += d;//日的天数

		return s;//返回总天数,相对公元1年
	}

	int daysOffset(int y, int m, int d)
	{
		TimeDate td;
		td.year = y;
		td.month = m;
		td.day = d;
		return td.daysOffset() - daysOffset();
	}

	int secondOffset()
	{
		return daysOffset() * 24 * 3600 + h * 3600 + m * 60 + s;
	}

	void addDays(int d)
	{
		int y = year;
		unsigned char x[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			x[2] = 29;
		else
			x[2] = 28;

		int _m = month;
		int _d = day;
		while (d--)
		{
			int _day = _d + 1;
			if (_day > x[_m])
			{
				_m++;
				if (_m > 12)
				{
					y++;
					if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
						x[2] = 29;
					else
						x[2] = 28;

					_m = 1;
				}

				_d = 0;
			}
			_d++;
		}

		year = y;
		month = _m;
		day = _d;
	}

	TimeDate& add(double offset)
	{
		//
		double offset_day = offset / (3600.0*24.0);
		int offsetDay = (int)offset_day;

		//
		double lastOffsetDay = (offset_day - offsetDay);
		double currentLastSecond = lastOffsetDay*3600.0*24.0; // second;

		//
		double offset_hour = (currentLastSecond) / (3600.0);
		int offsetHour = (int)offset_hour;
		double offset_min = (offset_hour - offsetHour) * 3600 / 60.0;
		int offsetMin = (int)offset_min;
		int offsetSecond = offset_min - offsetMin;

		addDays(offsetDay);
		h += offsetHour;
		m += offsetMin;
		s += offsetSecond;

		return *this;
	}

	void toString(char output[32])
	{
		sprintf_s(output, 32, "%04d-%02d-%02d %02d:%02d:%02d", year, month,day, h, m, s);
	}
};


// static inline unsigned long _mktime(unsigned int year, unsigned int mon,
// 	unsigned int day, unsigned int hour,
// 	unsigned int min, unsigned int sec)
// {
// 	if (0 >= (int)(mon -= 2)) {    /* 1..12 -> 11,12,1..10 */
// 		mon += 12;      /* Puts Feb last since it has leap day */
// 		year -= 1;
// 	}
// 
// 	unsigned long ul = (((
// 			 (unsigned long)(year / 4 - year / 100 + year / 400 + 367 * mon / 12 + day) +
// 			 year * 365 - 719499
// 		  ) * 24 + hour /* now have hours */
// 	   ) * 60 + min /* now have minutes */
// 	) * 60 + sec; /* finally seconds */
// 
// 	return ul;
// }

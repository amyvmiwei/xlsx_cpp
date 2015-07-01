#include "date.h"
#include <math.h>
#include <time.h>
#include "dateOffset.h"

typedef unsigned long long uint64;
typedef			long long	int64;


const double MJD_0		= 2400000.5;
const double MJD_JD2000 = 51544.5;


static void shiftJulianToNoon(double julianDays, double julianFraction, double& _j_days, double& _j_fraction)
{
// 	switch {
// 	case -0.5 < julianFraction && julianFraction < 0.5:
// 	julianFraction += 0.5
// 	case julianFraction >= 0.5:
// 	julianDays += 1
// 	julianFraction -= 0.5
// 	case julianFraction <= -0.5:
// 	julianDays -= 1
// 	julianFraction += 1.5
// 	}
// 	return julianDays, julianFraction

	if ( -0.5 < julianFraction && julianFraction < 0.5)
		julianFraction += 0.5;

	if  (julianFraction >= 0.5) {
		julianDays += 1;
		julianFraction -= 0.5;
	}

	if (julianFraction <= -0.5) {
		julianDays -= 1;
		julianFraction += 1.5;
	}

	//return julianDays, julianFraction.
	_j_days = julianDays;
	_j_fraction = julianFraction;
}


static double mod(double d, int v)
{
	return int(d) % v;
}

static void _modf(double value, int& v, double & v1)
{
	v = (int)(value);
	v1 = value - (double)v;
}

static void fractionOfADay(double fraction, int& hours, int &minutes, int& seconds, int& nanoseconds) {
double f = 5184000000000000 * fraction;
nanoseconds = int(mod(f, 1000000000));
f = f / 1000000000;
seconds = int(mod(f, 3600));
f = f / 3600;
minutes = int(mod(f, 60));
f = f / 60;
hours = int(f);
//return hours, minutes, seconds, nanoseconds

}

void doTheFliegelAndVanFlandernAlgorithm(int jd, int d, int m, int y) {
double l = jd + 68569;
double n = (4 * l) / 146097;
l = l - (146097 * n + 3) / 4;
double i = (4000 * (l + 1)) / 1461001;
l = l - (1461 * i) / 4 + 31;
double j = (80 * l) / 2447;
d = l - (2447 * j) / 80;
l = j / 11;
m = j + 2 - (12 * l);
y = 100 * (n - 49) + i + l;
//return d, m, y
}

static tm julianDateToGregorianTime(double part1, double part2)
{
	int p1I, p2I;
	double p1F, p2F;
	_modf(part1, p1I, p1F);
	_modf(part2, p2I, p2F);

	double julianDays = p1I + p2I;
	double julianFraction = p1F + p2F;

	shiftJulianToNoon(julianDays, julianFraction, julianDays, julianFraction);

	int day=0, month=0, year=0;
	doTheFliegelAndVanFlandernAlgorithm(int(julianDays), day, month, year);

	int hours=0, minutes=0, seconds=0, nanoseconds=0;
	fractionOfADay(julianFraction, hours, minutes, seconds, nanoseconds);

	//return time.Date(year, time.Month(month), day, hours, minutes, seconds, nanoseconds, time.UTC)
	tm tm1;
	tm1.tm_yday = year;
	tm1.tm_mon = month;
	tm1.tm_mday = day;
	tm1.tm_hour = hours;
	tm1.tm_min = minutes;
	tm1.tm_sec = seconds;
	
	return tm1;
}

static inline unsigned long _mktime(unsigned int year, unsigned int mon,
	unsigned int day, unsigned int hour,
	unsigned int min, unsigned int sec)
{
	if (0 >= (int)(mon -= 2)) {    /* 1..12 -> 11,12,1..10 */
		mon += 12;      /* Puts Feb last since it has leap day */
		year -= 1;
	}

	unsigned long ul = (((
			 (unsigned long)(year / 4 - year / 100 + year / 400 + 367 * mon / 12 + day) +
			 year * 365 - 719499
		  ) * 24 + hour /* now have hours */
	   ) * 60 + min /* now have minutes */
	) * 60 + sec; /* finally seconds */

	return ul;
}

//#include <afxdisp.h>
// 	COleDateTime oleDT1;
tm TimeFromExcelTime(double excelTime, bool date1904)
{	
	int64 intPart = (int64)(excelTime);
// 	if (intPart <= 61) {
// 		const double OFFSET1900 = 15018.0;
// 		const double OFFSET1904 = 16480.0;
// 		time_t tt = time(0);
// 		tm date= {0};
// 		::localtime_s(&date, &tt);
// 		if (date1904) {
// 			date = julianDateToGregorianTime(MJD_0, excelTime+OFFSET1904);
// 		} else {
// 			date = julianDateToGregorianTime(MJD_0, excelTime+OFFSET1900);
// 		}
// 		return date;
// 	}

	tm datee;
	TimeDate date;
	double floatPart = excelTime - double(intPart);
	//double dayNanoSeconds = 24 * 60 * 60 * 1000 * 1000 * 1000;
	double dayNanoSeconds = 24 * 60 * 60;
	if (date1904) {
		date = TimeDate(1904, 1, 1, 0, 0, 0, 0);
	} else {
		date = TimeDate(1899, 12, 30, 0, 0, 0, 0);
	}

	double durationDaysToSecond = intPart*24*3600;
	double durationLeftSecond = dayNanoSeconds*floatPart;
	double allOffsetSecond = durationDaysToSecond+durationLeftSecond;
	date.add(allOffsetSecond);

	tm t1 = { 0 };
	t1.tm_year = date.year;
	t1.tm_mon = date.month;
	t1.tm_mday = date.day;
	t1.tm_hour = date.h;
	t1.tm_min = date.m;
	t1.tm_sec = date.s;
	t1.tm_isdst = 1;
	return t1;


//// 	tm t1={0};
//// 	t1.tm_year = 1904-1900;
//// 	t1.tm_mon = 0;
//// 	t1.tm_mday = 1;
//// 	t1.tm_hour = 0;
//// 	t1.tm_min = 0;
//// 	t1.tm_sec = 0;
//// 	t1.tm_isdst = 1;
//// 	time_t rrr = mktime(&t1);
//	uint64 ul = 0;//= _mktime(4, 0, 1, 0, 0, 0);
//	ul = (durationDaysToSecond + durationLeftSecond) - ul;
//
//
//
//	tm t;
//	time_t m_time = ul/*41640*/;
//	::localtime_s(&t, &m_time);
//
//	int second = t.tm_sec;
//	int minute = t.tm_min;
//	int hour = t.tm_hour;
//	int day = t.tm_mday;
//	int month = t.tm_mon + 1;
//	int year = t.tm_year + 1904;
//	int dayOfWeek = t.tm_wday;
//	int dayOfYear = t.tm_yday;
//	int daylightSavingTime = t.tm_isdst;
//
//	//开始看日期
//	int iiii = 0;
//	iiii++;
}
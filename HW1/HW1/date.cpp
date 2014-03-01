// Author: Ilya Trofimov
// Group: 272(2)
// Date: 28 Jan 2014

#include "date.h";
#include <iomanip>

using namespace std;

date::date() : day(0), month(0), year(0) {}

date::date(int day, int month, int year) : day(day), month(month), year(year) {}

int date::compareTo(date another_date) {
	if (year != another_date.year) {
		return year - another_date.year;
	}

	if (month != another_date.month) {
		return month - another_date.month;
	}

	return day - another_date.day;
}

ostream &operator<< (ostream &stream, date d) {
	stream << setfill('0') << setw(2) << d.month << "/";
	stream << setfill('0') << setw(2) << d.day << "/";
	stream << setfill('0') << setw(4) << d.year;	
	return stream;
}
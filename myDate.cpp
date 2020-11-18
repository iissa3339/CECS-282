//Issa Issa
//CECS 282-07
//Prog 2 myDate
//03/04/2020
#include "myDate.h";
#include <iostream>;
#include <string>;
#include <stdlib.h>
int Greg2Julian(int month, int day, int year) {
	return ((day - 32075) + (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4);
}
//The & sign means pass by reference or nickname which means changing the values would change the original values
void Julian2Greg(int JD, int& month, int& day, int& year) {
	int l = JD + 68569;
	int n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	year = 4000 * (l + 1) / 1461001;
	l = l - 1461 * year / 4 + 31;
	month = 80 * l / 2447;
	day = l - 2447 * month / 80;
	l = month / 11;
	month = month + 2 - 12 * l;
	year = 100 * (n - 49) + year + l;
}
myDate::myDate(){
	month = 5;
	day = 11;
	year = 1959;
}
myDate::myDate(int M, int D, int Y) {
	int jd = Greg2Julian(M, D, Y);
	Julian2Greg(jd, month, day, year);
	if (M == month && D == day && Y == year) {
		month = M;
		day = D;
		year = Y;
	}
	else {
		month = 5;
		day = 11;
		year = 1959;
	}
}
void myDate::display() {
	std::string months[12] = {"January","February","March","April","May","June","July","August","Septemeber","October","November","December"};
	std::cout << months[getMonth() - 1] << " " << day << ", " << year;
}
void myDate::increaseDate(int N) {
	int g2j = Greg2Julian(month, day, year);
	g2j += N;
	Julian2Greg(g2j, month, day, year);
}
void myDate::decreaseDate(int N) {
	int g2j = Greg2Julian(month, day, year);
	g2j -= N;
	Julian2Greg(g2j, month, day, year);
}
int myDate::daysBetween(myDate D) {
	int mm = D.getMonth();
	int dd = D.getDay();
	int yy = D.getYear();
	int passedin = Greg2Julian(mm, dd, yy);
	int current = Greg2Julian(month, day, year);
	return passedin - current;
}
int myDate::getMonth() {
	return month;
}
int myDate::getDay() {
	return day;
}
int myDate::getYear() {
	return year;
}
int myDate::dayOfYear() {
	int fstday = Greg2Julian(1, 1, getYear());
	int curday = Greg2Julian(getMonth(), getDay(), getYear());
	return (curday - fstday + 1);
}
std::string myDate::dayName() {
	int yy = year % 100;
	int yearcode = (yy + (yy / 4)) % 7;
	int monthscode[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
	int monthcode = monthscode[getMonth() - 1];
	int centuries[4] = { 4,2,0,6 };
	int centurycode = 0;
	int century = getYear() / 100;
	if (getYear() >= 1700) {
		if ((century - 17) % 4 == 0) {
			centurycode = centuries[0];
		}
		else if ((century - 18) % 4 == 0) {
			centurycode = centuries[1];
		}
		else if ((century - 19) % 4 == 0) {
			centurycode = centuries[2];
		}
		else if ((century - 20) % 4 == 0) {
			centurycode = centuries[3];
		}
	}
	else {
		centurycode = (18 - century) % 7;
	}
	int leapyear = 0;
	if (getMonth() == 1 || getMonth() == 2) {
		if (getYear() % 400 == 0 || (getYear() % 4 == 0 && getYear() % 100 != 0)) {
			leapyear = 1;
		}
	}
	int dayy = (yearcode + monthcode + centurycode + getDay() - leapyear) % 7;
	std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return days[dayy];
}

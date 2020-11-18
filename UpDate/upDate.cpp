//Issa Issa
//CECS 282-07
//Prog 4 upDate
//04/20/2020
#include "upDate.h";
#include <iostream>;
using namespace std;
int upDate::count = 0;
int Greg2Julian(int month, int day, int year) {
	return ((day - 32075) + (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4);
}
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
upDate::upDate() {
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count++;
}
upDate::upDate(int Mo, int Da, int Ye) {
	dptr = new int[3];
	int month, day, year;
	int jd = Greg2Julian(Mo, Da, Ye);
	Julian2Greg(jd, month, day, year);
	if (Mo == month && Da == day && Ye == year) {
		dptr[0] = Mo;
		dptr[1] = Da;
		dptr[2] = Ye;
	}
	else {
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
	count++;
}
upDate::upDate(const upDate &ptr) {
	dptr = new int[3];
	dptr[0] = ptr.dptr[0];
	dptr[1] = ptr.dptr[1];
	dptr[2] = ptr.dptr[2];
	count++;	
}
upDate::upDate(int J) {
	dptr = new int[3];
	Julian2Greg(J, dptr[0], dptr[1], dptr[2]);
	count++;
}
upDate::~upDate() {
	delete [] dptr;
	count--;
}
void upDate::setDate(int Mo, int Da, int Ye) {
	int month, day, year;
	int jd = Greg2Julian(Mo, Da, Ye);
	Julian2Greg(jd, month, day, year);
	dptr = new int[3];
	if (Mo == month && Da == day && Ye == year) {
		dptr[0] = Mo;
		dptr[1] = Da;
		dptr[2] = Ye;
	}
	else {
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}
int upDate::getMonth() {
	return dptr[0];
}
int upDate::getDay() {
	return dptr[1];
}
int upDate::getYear() {
	return dptr[2];
}
string upDate::getMonthName() {
	string months[12] = { "January","February","March","April","May","June","July","August","Septemeber","October","November","December" };
	return months[dptr[0] - 1];
}
upDate upDate::operator=(upDate D) {
	dptr[0] = D.dptr[0];
	dptr[1] = D.dptr[1];
	dptr[2] = D.dptr[2];
	return *this;
}
upDate upDate::operator+=(int n) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD += n;
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	return upDate(m1, d1, y1);
}
upDate upDate::operator-=(int n) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD -= n;
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	return upDate(m1, d1, y1);
}
upDate upDate::operator+(int n) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD += n;
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	return upDate(m1, d1, y1);
}
upDate operator+(int n, upDate &D) {
	upDate x = upDate(D);
	int JDx = Greg2Julian(x.getMonth(), x.getDay(), x.getYear());
	JDx += n;
	int m1, d1, y1;
	Julian2Greg(JDx, m1, d1, y1);
	return upDate(m1, d1, y1);
}
upDate upDate::operator-(int n) {
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	JD = JD - n;
	int m1, d1, y1;
	Julian2Greg(JD, m1, d1, y1);
	return upDate(m1, d1, y1);
}
int upDate::operator-(upDate x) {
	int JD1 = Greg2Julian(getMonth(), getDay(), getYear());
	int JD2 = Greg2Julian(x.getMonth(), x.getDay(), x.getYear());
	return JD1 - JD2;
}
ostream& operator<<(ostream& out, const upDate& D) {
	upDate temp(D);
	out << temp.getMonth() << '/' << temp.getDay() << '/' << temp.getYear();
	return out;
}
int upDate::GetDateCount() {
	return count;
}
upDate upDate::operator++(int n) {
	int temp = Greg2Julian(dptr[0],dptr[1],dptr[2]);
	temp ++;
	Julian2Greg(temp, dptr[0], dptr[1], dptr[2]);
	return *this;
}
upDate upDate::operator++() {
	int temp = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	temp++;
	Julian2Greg(temp, dptr[0], dptr[1], dptr[2]);
	return *this;
}
upDate upDate::operator--(int n) {
	int temp = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	temp--;
	Julian2Greg(temp, dptr[0], dptr[1], dptr[2]);
	return *this;
}
upDate upDate::operator--() {
	int temp = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	temp--;
	Julian2Greg(temp, dptr[0], dptr[1], dptr[2]);
	return *this;
}
int upDate::julian() {
	return Greg2Julian(dptr[0], dptr[1], dptr[2]);
}
bool upDate::operator==(upDate D) {
	if (D.dptr == NULL) {
		return false;
	}
	else if (dptr[0] == D.getMonth() && dptr[1] == D.getDay() && dptr[2] == D.getYear()) {
		return true;
	}
	return false;
}
bool upDate::operator<(upDate D) {
	if (D.dptr == NULL) {
		return false;
	}
	else if (dptr[2] < D.getYear() || dptr[0] < D.getMonth() || dptr[1] < D.getDay()) {
		return true;
	}
	return false;
}
bool upDate::operator>(upDate D) {
	if (D.dptr == NULL) {
		return true;
	}
	else if (dptr[2] > D.getYear() || dptr[0] > D.getMonth() || dptr[1] > D.getDay()) {
		return true;
	}
	return false;
}
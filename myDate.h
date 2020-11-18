//Issa Issa
//CECS 282-07
//Prog 2 myDate
//03/04/2020
#ifndef _myDate_h_
#define _myDate_h_
#include <string>;
class myDate {
	private:
		int month;
		int day;
		int year;
	public:
		myDate();
		myDate(int M, int D, int Y);
		void display();
		void increaseDate(int N);
		void decreaseDate(int N);
		int daysBetween(myDate D);
		int getMonth();
		int getDay();
		int getYear();
		int dayOfYear();
		std::string dayName();
		int getJulian();
		myDate getRandom(myDate first, myDate second);
};
#endif
//Issa Issa
//CECS 282-07
//Prog 4 upDate
//04/20/2020
#ifndef _upDate_h_
#define _upDate_h_
#include <string>;
class upDate {
	private:
		int* dptr;
		static int count;
	public:
		upDate();
		upDate(int Mo, int Da, int Ye);
		upDate(const upDate& ptr);
		upDate(int J);
		~upDate();
		void setDate(int Mo, int Da, int Ye);
		int getMonth();
		int getDay();
		int getYear();
		std::string getMonthName();
		upDate operator=(upDate D);
		upDate operator+=(int n);
		upDate operator-=(int n);
		upDate operator+(int n);
		friend upDate operator+(int n, upDate &D);
		upDate operator-(int n);
		int operator-(upDate x);
		friend std::ostream& operator<<(std::ostream& out, const upDate& D);
		static int GetDateCount();
		upDate operator++(int n);
		upDate operator++();
		upDate operator--(int n);
		upDate operator--();
		int julian();
		bool operator==(upDate D);
		bool operator<(upDate D);
		bool operator>(upDate D);	
};
#endif
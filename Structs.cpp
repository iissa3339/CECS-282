//Issa Issa
//CECS 282-07
//Prog 2 myDate
//03/04/2020
#include "myDate.h";
#include <string>;
#include <iostream>;
#include <iomanip>;
#include <cstring>;
using namespace std;

struct student {
	char name[30];
	int id;
	char grade;
	myDate bday;
	string town;
};
void populate(student* arrayS[10]){
	const char* names[]= { "Amy Wang","Sam Gonzales","Samantha Jimenez", "Jake Ortiz", "George Hernandez","Steve Goal","Issa Issa","Annette Phong","Amed Ngo","Maria Gato" };
	int ids[] = { 1002,2005,1999,2004,2010,9012,2783,9843,9283,2393 };
	char grades[] = { 'A','C','D','A','B','F','A','B','C','D' };
	string towns[] = { "Fontana","Bakersfield","Lake Tahoe","Encino","Dana Point","Mission Viejo","Lake Elsinore","San Clemente","Riverside","Irvine" };
	for (int i = 0; i < 10; i++) {
		arrayS[i] = new student;
		strcpy_s(arrayS[i]-> name, names[i]);
		arrayS[i] -> id = ids[i];
		arrayS[i]-> grade = grades[i];
		myDate temp;
		arrayS[i]-> bday = temp.getRandom(myDate(1,1,1999), myDate(12,31,2004));
		arrayS[i]-> town = towns[i];
	}
}
void display(student* arrayS[10]) {
	const char * months[] = { "January","February","March","April","May","June","July","August","Septemeber","October","November","December" };
	cout << "Name" << setw(25) << "Student ID" << setw(15) << "Grade" << setw(15) << "Birthday" << setw(20) << "Home Town" << "\n";
	for (int i = 0; i < 10; i++) {
		// This x is going to be the space for justifying left for the ID
		int x = (19 - strlen((*arrayS[i]).name)) + to_string((*arrayS[i]).id).length();
		// This y is going to be the space for justifying left for the hometown
		int y = 16 - strlen(months[(*arrayS[i]).bday.getMonth()-1]) - to_string((*arrayS[i]).bday.getDay()).length() - to_string((*arrayS[i]).bday.getYear()).length() + (*arrayS[i]).town.length();
		cout << (*arrayS[i]).name << setw(x) << (*arrayS[i]).id << setw(21 - to_string((*arrayS[i]).id).length()) << (*arrayS[i]).grade << "\t   ";
		(*arrayS[i]).bday.display();
		cout << setw(y) << (*arrayS[i]).town << "\n";
	}
}
void sortName(student* arrayS[10],int left, int right) {
	int i = left;
	int j = right;
	student* mid = arrayS[(left + right) / 2];
	while (i <= j) {
		while (strcmp(arrayS[i]->name,mid->name) < 0)
			i++;
		while (strcmp(arrayS[j]->name, mid->name) > 0)
			j--;
		if (i <= j) {
			swap(arrayS[i], arrayS[j]);
			i++; j--;
		}
	};
	if (left < j)
		sortName(arrayS, left, j);
	if (i < right)
		sortName(arrayS, i, right);
}
void sortID(student* arrayS[10], int left, int right) {
	int i = left;
	int j = right;
	student* mid = arrayS[(left + right) / 2];
	while (i <= j) {
		while (arrayS[i]->id < mid->id)
			i++;
		while (arrayS[j]->id > mid->id)
			j--;
		if (i <= j) {
			swap(arrayS[i], arrayS[j]);
			i++; j--;
		}
	}
	if (left < j)
		sortID(arrayS, left, j);
	if (i < right)
		sortID(arrayS, i, right);
}
void sortGrade(student* arrayS[10], int left, int right) {
	int i = left;
	int j = right;
	student* mid = arrayS[(left + right) / 2];
	while (i <= j) {
		while (arrayS[i]->grade < mid->grade)
			i++;
		while (arrayS[j]->grade > mid->grade)
			j--;
		if (i <= j) {
			swap(arrayS[i], arrayS[j]);
			i++; j--;
		}
	};
	if (left < j)
		sortGrade(arrayS, left, j);
	if (i < right)
		sortGrade(arrayS, i, right);
}
void sortBday(student* arrayS[10], int left, int right) {
	int i = left;
	int j = right;
	student* mid = arrayS[(left + right) / 2];
	while (i <= j) {
		while (arrayS[i]->bday.getJulian() < mid->bday.getJulian())
			i++;
		while (arrayS[j]->bday.getJulian() > mid->bday.getJulian())
			j--;
		if (i <= j) {
			swap(arrayS[i], arrayS[j]);
			i++; j--;
		}
	};
	if (left < j)
		sortBday(arrayS, left, j);
	if (i < right)
		sortBday(arrayS, i, right);
}
void sortTown(student* arrayS[10], int left, int right) {
	int i = left;
	int j = right;
	student* mid = arrayS[(left + right) / 2];
	while (i <= j) {
		while ((arrayS[i]->town.compare(mid->town)) < 0)
			i++;
		while ((arrayS[j]->town.compare(mid->town)) > 0)
			j--;
		if (i <= j) {
			swap(arrayS[i], arrayS[j]);
			i++; j--;
		}
	};
	if (left < j)
		sortTown(arrayS, left, j);
	if (i < right)
		sortTown(arrayS, i, right);
}
int main() {
	student* Students[10];
	populate(Students);
	cout << "1) Display list sorted by Name\n2) Display list sorted by Student ID\n3) Display list sorted by Grade\n";
	cout << "4) Display list sorted by Birthday\n5) Display list sorted by Home Town\n6) Exit\n";
	int choice;
	cout << "Please choose a number from the menu: ";
	cin >> choice;
	while (choice != 6) {
		if (choice == 1) {
			sortName(Students,0,9);
			display(Students);
		}
		else if (choice == 2) {
			sortID(Students,0,9);
			display(Students);
		}
		else if (choice == 3) {
			sortGrade(Students,0,9);
			display(Students);
		}
		else if (choice == 4) {
			sortBday(Students,0,9);
			display(Students);
		}
		else if (choice == 5) {
			sortTown(Students,0,9);
			display(Students);
		}
		else {
			break;
		}
		cout << "1) Display list sorted by Name\n2) Display list sorted by Student ID\n3) Display list sorted by Grade\n";
		cout << "4) Display list sorted by Birthday\n5) Display list sorted by Home Town\n6) Exit\n";
		cout << "Please choose a number from the menu: ";
		cin >> choice;
	}
	return 0;
}


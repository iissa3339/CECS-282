// Issa Issa
//CECS 282-07
//Prog 5 BigInt
//05/06/2020
#include<iostream>;
#include <vector>;
#include<map>;
#include<string>;
#include <sstream>;
#include <stdlib.h>;
#include <algorithm>;
using namespace std;
class BigInt {
	public:
		BigInt();
		BigInt(int x);
		BigInt(string x);
		void print();
		BigInt operator+(BigInt x);
		BigInt operator-(BigInt x);
		bool operator<(const BigInt& x)const;
		bool operator==(BigInt& x);
		bool operator<=(int x);
		BigInt operator++(int x);
		friend ostream& operator<<(ostream& out, const BigInt& D);
	private:
		vector <char> ourVector;
};
BigInt goldRabbits(BigInt); 
void pause() { cout << "\nPress Enter to continue..."; getchar(); }
int main() {
	BigInt B1("123456789123456789123456789123456789"); 
	BigInt B2(B1); 
	BigInt MAX(INT_MAX); 
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl; 
	pause(); 
	cout << "\nB1:"; 
	B1.print(); 
	cout << endl; 
	pause();
	for(BigInt i=0; i<=3000; i++){
		cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
	}
	pause();
	cout<< "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 =  goldRabbits(BigInt(3000));
	gR3000.print();
	pause();
}
BigInt::BigInt() {

}
BigInt::BigInt(int x) {
	vector<char> temp;
	while (x > 9)
	{
		temp.push_back(x % 10);
		x /= 10;
	}
	ourVector.push_back(x);
	vector<char>::reverse_iterator rit;
	for (rit = temp.rbegin(); rit != temp.rend(); rit++) {
		ourVector.push_back(*rit);
	}
}
BigInt::BigInt(string x) {
	string::iterator it;
	for (it = x.begin(); it != x.end(); it++) {
		ourVector.push_back(*it - '0');
	}
}
void BigInt::print() {
	vector<char>::iterator it;
	for (it = ourVector.begin(); it != ourVector.end(); it++) {
		cout << (int)*it;
	}
}
BigInt BigInt::operator+(BigInt x) {
	// Find the shorter length one
	BigInt shorter;
	BigInt longer;
	if (ourVector.size() > x.ourVector.size()) {
		shorter = x;
		longer = *this;
	}
	else if (x.ourVector.size() > ourVector.size()) {
		shorter = *this;
		longer = x;
	}
	// Same length
	else {
		shorter = x;
		longer = *this;
	}
	string concatenated = "";
	for (int i = 0; i < shorter.ourVector.size(); i++) {
		int result = ((int)shorter.ourVector[shorter.ourVector.size() - 1 - i] + (int)longer.ourVector[longer.ourVector.size() - 1 - i]);
		if (result > 9 && i < longer.ourVector.size()-1) {
			concatenated += to_string(result)[1];
			longer.ourVector[longer.ourVector.size() - 2 - i] += 1;
		}
		else {
			string resultt = to_string(result);
			for (int g = resultt.length()-1; g >= 0; g--) {
				concatenated += resultt[g];
			}
		}
	}
	if (ourVector.size() != x.ourVector.size()) {
		for (int m = longer.ourVector.size() - shorter.ourVector.size(); m > 0 ; m--) {
			concatenated += (int)longer.ourVector[m-1] + '0';
		}
	}
	reverse(concatenated.begin(), concatenated.end());
	return BigInt(concatenated);
}
BigInt BigInt::operator-(BigInt x) {
	if (ourVector == x.ourVector) {
		return BigInt(0);
	}
	else {
		vector<char> temp_X;
		vector<char> temp_this;
		for (int z = ourVector.size() - x.ourVector.size(); z > 0; z--) {
			temp_X.push_back(0);
		}
		for (char s : x.ourVector) {
			temp_X.push_back(s);
		}
		for (char ss : ourVector) {
			temp_this.push_back(ss);
		}
		string concatenated = "";
		for (int i = temp_X.size() - 1; i >= 0; i--) {
			int result = (int)temp_this[i] - (int)temp_X[i];
			if (result < 0) {
				result = ((int) temp_this[i] + 10) - (int) temp_X[i];
				for (int z = i-1; z >= 0; z--) {
					if ((int)temp_this[z] > 0) {
						temp_this[z] -= 1;
						break;
					}
					else {
						temp_this[z] += 9;
					}
				}
			}
			concatenated += result + '0';
		}
		reverse(concatenated.begin(), concatenated.end());
		// Remove leading zeros from number
		concatenated.erase(0, min(concatenated.find_first_not_of('0'), concatenated.size() - 1));
		return BigInt(concatenated);
	}
}
bool BigInt::operator<(const BigInt& x) const {
	if (ourVector.size() < x.ourVector.size()) {
		return true;
	}
	else if (ourVector.size() == x.ourVector.size()) {
		for (int i = ourVector.size() - 1; i > -1; i--) {
			if (x.ourVector[i] < ourVector[i]) {
				return false;
			}
			else if (ourVector[i] < x.ourVector[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
		
}
bool BigInt::operator==(BigInt& x){
	if (ourVector == x.ourVector) {
		return true;
	}
	return false;
}
bool BigInt::operator<=(const int x) {
	BigInt temp(x);
	if (ourVector.size() < temp.ourVector.size()) {
		return true;
	}
	else if (temp.ourVector.size() < ourVector.size()) {
		return false;
	}
	if (ourVector.size() == temp.ourVector.size()) {
		if (ourVector[0] < temp.ourVector[0]) {
			return true;
		}
		else if (temp.ourVector[0] < ourVector[0]) {
			return false;
		}
		else if (ourVector == temp.ourVector) {
			return true;
		}
		return false;
	}
}
BigInt BigInt::operator++(int x) {
	int lastIndex = ourVector.size() - 1;
	int result = (int)ourVector[ourVector.size() - 1] + 1;
	if (result < 10) {
		ourVector[ourVector.size() - 1] = (int)ourVector[lastIndex] + 1;
	}
	else {
		if (lastIndex - 1 < 0) {
			string concatenated = "1";
			for (int nb = 0; nb < ourVector.size(); nb++) {
				concatenated += "0";
			}
			BigInt tempo(concatenated);
			ourVector.clear();
			for (char g : tempo.ourVector) {
				ourVector.push_back(g);
			}
		}
		// Look at digits left of that one above
		for (int xx = lastIndex-1; xx >= 0; xx--) {
			// Find the digit on left of it that doesn't give you a 10 when added to a 1
			// Make the stuff on right of it zero and add one to it
			if ((int)ourVector[xx] + 1 < 10) {
				for (int z = lastIndex; z > xx; z--) {
					ourVector[z] -= ourVector[z];
				}
				ourVector[xx] = (int)ourVector[xx] + 1;
				break;
			}
			// It's the left most digit and it adds up to more than 10 so make space for another digit
			else if (xx == 0 && ((int)ourVector[xx] + 1 >= 10)) {
				string concatenated = "1";
				for (int nb = 0; nb < ourVector.size(); nb++) {
					concatenated += "0";
				}
				BigInt tempo(concatenated);
				ourVector.clear();
				for (char g : tempo.ourVector) {
					ourVector.push_back(g);
				}
			}
		}
	}
	return *this;
}
ostream& operator<<(ostream& out, const BigInt& B) {
	if (B.ourVector.size() > 12) {
		out << (int)B.ourVector[0] << '.';
		for (int i = 1; i < 11; i++) {
			out << (int)B.ourVector[i];
		}
		out << 'e' << B.ourVector.size();
	}
	else {
		for (char x : B.ourVector) {
			out << (int)x;
		}
	}
	return out;
}
BigInt goldRabbits(BigInt n) {
	static map<BigInt, BigInt> rabbitsMap;
	if (n <= 1) {
		rabbitsMap[n] = BigInt(1);
	}
	else if (rabbitsMap.find(n - BigInt(1)) != rabbitsMap.end() && rabbitsMap.find(n - BigInt(2)) != rabbitsMap.end()) {
		rabbitsMap[n] = rabbitsMap[n - BigInt(1)] + rabbitsMap[n - BigInt(2)];
	}
	else {
		rabbitsMap[n] = goldRabbits(n - BigInt(1)) + goldRabbits(n - BigInt(2));
	}
	return rabbitsMap[n];
}

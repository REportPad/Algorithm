//Counting Sundays
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

//#define FUNC

#ifdef FUNC
bool isPrime(int x);
int DivisorNumber(int x);
int BigNumberSum(string a, string b, char* c, int csize);
int ReadFile(string name, string* number);
#endif


//1901~2000
int main() {
	//1900.1.1 mon, common year
	//1901.1.1 ?

	//find leap year
	vi leapYear;
	for (int y = 1901; y <= 2000; ++y) {
		if (y % 4 == 0) {
			if (y % 400 == 0) {
				//cout << y << ": leap year" << endl;
				leapYear.push_back(y);
			}
			else if (y % 100 == 0) {
				continue;
			}
			else {
				//cout << y << ": leap year" << endl;
				leapYear.push_back(y);
			}
		}
	}

	//find first sunday
	int thirtyOneMonth[] = { 1,3,5,7,8,10,12 };
	int thirtyMonth[] = { 4,6,9,11 };
	int day = 6; 	//1901.1.6 sun
	int iLeapYear = 0, i30 = 0, i31 = 0;
	int cnt = 0;

	for (int y = 1901; y <= 2000; ++y) {
		for (int month = 1; month <= 12; ++month) {
			if (month == thirtyOneMonth[i31]) {
				while (day <= 31) {
					day += 7;
				}
				day -= 31;
				
				//
				i31 = (i31 + 1) % 7;
			}
			else if (month == thirtyMonth[i30]) {
				while (day <= 30) {
					day += 7;
				}
				day -= 30;
				//
				i30 = (i30 + 1) % 4;
			}
			else {//february
				if (y == leapYear[iLeapYear]) {//day 29
					while (day <= 29) {
						day += 7;
					}
					day -= 29;
					//
					++iLeapYear;
				}
				else {//day 28
					while (day <= 28) {
						day += 7;
					}
					day -= 28;
				}
			}

			if (day == 1) {
				++cnt;
				//cout << y << "." << month+1 << "." << day << ": " << cnt << endl;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}

#ifdef FUNC
int ReadFile(string name, string* number) {
	string line;
	ifstream file(name);

	int i = 0;

	if (file.is_open()) {
		while (getline(file, line)) {
			number[i] = line;
			//cout << number[i] << endl;
			++i;
		}
		//cout << endl;

		file.close();
	}
	else {
		cout << "Unable to open file";
	}

	return i;
}



bool isPrime(int x) {
	if (x == 2 || x == 3) return true;

	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int DivisorNumber(int x) {
	if (x == 1) return 1;
	if (isPrime(x)) return 2;

	int ret = 2;//1, x
	int n = 2;
	int t = sqrt(x);

	while (t >= n) {
		if (x % n == 0) {
			if (x / n == n) {
				++ret;
				break;
			}
			else {
				ret += 2;
				++n;
			}
		}
		else ++n;
	}

	return ret;
}

int BigNumberSum(string a, string b, char* c, int csize) {
	int SIZE = min(a.size(), b.size());
	int carry = 0;
	int cnt = 0;

	for (int i = 0; i < SIZE; ++i) {
		int x = a[(SIZE - 1) - i] - '0';
		int y = b[(SIZE - 1) - i] - '0';
		int z = x + y;

		if (z + carry < 10) {
			c[(csize - 1) - i] = (z + carry + '0');
			carry = 0;
		}
		else {
			c[(csize - 1) - i] = (z + carry - 10 + '0');
			carry = 1;
		}
		++cnt;
	}

	if (carry) {
		c[(csize - 1) - cnt] = '1';
		++cnt;
	}

	return cnt;
}
#endif

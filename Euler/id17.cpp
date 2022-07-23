//Number letter counts
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

bool isPrime(int x);
int DivisorNumber(int x);
void ReadFile(string name, string* number);
int BigNumberSum(string a, string b, char* c, int csize);


int main() {
	string word0[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string word1[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	string word2[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string hundred = "hundred";
	ull sum = 0;
	
	//1~9
	int SIZE0 = sizeof(word0) / sizeof(string);
	for (int i = 0; i < SIZE0; ++i) {
		sum += word0[i].size();
	}

	//10~19
	int SIZE1 = sizeof(word1) / sizeof(string);
	for (int i = 0; i < SIZE1; ++i) {
		sum += word1[i].size();
	}

	//20~99
	int SIZE2 = sizeof(word2) / sizeof(string);
	int cnt = 0;
	for (int i = 0; i < SIZE2; ++i) {
		string w2 = word2[i];
		if (cnt%10 == 0) {
			string t = w2;
			sum += (t.size());
		}
		++cnt;

		if(cnt%10 != 0) {
			for (int j = 0; j < SIZE0; ++j) {
				string w0 = word0[j];
				string t = w2 + w0;
				sum += (t.size());
				++cnt;
			}
		}

	}
	cout << "1~99: " << sum << endl << endl;

	
	//100~999
	int cnt100 = 100;
	for (int i = 0; i < 9; ++i) {
		string t = word0[i] + hundred;

		if (cnt100 % 100 == 0) {//100, 200, ... 900
			sum += t.size();
			cout << cnt100 << ": " << t << " " << sum << endl;
			++cnt100;
		}
		
		if(cnt100 % 100 != 0) {
			t += "and";

			//1~9
			for (int i = 0; i < SIZE0; ++i) {
				string w = t + word0[i];
				sum += w.size();
				cout << cnt100 << ": " << w << " " << sum << endl;
				++cnt100;

			}
			cout << endl;

			//10~19
			for (int i = 0; i < SIZE1; ++i) {
				string w = t + word1[i];
				sum += w.size();
				cout << cnt100 << ": " << w << " " << sum << endl;
				++cnt100;
			}
			cout << endl;

			//20~99
			cnt = 0;
			for (int i = 0; i < SIZE2; ++i) {
				string w2 = word2[i];

				if (cnt % 10 == 0) {//0
					string w = t + w2;
					sum += w.size();
					cout << cnt100 << ": " << w << " " << sum << endl;
					++cnt;
					++cnt100;
				}

				if(cnt%10 != 0) {
					for (int j = 0; j < SIZE0; ++j) {
						string w0 = word0[j];
						string w = t + w2 + w0;
						sum += w.size();
						cout << cnt100 << ": " << w << " " << sum << endl;
						++cnt;
						++cnt100;
					}
				}
				cout << endl;
			}
			//
		}

		cout << "cnt100: " << cnt100  << endl << endl;
	}
	cout << "1~999: " << sum << endl;

	//1000
	string thousand = "onethousand";
	sum += thousand.size();

	cout << "1~1000: " << sum << endl;
	
	return 0;
}


void ReadFile(string name, string* number) {
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

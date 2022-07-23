//Maximum path sum I
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

//#define OFF

#ifdef OFF
bool isPrime(int x);
int DivisorNumber(int x);
int BigNumberSum(string a, string b, char* c, int csize);
#endif

int ReadFile(string name, string* number);

#define ROW 15
#define COL 15

int main() {
	//read text
	string name = "p18.txt";
	string number[ROW];
	const int row = ReadFile(name, number);
	//cout << "row: " << row << endl;

	//string to int
	int num[ROW][COL];
	int k = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < (i+1)*3; ++j) {
			if (number[i][j] == ' ') {
				num[i][k] = (number[i][j - 2] - '0') * 10 + (number[i][j - 1] - '0');
				//cout << num[i][k] << ' ';
				++k;
			}
		}
		//cout << endl;
		k = 0;
	}

	//find maximum path
	ull maxPath[ROW][COL] = {0,};//1 2 3 
	maxPath[0][0] = num[0][0];
	//cout << maxPath[0][0] << endl;

	for (int i = 1; i < row; ++i) {
		for (int j = 0; j < (i + 1); ++j) {
			if (j == 0) {
				maxPath[i][j] = maxPath[i - 1][j] + num[i][j];
			}
			else if (j == i) {
				maxPath[i][j] = maxPath[i - 1][j - 1] + num[i][j];
			}
			else {
				maxPath[i][j] = max(maxPath[i - 1][j-1] + num[i][j], maxPath[i - 1][j] + num[i][j]);
			}
			//cout << maxPath[i][j] << ' ';
		}
		//cout << endl;
	}

	//find maximum value
	ull bestNum = 0;
	for (int j = 0; j < COL; ++j) {
		bestNum = max( bestNum, maxPath[ROW-1][j] );
	}
	cout << bestNum << endl;


	return 0;
}


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


#ifdef OFF
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

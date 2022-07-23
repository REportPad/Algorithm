//Large sum
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

#define N 100
#define M 50
#define SUM_SIZE 100

int main() {
	string number[N];
	string fileName = "p13.txt";

	ReadFile(fileName, number);
	
	char ans[SUM_SIZE] = {0,};
	char buff[SUM_SIZE] = { 0, };
	char t;
	int SIZE = SUM_SIZE - 1;
	int carry = 0;

	for (int j = 0; j < M; ++j) {
		buff[SIZE - j] = number[0][M-1-j];
	}
	
	for (int i = 1; i < N; ++i) {
		carry = 0;
		SIZE = SUM_SIZE - 1;
		cout << "i: " << i << endl;

		for (int j = 0; j < M; ++j) {
			int x = buff[SIZE] - '0';
			int y = number[i][(M - 1) - j] - '0';
			int z = x + y;

			if (z + carry < 10) {
				t = (z + carry) + '0';
				ans[SIZE] = t;
				carry = 0;
			}
			else {//z+carry >= 10
				t = (z + carry - 10) + '0';
				ans[SIZE] = t;
				carry = 1;
			}
			--SIZE;
		}

		//first digit calculation
		while (carry > 0) {
			if (buff[SIZE] >= '1' && buff[SIZE] <= '9') {
			}
			else {
				buff[SIZE] = '0';
			}

			int u = buff[SIZE] - '0';
			if (u + carry < 10) {
				ans[SIZE] = u + carry + '0';
				carry = 0;
			}
			else {//u + carry >= 10
				ans[SIZE] = (u + carry - 10) + '0';
				carry = 1;
			}
			--SIZE;
		}

		cout << "ans: " << endl;
		for (int q = 0; q < SUM_SIZE; ++q) {
			cout << ans[q];
			buff[q] = ans[q];
		}
		cout << endl;

		cout << "buff: " << endl;
		for (int q = 0; q < SUM_SIZE; ++q) {
			cout << buff[q];
		}
		cout << endl;
	}

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

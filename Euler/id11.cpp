//	Largest product in a grid
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

bool isPrime(int x);
int DivisorNumber(int x);
void ReadFile(string name, string* number);

#define N 20
#define ROW 20
#define COL (20*3)
#define ADJ_NUM 4

int main() {
	string number[N];
	string fileName = "p11.txt";

	ReadFile(fileName, number);
	
	ull mat[N][N];

	//make number matrix
	for (int i = 0; i < ROW; ++i) {
		int k = 0;

		for (int j = 0; j < COL; ++j) {
			if (number[i][j] == ' ') {
				ull t = (number[i][j - 2] - '0') * 10 + (number[i][j - 1] - '0');
				mat[i][k] = t;
				++k;
			}
		}
	}

	//diagonal -> 1788696
	//down
	ull maxNumber = 1788696;
	ull t = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - ADJ_NUM; ++j) {
			for (int k = 0; k < ADJ_NUM; ++k) {
				t *= mat[j+k][i];
			}
			maxNumber = max(maxNumber, t);
			t = 1;
		}
	}

	//right
	t = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - ADJ_NUM; ++j) {
			for (int k = 0; k < ADJ_NUM; ++k) {
				t *= mat[i][j + k];
			}
			maxNumber = max(maxNumber, t);
			t = 1;
		}
	}
	
	//reverse diagonal
	t = 1;
	for (int i = 0; i < N - ADJ_NUM; ++i) {
		for (int j = 3; j < N; ++j) {
			for (int k = 0; k < ADJ_NUM; ++k) {
				t *= mat[i + k][j - k];
			}
			maxNumber = max(maxNumber, t);
			t = 1;
		}
	}

	cout << maxNumber << endl;

	return 0;
}


void ReadFile(string name, string* number) {
	string line;
	ifstream file(name);

	int i = 0;

	if (file.is_open()) {
		while (getline(file, line)) {
			number[i] = line;
			++i;
		}
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

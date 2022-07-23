//Power digit sum
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

#define LEN 303

bool isPrime(int x);
int DivisorNumber(int x);
void ReadFile(string name, string* number);
int BigNumberSum(string a, string b, char* c, int csize);


int main() {
	string a = "2";
	char c[LEN] = {0,};
	ull ans = 0;
	int cnt;

	for (int i = 2; i <= 1000; ++i) {
		cnt = BigNumberSum(a,a,c, LEN);

		a = "";
		ans = 0;
		for (int j = 0; j < cnt; ++j) {
			ans += (c[(LEN - 1) - j] - '0');
			a += c[((LEN - 1) - (cnt-1)) + j];
		}
		//cout << cnt << " " << ans << " " << a << endl;
	}

	cout << ans << endl;

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

//Longest Collatz sequence
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

int main() {
	int N = 1000000;
	ull t = 2;
	int cnt = 1;
	int longestCnt = 0;

	while (t <= N) {
		ull x = t;

		while (x > 1) {
			if (x % 2 == 0) {
				x /= 2;
				++cnt;
			}
			else {
				x = 3 * x + 1;
				++cnt;
			}
		}

		if (cnt > longestCnt) {
			longestCnt = cnt;
			cout << t << " " << longestCnt << endl;
		}
		++t;
		cnt = 1;
	}

	return 0;
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

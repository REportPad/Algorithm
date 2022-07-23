//Highly divisible triangular number
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

#define NUM 500

bool isPrime(int x);
int DivisorNumber(int x);



int main() {
	int tri = 1;
	int x;
	int n = 2;

	while (1) {
		x = DivisorNumber(tri);
		//cout << tri << " " << x << endl;

		if (x > 500) {
			cout << tri << endl;
			break;
		}

		tri += n;
		++n;
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

//Summation of primes
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

#define NUM 2000000

bool isPrime(int x) {
	if (x == 2 || x == 3) return true;

	for (int i = 2;i*i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ull sum = 0;

	for (int i = 2; i < NUM; ++i) {
		if (isPrime(i)) {
			sum += i;
		}
	}

	cout << sum << endl;

	return 0;
}

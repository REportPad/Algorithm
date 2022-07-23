//Largest prime factor

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define PRIME_NUM 600851475143

int main() {
	ull i = 2;
	ull p = PRIME_NUM;

	while (p > 0) {
		if (p%i == 0) {
			p /= i;
			cout << i << " " << p << endl;
		}
		else {
			++i;
		}
	}

	return 0;
}

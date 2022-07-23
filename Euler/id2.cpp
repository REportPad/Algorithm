//Even Fibonacci numbers

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX_NUM 4000000

int main() {
	ull sum = 0;
	ull fib[3] = {1, 2, 0};
	sum = fib[1];

	while (fib[2] < MAX_NUM) {
		fib[2] = fib[0] + fib[1];

		if (fib[2]%2 == 0 && fib[2] < MAX_NUM) {
			sum += fib[2];
		}

		fib[0] = fib[1];
		fib[1] = fib[2];
	}

	cout << sum << endl;

	return 0;
}

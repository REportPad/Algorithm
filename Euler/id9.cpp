//Special Pythagorean triplet
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;


int main() {
	int a, b;
	bool flg = false;

	for (a = 1; a <= 1000; ++a) {
		flg = false;

		for (b = a + 1; b <= 1000; ++b) {
			int y = (a - 1000) * (b - 1000);
			if (y == 5 * pow(10, 5)) {
				flg = true;
				break;
			}
		}
		if (flg) break;
	}

	int c = 1000 - (a + b);
	cout << a << " " << b << " " << c << endl;
	cout << a * b * c << endl;

	return 0;
}

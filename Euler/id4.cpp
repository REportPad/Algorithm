//Largest palindrome product

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

int main() {
	bool flg = true;
	int y;

	for (int i = 999; i > 900; --i) {
		for (int j = 999; j > 900; --j) {
			flg = true;
			int x = i * j;
			y = x;
			vi v;

			while (x > 0) {
				v.push_back(x % 10);
				x /= 10;
			}
			
			for (int k = 0; k < v.size()/2; ++k) {
				if (v[k] != v[v.size() - k - 1]) {
					flg = false;
					break;
				}
			}

			if (flg) {
				cout << i << " " << j << " " << y << endl;
				break;
			}
		}

		if (flg) {
			cout << y << endl;
			break;
		}
	}

	return 0;
}

//Number spiral diagonals
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include<map>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

//#define FUNC

#ifdef FUNC
int DivisorNumber(int x);
int ReadFile(string name, string* number);
int BigNumberSum(string a, string b, char* c, int digit);
ull FactorialDigitCount(int n);
bool isAmicable(int n);
bool isPrime(int x);
#endif

#define N 500

int main(){
	ull a = 0;
	ull b = 0;
	ull c = 0;
	ull d = 0;

	for (int i = 1; i <= N; ++i) {
		a += (4*i*i -2*i + 1);
		b += (4 * i * i + 1);
		c += (4 * i * i + 2 * i + 1);
		d += (4 * i * i + 4 * i + 1);
	}

	cout << a + b + c + d +1 << endl;



	return 0;
}


#ifdef FUNC
bool isPrime(int x) {
	if (x == 2 || x == 3) return true;

	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

bool isAmicable(int n) {
	if (n >= 1 && n <= 3) {
		return false;
	}

	int i = 2;
	ull sumA = 1;
	ull sumB = 1;

	while (i * i <= n) {
		if (n % i == 0) {
			sumA += i;
			if ((n / i) != i) {
				sumA += (n / i);
			}
		}
		++i;
	}

	i = 2;
	while (i * i <= sumA) {
		if (sumA % i == 0) {
			sumB += i;
			if ((sumA / i) != i) {
				sumB += (sumA / i);
			}

		}
		++i;
	}

	if (n == sumB && n != sumA) {
		return true;
	}

	return false;
}

int ReadFile(string name, string* number) {
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

	return i;
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


ull FactorialDigitCount(int n) {
	ull ret = 0;
	string s = "1";
	string t = "1";
	int x = 0;
	char c[N];

	//initialization
	for (int i = 0; i < N; ++i) {
		c[i] = '0';
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			x = BigNumberSum(s, t, c, N);
			//cout << "s: " << s << ", t: " << t << endl;
			for (int k = 0; k < N; ++k) {
				if (c[k] != '0') {
					s = c[k];
					for (int u = k + 1; u < N; ++u) {
						s += c[u];
					}
					//cout << "i: " << i << " " << s << endl;
					break;
				}
			}
		}

		cout << "i: " << i << ", " << s << endl;
		t = s;
	}

	for (int i = 0; i < N; ++i) {
		ret += (c[i] - '0');
		//cout  << i << ": " << ret << endl;
	}

	return ret;
}


int BigNumberSum(string a, string b, char* c, int digit) {
	if (b.size() > a.size()) {
		string d = a;
		a = b;
		b = d;
	}

	if (a.size() > b.size()) {
		string d = "";
		int m = a.size() - b.size();
		for (int i = 0; i < m; ++i) {
			d += '0';
		}
		d += b;
		b = d;
	}

	//a.size() == b.size()
	int SIZE = min(a.size(), b.size());//12+6=18?
	int carry = 0;
	int cnt = 0;

	for (int i = 0; i < SIZE; ++i) {
		int x = a[(SIZE - 1) - i] - '0';
		int y = b[(SIZE - 1) - i] - '0';
		int z = x + y;
		//cout << "z: " << z << endl;

		if (z + carry < 10) {
			c[(digit - 1) - i] = (z + carry + '0');
			carry = 0;
		}
		else {
			c[(digit - 1) - i] = (z + carry - 10 + '0');
			carry = 1;
		}
		++cnt;
	}

	if (carry) {
		c[(digit - 1) - cnt] = '1';
		++cnt;
	}

	return cnt;
}

#endif

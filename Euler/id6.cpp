//Sum square difference
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;


int main() {
	int n = 100;
	int y = (n * (n + 1) / 2) * (n * (n + 1) / 2) - (n * (n + 1) * (2*n + 1) / 6);
	cout << y << endl;
	return 0;
}

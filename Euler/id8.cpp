//Largest product in a series
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

int main() {
	string number = "";

	string line;
	ifstream file("p8.txt"); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open()) {
		while (getline(file, line)) {
			number += line;
		}
		file.close(); // 열었떤 파일을 닫는다. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}

	ull prod = 1;
	ull temp = 1;

    for (int i = 0; i < 1000-13; ++i) {
        for (int j = 0; j < 13; ++j) {
			ull t = (number[i + j] - '0');
			temp *= t;
        }

		if (temp > prod) prod = temp;
		temp = 1;
    }
                                          
	cout << prod << endl;

	return 0;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string t = s;
    sort(t.begin(), t.end(), greater<>());
    return t;
}

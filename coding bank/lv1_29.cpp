#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    string t = "";
    
    if(n%2 == 0){
        t = s[n/2-1];
        t += s[n/2];
    }
    else{
        t = s[n/2];
    }
    
    return t;
}

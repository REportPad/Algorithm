#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    string ans = "";
    int start = 0;
    
    for(int i=0; i < n; ++i){
        if(s[i] == ' '){
            start = 0;
        }
        else if(start == 0){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 'a' + 'A';
            }
            start = 1;
        }
        else{
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }
    
    ans = s;
    return ans;
}

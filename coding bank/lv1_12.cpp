#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string ans = "";
    
    for(int i=0; i < s.size(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            int c = (s[i] + n);
            //cout << c << endl;
            c = (c-'A')%26 + 'A';
            char t = c;
            ans += t;
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            int c = (s[i] + n);
            //cout << c << endl;
            c = (c-'a')%26 + 'a';
            char t = c;
            ans += t;
        }
        else{
            ans += s[i];
        }
    }
    
    return ans;
}

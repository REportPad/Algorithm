#include<string>
#include <iostream>

using namespace std;

bool solution(string s){
    int cnt = 0;
    for(int i=0; i < s.size(); ++i){
        if(s[i] == '('){
            ++cnt;
        }
        else{
            --cnt;
        }
        
        if(cnt < 0) return false;
        //cout << cnt << endl;
    }
    
    if(cnt == 0) return true;
    return false;
}

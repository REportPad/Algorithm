#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pcnt = 0;
    int ycnt = 0;
    for(int i=0; i < s.size(); ++i){
        if(s[i] == 'P' || s[i] == 'p'){
            ++pcnt;
        }
        if(s[i] == 'Y' || s[i] == 'y'){
            ++ycnt;
        }
    }
    
    if(pcnt != ycnt) answer = false;
    
    return answer;
}

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string a = "김서방은 ";
    string b = "에 있다";
    int n = seoul.size();
    string t;
    
    for(int i=0; i < n; ++i){
        if(seoul[i] == "Kim"){
            t = to_string(i);
            break;
        }
    }
    
    a += t;
    a += b;
    
    return a;
}

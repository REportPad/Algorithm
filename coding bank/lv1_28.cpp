#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string s = "";
    for(int i=0; i < n; ++i){
        if(i%2 == 0){
            s += "수";
        }
        else{
            s += "박";
        }
    }
    
    return s;
}

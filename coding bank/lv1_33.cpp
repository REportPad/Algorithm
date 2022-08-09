#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int n = phone_number.size();
    string s = "";
    for(int i=0; i < n-4; ++i){
        s += '*';
    }
    
    for(int i=0; i < 4; ++i){
        s += phone_number[n-4+i];
    }
    
    return s;
}

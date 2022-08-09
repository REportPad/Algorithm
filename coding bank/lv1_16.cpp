#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string day[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int lastDay[] = {-1,31,29,31,30,31,30,31,31,30,31,30,31};
    int init[12] = {0,};
    
    init[0] = -1;
    init[1] = 4;
    //cout << init[1] << " ";
    for(int i=1; i < 12; ++i){
        init[i+1] = (lastDay[i] + init[i])%7;
        //cout << init[i+1] << " ";
    }
    
    return day[(b + init[a])%7];
}

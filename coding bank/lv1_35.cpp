#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int sum = 0;
    for(int i=1; i <= n; ++i){
        if(n%i == 0){
            sum += i;
            //cout << i << ", " << sum << endl;
        }
    }
    
    return sum;
}

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int t = n;
    int sum = 0;
    
    while(t > 0){
        sum += (t%2);
        t /= 2;
    }
    int sum_n = sum;
    
    int u = 1;
    while(1){
        t = n+u;
        sum = 0;
        
        //2digit
        while(t > 0){
            sum += (t%2);
            t /= 2;
        }
        
        if(sum_n == sum){
            return (n+u);
        }
        ++u;
    }
}

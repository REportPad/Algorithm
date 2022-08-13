#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n == 1 || n == 2){
        return 1;
    }
    
    int cnt = 1;//n
    
    for(int i=2; i < n; ++i){
        int sum = i*(i-1)/2;
        
        for(int a=1; a < n; ++a){
            int t = i*a + sum;
            if(t == n){
                ++cnt;
                break;
            }
            else if(t > n){
                break;
            }
        }        
    }
    
    return cnt;
}

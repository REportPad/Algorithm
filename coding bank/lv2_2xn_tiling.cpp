#include <string>
#include <vector>

using namespace std;

#define N 60001
#define M 1000000007

int visit[N];

int solution(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    visit[0] = 1;
    visit[1] = 2;
    for(int i=2; i < n; ++i){
        visit[i] = (visit[i-1]%M + visit[i-2]%M)%M;
    }
    
    return visit[n-1]%M;
}

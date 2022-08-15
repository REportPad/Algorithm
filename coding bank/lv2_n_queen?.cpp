#include <string>
#include <vector>

using namespace std;

#define N 12

int count;
int col[N];
int diag1[2*N];
int diag2[2*N];

void search(int y, int n){
    if(y == n){
        count++;
        return;
    }
    
    for(int x=0; x < n; x++){//8
        if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1, n);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int solution(int n) {
    search(0, n);
    return count;
}

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double avg = 0;
    int n = arr.size();
    for(int i=0; i < n; ++i){
        avg += arr[i];
    }
    avg /= n;
    return avg;
}

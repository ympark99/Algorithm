#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000000

int counts[MAX * 2 + 1] = {0,};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        counts[num + MAX]++;
    }

    cin >> M;    
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        cout << counts[target + MAX] << " ";
    }
    return 0;
}

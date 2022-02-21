#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int N; cin >> N;

    int arr[10] = {0, };

    while(1){
        arr[N % 10]++;
        if(N / 10 == 0) break;
        N /= 10;
    }

    int ans = 0;

    for(int i = 0; i < 10; i++){
        if(i != 6 && i != 9) ans = max(ans, arr[i]);
    }

    cout << max(ans, (arr[6] + arr[9] + 1) / 2);
    
    return 0;
}

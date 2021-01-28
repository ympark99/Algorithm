#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int* arr = new int[n+1];
    int* dp = new int[n+1];
    int cnt = 1;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[0] = arr[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        if(arr[i] <= arr[cnt]) dp[i] = dp[cnt];
        else{
            dp[i] = dp[cnt] + 1;
            cnt = i;
        }
    }

    cout << dp[n];
}

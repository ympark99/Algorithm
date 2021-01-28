#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int* arr = new int[n+1];
    int* dp = new int[n+1];

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[0] = arr[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i=3; i<=n; i++){
        dp[i] = arr[i] +  max(arr[i-1] + dp[i-3], dp[i-2]);
        dp[i] = max(dp[i],dp[i-1]);
    }

    cout << dp[n];
}

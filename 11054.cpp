#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    int arr[1001];
    int dp[2][1001];
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        dp[0][i] = 1;
        for(int j = 1; j < i; j++)
            if(arr[i] > arr[j] && dp[0][i] < dp[0][j] + 1)
                dp[0][i] = dp[0][j] + 1;
    }
    
    for(int i = N; i >= 1; i--){
        dp[1][i] = 1;
        for(int j = N; j > i; j--)
            if(arr[i] > arr[j] && dp[1][i] < dp[1][j] + 1)
                dp[1][i] = dp[1][j] + 1;
    }
    
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(max < dp[0][i] + dp[1][i] - 1)
            max = dp[0][i] + dp[1][i] - 1;
    }
    
    cout << max << '\n';
    
    return 0;
}

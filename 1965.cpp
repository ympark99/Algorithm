#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000 + 1];
int dp[1000 + 1];

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];    
    
    int res = 0;

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);        
    }

    cout << res;

    return 0;
}

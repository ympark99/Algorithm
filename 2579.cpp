#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int dp[300 + 1] = {0, };
    int score[300 + 1] = {0,};
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> score[i + 1];
    }

    dp[1] = score[1], dp[2] = dp[1] + score[2], dp[3] = max(score[1], score[2]) + score[3];

    for(int i = 4; i <= n; i++){
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }

    cout << dp[n];

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[300];
    int dp[300];

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = arr[0];
    dp[1] = max(arr[0]+arr[1], arr[1]);
    dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]);

    for (int i = 3; i < n; i++) dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    cout << dp[n-1];

    return 0;
}
*/

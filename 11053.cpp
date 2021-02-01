#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int arr[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> arr[i];
        dp[i] = 1; //길이가 1인 경우로 초기화
    }
    for (int i=0; i < n; i++) {
        int& last_val = arr[i];
        for (int j=0; j < i; j++) {
            int& target_val = arr[j];
            if (last_val > target_val) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
	return 0;
}

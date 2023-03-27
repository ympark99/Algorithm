#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dp[41];
int idx = 1, ans = 1;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
	for(int i = 3; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

    int vip;
    for(int i = 0; i < M; i++){
        cin >> vip;
        ans *= dp[vip - idx];
        idx = vip + 1;
    }
    ans *= dp[N + 1 - idx];

    cout << ans << '\n';
    return 0;
}

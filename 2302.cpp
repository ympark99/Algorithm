#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int dp[40 + 1] = {0, };
    bool isVip[40 + 1] = {false,};
    int answer = 1;

    int N;
    cin >> N;

    int M;
    cin >> M;

    while(M--){
        int vip;
        cin >> vip;
        isVip[vip] = true;
    }   

    dp[1] = 1, dp[2] = 2;

    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        cnt++;
        if(isVip[i] == true){
            cnt--;
            answer *= dp[cnt];
            cnt = 0;
        }
    }
    if(cnt > 0) answer *= dp[cnt];

    cout << answer;

    return 0;
}

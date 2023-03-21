#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool dp[2001][2001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<int> v(N+1);
    for(int i = 1; i <= N; i++)  
        cin >> v[i];

    for(int i = 1; i <= N-1; i++){
        dp[i][i] = true;
        if(v[i] == v[i+1])
            dp[i][i+1] = true;
    }
    dp[N][N] = true;

    for(int i = N - 1; i >= 1; i--){
        for(int j = i + 1; j <= N; j++){
            if(v[i] == v[j] && dp[i+1][j-1])
                dp[i][j] = true;
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}

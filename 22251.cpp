#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ans;
int N, K, P, X; // N : 최대층 K : 최대자리 P : 최대반전 X : 실제위치

vector<vector<bool>> led(10, vector<bool>(7));

void init_led(){
    // 최상 상좌 상우 중 하좌 하우 최하
    led[0] = {1, 1, 1, 0, 1, 1, 1};
    led[1] = {0, 0, 1, 0, 0, 1, 0};
    led[2] = {1, 0, 1, 1, 1, 0, 1};
    led[3] = {1, 0, 1, 1, 0, 1, 1};
    led[4] = {0, 1, 1, 1, 0, 1, 0};
    led[5] = {1, 1, 0, 1, 0, 1, 1};
    led[6] = {1, 1, 0, 1, 1, 1, 1};
    led[7] = {1, 0, 1, 0, 0, 1, 0};
    led[8] = {1, 1, 1, 1, 1, 1, 1};
    led[9] = {1, 1, 1, 1, 0, 1, 1};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> P >> X;

    init_led();

    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        int cnt = 0;
        int now = X, target = i;
        for(int j = 0; j < K; j++){
            for(int idx = 0; idx < 7; idx++){
                if(led[now % 10][idx] != led[target%10][idx])
                    cnt++;
            }
            now /= 10;
            target /= 10;
            if(cnt > P) break;
        }
        if(cnt <= P)
            ans++;
    }
    cout << ans << '\n';
}

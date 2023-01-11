#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<pair<int, bool>> v(N * 2, {0, false});
    for(int i = 0; i < N * 2; i++)
        cin >> v[i].first;

    int upIdx = 0;
    int ans = 1;
    while(true){
        upIdx = (upIdx + (N * 2) - 1) % (N * 2); // 벨트 이동
        int downIdx = (upIdx + N - 1) % (N * 2);
        if(v[downIdx].second)
            v[downIdx].second = false; // 로봇있으면 내림
        for(int i = upIdx + N - 1; i >= upIdx; i--){
            int nowIdx = i % (N * 2); // i가 2N보다 클 수 있음
            int nextIdx = (nowIdx + 1) % (N * 2);
            if(v[nowIdx].second && (!v[nextIdx].second && v[nextIdx].first > 0)){
                v[nowIdx].second = false;
                v[nextIdx].first--;
                v[nextIdx].second = true;
            }
        }
        if(v[downIdx].second)
            v[downIdx].second = false; // 로봇있으면 내림
        // 새로운 로봇 올리기
        if(v[upIdx].first > 0){
            v[upIdx].first--;
            v[upIdx].second = true;
        }
        int cnt = 0;
        for(auto elem : v){
            if(elem.first == 0)
                cnt++;
        }
        if(cnt >= K) break;
        ans++;
    }
    cout << ans << '\n';
	return 0;
}

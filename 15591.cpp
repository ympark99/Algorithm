#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v[5000+1]; // idx, val

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for(int i = 0; i < N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 0; i < Q; i++){
        vector<bool> visit(5000+1, false);
        int ans = 0;
        int k, video;
        cin >> k >> video;
        queue<int> q;
        visit[video] = true;
        q.push(video);
        while(!q.empty()){
            int now_idx = q.front();
            q.pop();
            for(int j = 0; j < v[now_idx].size(); j++){
                int next_idx = v[now_idx][j].first;
                if(visit[next_idx]) continue;
                int next_val = v[now_idx][j].second;
                if(next_val >= k){
                    visit[now_idx] = true;
                    ans++;
                    q.push(next_idx);
                }
            }
        }
        cout << ans << '\n';
    }
	return 0;
}

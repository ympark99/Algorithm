#include <bits/stdc++.h>

using namespace std;

vector<int> v;
bool check[100001];
bool done[100001];
int cnt; // 프로젝트 팀 결성

void dfs(int now) {
	check[now] = true;
	int next = v[now];

	if(!check[next])
		dfs(next);
	else if(!done[next]) {
		for(int i = next; i != now; i = v[i]) {
			cnt++;
		}
		cnt++; // 본인
	}
	done[now] = true;
	return;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		v.resize(n+1);
		for(int i = 1; i <= n; i++) {
			cin >> v[i];
		}

		for(int i = 1; i <= n; i++) {
			if(!check[i])
				dfs(i);
		}
		cout << n - cnt << '\n';
		cnt = 0;
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));
	}
	return 0;
}

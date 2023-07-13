#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> bridge[10001];
pair<int, int> company;
bool check[10001];
int ans;

bool cal(int mid) {
	queue<int> q;
	q.push(company.first);

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		check[now] = true;

		if(now == company.second) {
			return true;
		}

		for(int i = 0; i < bridge[now].size(); i++) {
			int next = bridge[now][i].first;
			int weight = bridge[now][i].second;

			if(mid <= weight && !check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int maxWeight = 0;
	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		maxWeight = max(maxWeight, c);

		bridge[a].push_back({b, c});
		bridge[b].push_back({a, c});
	}
	cin >> company.first >> company.second;

	int left = 1;
	int right = maxWeight;

	while(left <= right) {
		int mid = (left + right) / 2;

		if(cal(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
		memset(check, false, sizeof(check));
	}
	cout << ans << '\n';
	return 0;
}

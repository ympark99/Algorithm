#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> L;

	vector<pair<int, int>> v(N);

	for(int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	int now = 0, end = 0;
	for(auto elem : v){
		if(now >= elem.second) continue;
		now = max(now, elem.first);

		int cnt = (elem.second - (now + 1)) / L + 1;
		ans += cnt;
		now += cnt * L;
	}
	cout << ans << '\n';
	return 0;
}

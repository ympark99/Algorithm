#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	unordered_map<string, int> um;
	vector<string> ans;

	cin >> N >> M;
	string str = "";
	for(int i = 0; i < N; i++) {
		cin >> str;
		um[str] = 1;
	}
	for(int i = 0; i < M; i++) {
		cin >> str;
		if(um.find(str) != um.end())
			ans.push_back(str);
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for(auto elem : ans)
		cout << elem << '\n';
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int p, m;

bool comp(pair<int, char> a, pair<int, char> b) {
	return a.second < b.second;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> p >> m;

	vector<vector<pair<int, char>>> room; // level, nickname

	for(int i = 0; i < p; i++) {
		int level;
		char nickname;
		vector<pair<int, char>> v;
		cin >> level >> nickname;
		v.push_back({level, nickname});

		bool flag = true;
		for(int j = 0; j < room.size(); j++) {
			int standLevel = room[j][0].first;
			if(abs(standLevel - level) <= 10 && room[j].size() < m) {
				room[j].push_back({level, nickname});
				flag = false;
				break;
			}
		}
		if(flag)
			room.push_back(v);
	}

	for(int i = 0; i < room.size(); i++) {
		if(room[i].size() >= m) cout << "Started!\n";
		else if(room[i].size()) cout << "Waiting!\n";

		sort(room[i].begin(), room[i].end(), comp);

		for(int j = 0; j < room[i].size(); j++)
			cout << room[i][j].first << ' ' << room[i][j].second << '\n';
	}

	return 0;
}

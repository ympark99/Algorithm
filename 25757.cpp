#include <bits/stdc++.h>

using namespace std;

int N;
char game;

// Y - 2 F - 3 O - 4

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> game;

	unordered_map<string, int> um;

	for(int i = 0; i < N; i++) {
		string str = "";
		cin >> str;
		um[str]++;
	}

	if(game == 'Y')
		cout << um.size();
	else if(game == 'F')
		cout << um.size() / 2;
	else if(game == 'O')
		cout << um.size() / 3;
	
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int N;
char arr[6][6];
vector<pair<int, int>> teacher, none;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check_avoid(int row, int col) {
	for(int i = 0; i < 4; i++) {
		int nrow = row;
		int ncol = col;
		while(nrow >= 0 && nrow < N && ncol >= 0 && ncol < N) {
			nrow += dx[i];
			ncol += dy[i];
			if(arr[nrow][ncol] == 'O') 
				break;
			if(arr[nrow][ncol] == 'S')
				return false;
		}
	}
	return true;
}

void dfs(int idx, int cnt){
	if(cnt == 3) {
		for(auto elem: teacher) {
			if(!check_avoid(elem.first, elem.second)) {
				return;
			}
		}
		cout << "YES\n";
		exit(0);
	}
	for(int i = idx; i < none.size(); i++) {
		arr[none[i].first][none[i].second] = 'O';
		dfs(i+1, cnt+1);
		arr[none[i].first][none[i].second] = 'X';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 'T')
				teacher.push_back({i, j});
			else if(arr[i][j] == 'X') {
				none.push_back({i, j});
			}
		}
	}
	dfs(0, 0);
	cout << "NO\n";

	return 0;
}

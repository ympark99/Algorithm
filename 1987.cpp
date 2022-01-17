#include <iostream>
#include <algorithm>

using namespace std;

int R, C, ans;
char arr[20 + 2][20 + 2];
bool check[26];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int row, int col, int cnt){
	ans = max(ans, cnt);

	for(int i = 0; i < 4; i++){
		int ny = row + dy[i];
		int nx = col + dx[i];
		
		if(ny == 0 || ny > R || nx == 0 || nx > C) continue;

		if(!check[arr[ny][nx] - 'A']){
			check[arr[ny][nx] - 'A'] = true;
			dfs(row + dy[i], col + dx[i], cnt + 1);
			check[arr[ny][nx] - 'A'] = false;
		}
	}

	return;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			cin >> arr[i][j];

	check[arr[1][1] - 'A'] = true;
	dfs(1, 1, 1);
	cout << ans;

	return 0;
}

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int w, h;
int arr[50 + 1][50 + 1];
bool check[50 + 1][50 + 1];
queue<pair<int, int>> q;

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

void bfs(){
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx <= 0 || ny <= 0 || nx > w || ny > h)
				continue;
			if(arr[ny][nx] && !check[ny][nx]){
				q.push({ny, nx});
				check[ny][nx] = true;
			}
		}
	}
}

void dfs(int y, int x){
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx <= 0 || ny <= 0 || nx > w || ny > h)
				continue;
			if(arr[ny][nx] && !check[ny][nx]){
				check[ny][nx] = true;				
				dfs(ny, nx);
			}
		}	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	while (true){
		cin >> w >> h;
		int ans = 0;

		if(!w && !h) break;

		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++)
				cin >> arr[i][j];			
		}

		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				if(!check[i][j] && arr[i][j]){
					q.push({i, j});
					check[i][j] = true;
					dfs(i, j);
// 					bfs();
					ans++;
				}				
			}
		}

		cout << ans << '\n';
		memset(check, 0, sizeof(check));
	}

	return 0;
}

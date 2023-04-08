#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<pair<int, int>> virus;
vector<bool> virus_visited;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = 987987987;
int cnt_zero = 0;

void bfs() {
	queue<pair<int, int>> q;
	visited.assign(n + 1, vector<int>(n + 1, -1));
	// 동시에 돌리고 싶으면 이렇게 다 넣고 시작.
	for(int i = 0; i < virus.size(); ++i) {
		if (virus_visited[i]) {
			q.push(make_pair(virus[i].first, virus[i].second));
			visited[virus[i].first][virus[i].second] = 0;
		}
	}

	int check = 0;
	int time = 0;
	while(!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 1)
				continue;
			if (visited[nx][ny] == -1) {
				visited[nx][ny] = visited[cx][cy] + 1;
				// 동시에 돌리면 최소값 굳이 안찾아도 됨.
				if (map[nx][ny] == 0) {
					check++;
					time = visited[nx][ny];
				}
				q.push(make_pair(nx, ny));
			}
		}
	}
	// 0의 갯수가 방문한 0의 갯수와 같다면, 최소값으로 갱신
	// 아니라면 맨 마지막에 -1
	if (check == cnt_zero)
		ans = min(ans, time);
	return;
}

void pick(int k, int cnt) {
	if (cnt == m) {
		// 여기서 bfs
		bfs();
		return;
	} else {
		for(int i = k; i < virus.size(); ++i) {
			if (!virus_visited[i]) {
				virus_visited[i] = true;
				pick(i + 1, cnt + 1);
				virus_visited[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	map.assign(n + 1, vector<int>(n + 1, 0));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			if (map[i][j] == 0) {
				cnt_zero++;
			}
		}
	}

	virus_visited.assign(virus.size() + 1, false);

	pick(0, 0);
	if (ans == 987987987)
		ans = -1;

	printf("%d\n", ans);
}

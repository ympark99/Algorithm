#include <iostream>
#include <queue>
using namespace std;

int map[17][17];// 1~16 인덱스 사용
int n, ans;
int dx[3] = {0, +1, +1}; //가로 대각선 세로
int dy[3] = { +1, +1, 0 };

struct info {
	int x, y, d;
	//방향은 0, 1, 2 순서대로 가로, 대각선, 세로
};

queue<info>q;

void move(int x, int y, int d, int i) {
	int nx = x + dx[i];
	int ny = y + dy[i];
	int nd = i;
	if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
		if (i == 1) {//대각선은 추가 체크
			if (map[nx - 1][ny] == 1 || map[nx][ny - 1] == 1)
				return;
		}
		q.push({ nx, ny, nd });
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	q.push({ 1,2,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		if (x == n && y == n)
			ans++;
		if (d == 0) { //가로
			for (int i = 0; i < 2; i++) { //0,1로 이동
				move(x, y, d, i);
			}
		}
		else if (d == 1) {//대각선
			for (int i = 0; i < 3; i++) { //0,1,2로 이동
				move(x, y, d, i);
			}
		}
		else {//아래
			for (int i = 1; i < 3; i++) { //1,2로 이동
				move(x, y, d, i);
			}
		}
	}
	cout << ans;
	return 0;
}

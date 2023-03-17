#include <iostream>
#include <queue>

using namespace std;

struct step{
	int Rx, Ry;
	int Bx, By;
	int cnt;
};

char map[11][11];
bool check[11][11][11][11];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i){
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O'){
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

void bfs(int Rx, int Ry, int Bx, int By){
	queue<step> q;
	q.push({ Rx,Ry,Bx,By,0 });
	check[Rx][Ry][Rx][Ry] = true;
	while (!q.empty()){
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;

		for (int i = 0; i < 4; i++){
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncnt = cnt + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O'){
				cout << ncnt;
				return;
			}
            // 공 겹치는 경우
			if (nrx == nbx && nry == nby){
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (check[nrx][nry][nbx][nby]) continue;
			check[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncnt });
		}
	}
	cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int Rx = 0, Ry = 0, Bx = 0, By = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 'R'){
				Rx = i; Ry = j;
			}
			else if (map[i][j] == 'B'){
				Bx = i; By = j;
			}
		}
	}
	bfs(Rx, Ry, Bx, By);

	return 0;
}

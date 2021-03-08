#include <cstdio>
#include <cstring>
using namespace std;
int map[129][129];
int w_cnt = 0, b_cnt = 0; 

void div_conq(int x, int y, int N) {
	int tmp_cnt = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j]) {
				tmp_cnt++;
			}
		}
	}
	if (!tmp_cnt) w_cnt++; // no count
	else if (tmp_cnt == N * N) b_cnt++; // all count
	else {
		div_conq(x, y, N / 2);  // left top
		div_conq(x, y + N / 2, N / 2); // right top
		div_conq(x + N / 2, y, N / 2); // left bottom
		div_conq(x + N / 2, y + N / 2, N / 2); // right bottom
	}
	return;
}

int main() {
	int n;
	memset(map, 0, sizeof(map));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	div_conq(0, 0, n); // divide and conquer
	printf("%d\n", w_cnt);
	printf("%d\n", b_cnt);
	return 0;
}

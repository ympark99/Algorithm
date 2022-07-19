#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//min
#include <cstring>//memset
#include <cmath>//abs
using namespace std;

struct Pos {
	int x, y;
};

int N, M;
bool check[13];

vector<Pos> House;
vector<Pos> Pick;
vector<Pos> Chicken;

int Min = 9999999;

//M개 치킨집 조합 구하기
void getChicken(int x, int cnt) {
	if (cnt == M) {
		int res = 0;
		for (int i = 0; i < House.size(); i++) {
			int min_dist = 9999999;
			//각 집에서 가장 가까운 치킨집 찾기
			for (int j = 0; j < Pick.size(); j++) {
				min_dist = min(min_dist, abs(House[i].x - Pick[j].x) + abs(House[i].y - Pick[j].y));
			}
			res += min_dist;
		}
		Min = min(Min, res);
		return;
	}
	for (int i = x; i < Chicken.size(); i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		Pick.push_back({ Chicken[i].x, Chicken[i].y });
		getChicken(i, cnt + 1);
		check[i] = false;
		Pick.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n == 1)
				House.push_back({ i,j });
			else if (n == 2)
				Chicken.push_back({ i,j });
		}
	}
	getChicken(0, 0);
	cout << Min << '\n';
	return 0;
}

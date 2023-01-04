#include <bits/stdc++.h>

using namespace std;

int res;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> building(N);
	vector<int> cnt(N, 0);
	for(int i = 0; i < N; i++)
		cin >> building[i];

	for(int i = 0; i < N; i++){
		double max_level = -9999999999;
		for(int j = i + 1; j < N; j++){
			double level = (double)(building[j] - building[i]) / (j - i);
			if(level > max_level){
				cnt[i]++;
				cnt[j]++;
				max_level = level;
			}
		}
	}

	for(auto elem : cnt)
		res = max(res, elem);
	cout << res << '\n';
	return 0;
}

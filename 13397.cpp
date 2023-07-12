#include <bits/stdc++.h>

using namespace std;

int N, M;

bool isOk(vector<int> &v, int mid) {
	int cnt = 1;
    int minV, maxV;

    minV = v[0];
    maxV = v[0];

    for(int i = 1; i < N; i++){
		minV = min(minV, v[i]);
		maxV = max(maxV, v[i]);

		// 구간 점수 넘어가면 새로운 구간
        if ((maxV - minV) > mid){
            cnt++;
            minV = v[i];
            maxV = v[i];
        }
    }
	// 구간 개수 M 이하이면 ok
    return cnt <= M;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<int> v(N);

	for(int i = 0; i < N; i++)
		cin >> v[i];

	int right = *max_element(v.begin(), v.end());
	int left = 0;
	int res = right;

	while(left <= right) {
		// 구간 점수 최댓값
		int mid = (left + right) / 2;

		if(isOk(v, mid)) {
			res = min(res, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << res << '\n';

	return 0;
}

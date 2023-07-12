#include <bits/stdc++.h>

using namespace std;

int N, M;

bool cal(vector<int> v, int mid) {
	long long sum = 0;
	for(auto elem: v) {
		if(elem > mid)
			sum += (elem - mid);
	}
	if(sum >= M) 
		return true;
	else 
		return false;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<int> v(N);

	for(int i = 0; i < N; i++)
		cin >> v[i];

	long long left = 0;
	long long right = *max_element(v.begin(), v.end());
	long long ans = 0;

	while(left <= right) {
		long long mid = (left + right) / 2;
		if(cal(v, mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans << '\n';

	return 0;
}

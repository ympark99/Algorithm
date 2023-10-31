#include <bits/stdc++.h>

using namespace std;

int N, K;
int sum, cnt, idx;
int ans = -987654321;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	vector<int> v;

	for(int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		if(cnt < K) {
			sum += num;
			cnt++;
			if(cnt == K)
				ans = max(ans, sum);
		}
		else {
			sum -= v[idx++];
			sum += num;
			ans = max(ans, sum);
		}
	}
	
	cout << ans << '\n';

	return 0;
}

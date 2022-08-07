#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> v(N);

	for(int i = 0; i < N; i++)
		cin >> v[i];

	int ans = 0;

	for(int i = 0; i < N; i++){
		int flag = 0;
		int coupon = 1;
		bool check[30000 + 1] = {false, };
		for(int j = 0; j < k; j++){
			int val = v[(i + j) % N];
			if(check[val]) flag++;
			else check[val] = true;
			if(val == c) coupon = 0;
		}
		ans = max(ans, k - flag + coupon);
	}
	cout << ans;
}

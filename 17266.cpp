#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int pre = 0;
	int ans = 1;

	for(int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if(i == 0) {
			ans = max(ans, num);
			pre = num;
		}
		if(i == M-1) {
			ans = max(ans, N - num);
			pre = num;
		}
		else {
			if((num - pre) % 2 == 0) {
				ans = max(ans, (num - pre) / 2);
			}
			else
				ans = max(ans, (num - pre) / 2 + 1);
			pre = num;
		}
	}

	cout << ans << '\n';

	return 0;
}

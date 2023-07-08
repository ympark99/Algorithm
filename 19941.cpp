#include <bits/stdc++.h>

using namespace std;

int N, K, ans;
string str;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K >> str;

	for(int i = 0; i < N; i++){
		if(str[i] == 'P') {
			for(int j = i-K; j <= i+K; j++) {
				if(j < 0) continue;
				if(j >= N) break;
				if(str[j] == 'H') {
					str[j] = 'X';
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}

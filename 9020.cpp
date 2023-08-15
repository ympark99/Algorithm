#include <bits/stdc++.h>
 
using namespace std;

int T, N;
int prime[10001];
int min_diff = 10001;
pair<int, int> ans;

bool isPrime(int num) {
	if(num < 2) return false;

	for(int i = 2; i <= sqrt(num); i++)
		if(num % i == 0) return false;

	return true;
}

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	for(int i = 2; i <= 10000; i++) {
		if(isPrime(i))
			prime[i] = true;
	}

	cin >> T;
	while(T--) {
		cin >> N;

		for(int i = 2; i <= N/2; i++) {
			if(prime[i] && prime[N - i]) {
				if(abs(N - i * 2) < min_diff) {
					min_diff = N - i * 2;
					ans.first = i;
					ans.second = N - i;
				}
			}
		}
		cout << ans.first << ' ' << ans.second << '\n';
		min_diff = 10001;
	}

    return 0;
}

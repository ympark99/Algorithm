#include <bits/stdc++.h>

using namespace std;

int N;
bool arr[100][100];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int ans = 0;

	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for(int j = b; j < b + 10; j++) {
			for(int k = a; k < a + 10; k++) {
				if(!arr[j][k]) {
					arr[j][k] = true;
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

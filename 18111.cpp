#include <bits/stdc++.h>

using namespace std;

int N, M, B;

int arr[501][501];
int ans = 987654321;
int height;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> B;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for(int k = 0; k <= 256; k++) {
		int sum = 0, tmp = B;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				// 블록 꺼내기
				if(arr[i][j] < k) {
					sum += k - arr[i][j];
					tmp -= k - arr[i][j];
				}
				else if(arr[i][j] > k) {
					sum += (arr[i][j] - k) * 2;
					tmp += arr[i][j] - k;
				}
			}
		}
		if(tmp >= 0) {
			if(sum <= ans) {
				ans = sum;
				height = k;
			}
		}
	}

	cout << ans << " " << height << '\n';

	return 0;
}

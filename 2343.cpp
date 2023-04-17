#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans = 987654321;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<int> v(N);

	int sum = 0, low = -1;
	for(int i = 0; i < N; i++){
		cin >> v[i];
		sum += v[i];
		low = max(low, v[i]);
	}
	int high = sum;

	while(low <= high){
		int cnt = 0, tempSum = 0;
		int mid = (low + high) / 2;

		for(int i = 0; i < N; i++){
			if(tempSum + v[i] > mid){
				tempSum = 0;
				cnt++;
			}
			tempSum += v[i];
		}
		if(tempSum != 0) cnt++;

		if(cnt <= M){
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << low << '\n';
	return 0;
}

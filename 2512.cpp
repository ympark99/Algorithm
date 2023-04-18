#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int low, high, mid;
int ans;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> v(N);
	for(int i = 0; i < N; i++)	
		cin >> v[i];
	cin >> M;

	sort(v.begin(), v.end());

	low = 0;
	high = v[N-1];

	while(low <= high){
		int mid = (low + high) / 2;
		int sum = 0;
		for(int i = 0; i < N; i++){
			sum += min(v[i], mid);
		}
		if(sum > M){
			high = mid - 1;
		}
		else{
			ans = mid;
			low = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}

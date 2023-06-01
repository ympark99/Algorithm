#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int ans = 1;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> L;

	vector<int> v(N);

	for(int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int now = v[0];
	for(int i = 1; i < v.size(); i++) {
		if(v[i] - now + 1 > L){
			ans++;
			now = v[i];
		}
	}	
	cout << ans;

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;
ll ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	
	ll num = 0;
	for(int i = 0; i < n; i++){
		cin >> num;
		pq.push(num);
	}

	for(int i = 0; i < m; i++){
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();

		ll sum = a + b;
		pq.push(sum);
		pq.push(sum);
	}

	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
	cout << ans << '\n';

	return 0;
}

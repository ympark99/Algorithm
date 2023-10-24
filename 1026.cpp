#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> a;
	vector<int> b;
	int ans = 0;

	cin >> N;

	int num;
	for(int i = 0; i < N; i++) {
		cin >> num;
		a.push_back(num);
	}

	for(int i = 0; i < N; i++) {
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for(int i = 0; i < N; i++) {
		ans += a[i] * b[i];
	}

	cout << ans << '\n';

	return 0;
}

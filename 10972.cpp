#include <bits/stdc++.h>

using namespace std;

int N;
int pre_idx;
int swap_a, swap_b;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int> v(N);
	
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if(next_permutation(v.begin(), v.end())) {
		for(int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
	}
	else cout << -1 << '\n';

	return 0;
}

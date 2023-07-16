#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	

	cin >> N >> K;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	while (q.size() > 1) {
		for (int i = 1; i < K; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
	
	return 0;
}

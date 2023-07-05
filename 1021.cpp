#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
int ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	deque<int> dq;
	int left, right;
	int cnt = 0;

	for(int i = 1; i <= N; i++)
		dq.push_back(i);

	while(M--) {
		int num;
		cin >> num;

		for(int i = 0; i < dq.size(); i++) {
			if(dq[i] == num) {
				left = i;
				right = dq.size() - i;
				break;
			}
		}
		
		if(left <= right) {
			while(1) {
				if(dq.front() == num)
					break;
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else {
			cnt++;
			while(1) {
				if(dq.back() == num)
					break;
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_back();
		}
	}
	cout << cnt << '\n';
	return 0;
}

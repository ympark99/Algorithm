#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	int num = 0;
	for(int i = 0; i < N; i++){
		cin >> num;

		if(num == 0){
			if(pq.empty()){
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else{
			pq.push(num);
		}
	}
}

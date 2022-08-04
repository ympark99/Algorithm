#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	int num;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> num;
			if(pq.size() < N) pq.push(num);
			else if(pq.top() < num){
				pq.pop();
				pq.push(num);
			}
		}
	}
	cout << pq.top();
}

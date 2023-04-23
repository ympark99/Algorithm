#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cost, sum;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<int> package(M);
	vector<int> item(M);

	for(int i = 0; i < M; i++){
		cin >> package[i] >> item[i];
	}

	sort(package.begin(), package.end());
	sort(item.begin(), item.end());

	if(N < 6){
		cout << min(package[0], item[0] * N);
		return 0;
	}

	while(1){
		if(sum >= N) break;

		if(N - sum < 6){
			cost += min(package[0], item[0] * (N - sum));
			break;
		}

		if(package[0] <= item[0] * 6){
			sum += 6;
			cost += package[0];
		}
		else{
			sum += 6;
			cost += item[0] * 6;
		}
	}	
	cout << cost << '\n';
	return 0;
}

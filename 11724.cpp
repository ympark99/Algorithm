#include <iostream>
#include <queue>

using namespace std;

int arr[1000 + 1][1000 + 1];
bool check[1000 + 1];

int N, M, ans;
queue<int> q;

void dfs(int num){
	check[num] = true;
	for(int i = 1; i <= N; i++){
		if(arr[num][i] && !check[i])
			dfs(i);
	}
	return;
}

void bfs(int num){
	q.push(num);
	check[num] = true;

	while (!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 1; i <= N; i++){
			if(arr[now][i] && !check[i]){
				check[i] = true;
				q.push(i);
			}
		}
	}	
	return;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	int u, v = 0;
	for(int i = 1; i <= M; i++){
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for(int i = 1; i <= N; i++){
		if(!check[i]){
			// dfs(i);
			bfs(i);
			ans++;
		}
	}

	cout << ans;
	return 0;
}

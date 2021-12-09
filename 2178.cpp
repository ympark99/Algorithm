#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	string arr[101];
	int dist[101][101];
	bool check[101][101];
	
	queue<pair<int,int> > q;
	int n,m;

	cin >> n >> m;
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];	
	}
	
	dist[0][0] = 1;
	q.push({0,0});
	check[0][0] = 1;
	
	while(!q.empty()){
		
		pair<int,int> cur = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){ 
			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];
			
			if(nextx < 0 || nextx >= n || nexty < 0 || nexty >=m)
				continue;
				
			if(arr[nextx][nexty] =='0' || check[nextx][nexty])
				continue;
			
			dist[nextx][nexty] = dist[cur.first][cur.second] + 1;
			q.push({nextx,nexty});
			check[nextx][nexty] = 1;
			
		}
	}

	cout << dist[n - 1][m - 1];
	
	return 0; 
} 

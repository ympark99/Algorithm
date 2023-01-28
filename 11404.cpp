#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, 987654321));
    int a, b, c;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(dist[a][b] > c)
            dist[a][b] = c;
    }

    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
        
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int ans = (dist[i][j] == 987654321? 0 : dist[i][j]);
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}

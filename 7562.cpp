#include <bits/stdc++.h>

using namespace std;

struct chess{
    int row;
    int col;
    int cnt;
};

int dx[8] = {-2, 2, -2, 2, 1, -1, 1, -1};
int dy[8] = {1, 1, -1, -1, -2, 2, 2, -2};
bool check[301][301];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while (T--){
        int ans = 987654321;
        int len;
        pair<int, int> start, end;
        cin >> len;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        memset(check, false, sizeof(check));
        queue<chess> q;
        q.push({start.first, start.second, 0});
        while (!q.empty()){
            int row = q.front().row;
            int col = q.front().col;
            int cnt = q.front().cnt;
            check[row][col] = true;
            q.pop();
            if(end.first == row && end.second == col){
                ans = min(ans, cnt);
            }
            else{
                for(int i = 0; i < 8; i++){
                    int nrow = row + dy[i];
                    int ncol = col + dx[i];
                    if(nrow < 0 || nrow >= len || ncol < 0 || ncol >= len || check[nrow][ncol])
                        continue;
                    q.push({nrow, ncol, cnt+1});
                    check[nrow][ncol] = true;
                }
            }
        }
        cout << ans << '\n';
    }
}

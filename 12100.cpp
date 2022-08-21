#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans = 0;

vector<vector<int>> right(vector<vector<int>> v){
    for(int i = 1; i <= N; i++){
        for(int j = N; j >= 1; j--){
            int ori = v[i][j];
            pair<int, int> p = {i, j};

            for(int k = j - 1; k >= 1; k--){
                if(ori == v[i][k] || ori == 0){
                    if(ori == v[i][k])
                        v[p.first][p.second] *= 2;
                    else v[p.first][p.second] = v[i][k];
                    v[i][k] = 0;
                    ori = 0;
                    p = {i, k};
                }
            }
        }
        ans = max(ans, v[i][N]);
    }
    return v;
}

vector<vector<int>> left(vector<vector<int>> v){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int ori = v[i][j];
            pair<int, int> p = {i, j};

            for(int k = j + 1; k <= N; k++){
                if(ori == v[i][k] || ori == 0){
                    if(ori == v[i][k])
                        v[p.first][p.second] *= 2;
                    else v[p.first][p.second] = v[i][k];
                    v[i][k] = 0;
                    ori = 0;
                    p = {i, k};
                }
            }
        }
        ans = max(ans, v[i][1]);
    }
    return v;
}

vector<vector<int>> down(vector<vector<int>> v){
    for(int i = 1; i <= N; i++){
        for(int j = N; j >= 1; j--){
            int ori = v[j][i];
            pair<int, int> p = {j, i};

            for(int k = j - 1; k >= 1; k--){
                if(ori == v[k][i] || ori == 0){
                    if(ori == v[k][i])
                        v[p.first][p.second] *= 2;
                    else v[p.first][p.second] = v[k][i];
                    v[k][i] = 0;
                    ori = 0;
                    p = {k, i};
                }
            }
        }
        ans = max(ans, v[N][i]);
    }
    return v;
}

vector<vector<int>> up(vector<vector<int>> v){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int ori = v[j][i];
            pair<int, int> p = {j, i};

            for(int k = j + 1; k <= N; k++){
                if(ori == v[k][i] || ori == 0){
                    if(ori == v[k][i])
                        v[p.first][p.second] *= 2;
                    else v[p.first][p.second] = v[k][i];
                    v[k][i] = 0;
                    ori = 0;
                    p = {k, i};
                }
            }
        }
        ans = max(ans, v[1][i]);
    }
    return v;
}

void dfs(vector<vector<int>> v, int cnt){
    if(cnt == N){
        return;
    }    
    dfs(up(v), cnt+1);
    dfs(down(v), cnt+1);
    dfs(left(v), cnt+1);
    dfs(right(v), cnt+1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<vector<int>> v(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> v[i][j];

    dfs(v, 0);
    cout << ans;
}

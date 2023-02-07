#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int arr[20+1][20+1];
int sharkSize = 2;
int eat;
pair<int, int> sharkNow;
vector<pair<int, int>> fish[6+1];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int get_distance(pair<int, int> target){
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> check(21, vector<bool>(21, false));
    q.push(make_pair(sharkNow, 0));
    arr[sharkNow.first][sharkNow.second] = 0; // 상어 이동하므로 빈칸

    int res = -1;

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cnt = q.front().second;
        check[row][col] = true;
        q.pop();
        if(row == target.first && col == target.second){
            res = cnt;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nRow = row + dy[i];
            int nCol = col + dx[i];

            if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= N || check[nRow][nCol])
                continue;

            if(arr[nRow][nCol] > sharkSize)
                continue;
            
            check[nRow][nCol] = true;
            q.push({{nRow, nCol}, cnt+1});
        }
    }
    return res;
}

int search_target(){
    vector<pair<int, int>> v; // 먹을 수 있는 물고기들

    for(int i = 1; i < sharkSize; i++){
        for(int j = 0; j < fish[i].size(); j++)
            v.push_back(fish[i][j]);     
    }

    pair<int, int> result;
    int result_cnt = 987654321;

    if(v.empty())
        return -1;

    for(int i = 0; i < v.size(); i++){
        int distance = get_distance(v[i]);
        if(distance < result_cnt){
            result_cnt = distance;
            result = v[i];
        }
        else if(distance == result_cnt){
            if(result.first == v[i].first){
                if(v[i].second < result.second){
                    result_cnt = distance;
                    result = v[i];                        
                }
            }
            else if(v[i].first < result.first){
                result_cnt = distance;
                result = v[i];
            }
        }
    }

    // 상어 식사
    if(result_cnt == -1)
        return -1;
    ans += result_cnt; // 시간 더해주기
    eat++; // 잡아먹은 물고기수 ++
    arr[result.first][result.second] = 0; // 물고기 먹은 칸 빈칸
    sharkNow = result; // 상어 이동

    // 상어 커지는 경우
    if(eat == sharkSize){
        sharkSize++;
        eat = 0;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 9)
                fish[arr[i][j]].push_back({i, j});
            else if(arr[i][j] == 9)
                sharkNow = {i, j};
        }
    }
    while(true){
        int status = search_target();
        if(status == -1){
            cout << ans << '\n';
            break;
        }
    }
    return 0;
}

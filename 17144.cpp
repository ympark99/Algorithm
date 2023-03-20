#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, T;
int arr[51][51];
int add[51][51]; // 한번에 더해줄 배열
vector<int> cleaner;
int ans;

int dx[4] = {1, 0, -1, 0}; // 우 하 좌 상(시계)
int dy[4] = {0, 1, 0, -1};

void get_dust(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(arr[i][j] <= 0) continue;
            ans += arr[i][j];
        }
    }
}

void work_cleaner(int num){
    int row = cleaner[num];
    int idx = 0; // 방향 조절 idx

    pair<int, int> now = {row, 1};
    vector<pair<int, int>> endpoint;
    endpoint.push_back({row, C-1});
    endpoint.push_back({0, C-1});
    endpoint.push_back({R-1, C-1});
    endpoint.push_back({R-1, 0});
    endpoint.push_back({0, 0});

    int pre = 0, tmp = 0;
    while(now.second != 0 || now.first != row){
        tmp = arr[now.first][now.second];
        arr[now.first][now.second] = pre;
        pre = tmp;

        // 끝점이면 방향전환
        for(int i = 0; i < endpoint.size(); i++){
            if(now == endpoint[i])
                num == 0 ? idx = (idx + 3) % 4 : idx = (idx + 1) % 4;
        }

        now.second += dx[idx];
        now.first += dy[idx];
    }
}

void solution(int time){
    if(T == time){
        get_dust();
        return;
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(arr[i][j] <= 0) continue;

            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nrow = i + dy[k];
                int ncol = j + dx[k];

                if(nrow < 0 || nrow >= R || ncol < 0 || ncol >= C || arr[nrow][ncol] == -1) continue;

                cnt++;
                add[nrow][ncol] += (arr[i][j] / 5);
            }
            add[i][j] -= ((arr[i][j] / 5) * cnt);
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            arr[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }

    work_cleaner(0); // 위 작동
    work_cleaner(1); // 아래 작동

    solution(time+1);
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> T;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1)
                cleaner.push_back(i);
        }
    }
    solution(0);
    cout << ans << '\n';

    return 0;
}

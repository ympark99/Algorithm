#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int arr[101][101]; // 1 뱀 2 사과
int N, K, L;
int ans;
int dir_idx = 1; // 방향 상우하좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int row, col;
        cin >> row >> col;
        arr[row][col] = 2;
    }

    cin >> L;
    queue<pair<int, char>> time;
    for(int i = 0; i < L; i++){
        int X; char C;
        cin >> X >> C;
        time.push({X, C});
    }

    arr[1][1] = 1;    
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});

    while(1){
        ans++;
        int nRow = dq.back().first + dy[dir_idx];
        int nCol = dq.back().second + dx[dir_idx];
        if(nRow <= 0 || nRow > N || nCol <= 0 || nCol > N || arr[nRow][nCol] == 1) 
            break;

        if(arr[nRow][nCol] != 2){
            arr[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        arr[nRow][nCol] = 1;
        dq.push_back({nRow, nCol});

        if(ans == time.front().first){
            char ch = time.front().second;
            if(ch == 'D')
                dir_idx = (dir_idx + 1) % 4;
            else dir_idx = (dir_idx - 1 + 4) % 4;
            time.pop();
        }
    }
    cout << ans << '\n';
}

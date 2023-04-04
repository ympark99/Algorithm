#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, ans;
int arr[51][51];
// int cloud[51][51];
bool deletedCloud[51][51];
vector<pair<int, int>> nowCloud; // row, col
vector<pair<int, int>> order;
int dirX[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1}; // 2 4 6 8 대각선
int dirY[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void solution(int d, int s){
    vector<pair<int, int>> nextCloud;

    for(int i = 0; i < nowCloud.size(); i++){
        int nY = nowCloud[i].first + (dirY[d]) * s;
        int nX = nowCloud[i].second + (dirX[d]) * s;

        if(nY < 0) nY = (nY + N) % N;
        if(nY == 0) nY = N;
        if(nX < 0) nX = (nX + N) % N;
        if(nX == 0) nX == N;
        if(nY == N+1) nY = 0;
        if(nY >= N+1) nY %= N;
        if(nX == N+1) nX = 0;
        if(nX >= N+1) nX %= N;

        nextCloud.push_back({nY, nX});
        deletedCloud[nY][nX] = true;
    }

    for(auto elem : nextCloud)
        arr[elem.first][elem.second]++;
    
    // 물복사버그
    vector<int> increase(nextCloud.size());
    for(int i = 0; i < nextCloud.size(); i++){
        int cnt = 0;
        // 대각선 검사
        for(int j = 2; j <= 8; j+=2){
            int nY = nextCloud[i].first + dirY[j];
            int nX = nextCloud[i].second + dirX[j];

            if(nY == 0) nY = N;
            if(nX == 0) nX == N;
            if(nY == N+1) nY = 0;
            if(nX == N+1) nX = 0;

            if(arr[nY][nX]) 
                cnt++;
        }
        increase[i] = cnt;
    }
    for(int i = 0; i < increase.size(); i++)
        arr[nextCloud[i].first][nextCloud[i].second] += increase[i];
    
    nowCloud.clear();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(arr[i][j] >= 2 && !deletedCloud[i][j]){
                nowCloud.push_back({i, j});
                arr[i][j] -= 2;
            }
        }
    }
    memset(deletedCloud, false, sizeof(deletedCloud));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        int d, s;
        cin >> d >> s;
        order.push_back({d, s});
    }

    nowCloud.push_back({N, 1});
    nowCloud.push_back({N, 2});
    nowCloud.push_back({N-1, 1});
    nowCloud.push_back({N-1, 2});

    for(auto elem : order)
        solution(elem.first, elem.second);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            ans += arr[i][j];
    
    cout << ans << '\n';
    return 0;
}

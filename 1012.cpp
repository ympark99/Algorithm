#include <iostream>
#include <vector>

using namespace std;

bool arr[50 + 2][50 + 2] = {0, };

int answer = 0;

void dfs(int row, int col, bool isStart){ // isStart -> 맨 처음 0
    if(arr[col][row] == 0) return;
    else{
        arr[col][row] = 0;
        dfs(row, col - 1, 0);
        dfs(row, col + 1, 0);
        dfs(row - 1, col, 0);
        dfs(row + 1, col, 0);
        if(isStart) answer++;
    }

}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    
    while(T--){
        int M, N, K;
        cin >> M >> N >> K;

        //vector<vector<bool>> v(M, vector<bool>(N, 0));
        vector<pair<int, int>> v; // 배추 위치 저장 벡터

        for(int i = 0; i < K; i++){
            int row, col = 0;
            cin >> row >> col;
            v.push_back(make_pair(row + 1, col + 1));
            arr[col + 1][row + 1] = 1;
        }        

        for(int i = 0; i < v.size(); i++){
            dfs(v[i].first, v[i].second, 1);
        }

        cout << answer << '\n';
        answer = 0;
    }

    return 0;
}

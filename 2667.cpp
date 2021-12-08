#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool arr[25 + 2][25 + 2];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int cnt = 0;

void dfs(int i, int j){
    if(arr[i][j] == 0) return;

    if(arr[i][j] == 1){
        arr[i][j] = 0;
        cnt++;
        for(int k = 0; k < 4; k++) 
            dfs(i + dy[k], j + dx[k]);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> idx;
    vector<int> answer;

    int num = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num;
            if(num == 1) idx.push_back(make_pair(i, j));
            arr[i][j] = num;
        }
    }

    for(int i = 0; i < idx.size(); i++){
        cnt = 0;
        dfs(idx[i].first, idx[i].second);
        if(cnt > 0) answer.push_back(cnt);
    }

    if(!answer.empty()){
        cout << answer.size() << '\n';
        for(auto elem : answer) cout << elem << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N, S;
int answer;

void dfs(vector<int> v, int idx, int sum, int cnt, int size){
    sum += v[idx];
    cnt++;

    if(size == cnt){
        if(sum == S) answer++;
        return;
    }

    for(int i = idx + 1; i < N; i++)
        dfs(v, i, sum, cnt, size);
    
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> S;

    vector<int> v(N);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    for(int i = 1; i <= N; i++)
        for(int j = 0; j < N; j++)
            dfs(v, j, 0, 0, i);

    cout << answer;
}

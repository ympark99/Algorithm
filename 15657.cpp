#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int pre, int cnt, vector<int> ans){
    if(cnt == M){
        for(auto elem : ans)
            cout << elem << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        if(pre > v[i]) continue;
        ans.push_back(v[i]);
        dfs(v[i], cnt+1, ans);
        ans.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    v.resize(N);

    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> ans;
    dfs(0, 0, ans);
}

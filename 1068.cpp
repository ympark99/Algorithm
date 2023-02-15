#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root, del, leaf;
vector<int> v[51];

int dfs(int node){
    if(node == del)
        return -1;
    if(!v[node].size()){
        leaf++;
        return 0;
    }
    for(int i = 0; i < v[node].size(); i++){
        int tmp = dfs(v[node][i]);
        if(tmp == -1 && v[node].size() == 1)
            leaf++;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int num;
    int idx = 0;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == -1)
            root = i;
        else v[num].push_back(i);
    }
    cin >> del;
    dfs(root);

    cout << leaf << '\n';
}

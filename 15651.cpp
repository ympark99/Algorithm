#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int cnt, int n, int m, vector<int>v){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;         
    }
    for(int i=0; i<n; i++){
            v.push_back(i+1);
            dfs(cnt+1,n,m,v);
            v.pop_back();
        }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    vector<int> v;

    cin >> n >> m;
    dfs(0,n,m,v);
}

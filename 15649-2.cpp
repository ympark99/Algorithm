#include <iostream>
#include <vector>

using namespace std;

int n,m;
bool check[8] = {0,};
int arr[8];
vector<int> v(8);

void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!check[i]){
            check[i] = true;
            v[cnt] = i+1;
            dfs(cnt+1);
            check[i] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dfs(0);
}

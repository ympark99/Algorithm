#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
bool check[8] = {0,};
int arr[8];
bool return_check = 0;
vector<int> v;
vector<int> comp;

void dfs(int cnt){
    if(cnt == m){
        sort(comp.begin(),comp.end());
        for(int i=0; i<m; i++){
            if(comp[i] != v[i]) return_check = true;
            comp[i] = v[i];
        }
        if(return_check == true){ 
            return_check = false;
            return;
        }
        else{
            for(int i=0; i<m; i++){
                cout << v[i] << " ";
            }
            cout << "\n";
            return;
        }            
    }
    for(int i=0; i<n; i++){
        if(!check[i]){
            check[i] = true;
            v.push_back(i+1);
            comp.push_back(i+1);
            dfs(cnt+1);
            check[i] = false;
            v.pop_back();
            comp.pop_back();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dfs(0);
}

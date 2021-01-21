#include <iostream>

using namespace std;

int n,m;
int list[9];
bool check[9] = {0,};

void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m;i++){
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i <= n; i++){
        if(!check[i]){
            check[i] = true;
            list[cnt] = i;
            dfs(cnt + 1);
            check[i] = false;
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    dfs(0);

    return 0;
}

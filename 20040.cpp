#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[500000+1];
int ans;

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a == b) return true;
    else{
        parent[a] = b;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        if(unionParent(a, b)){
            ans = i;
            break;
        }
    }
    cout << ans;
}

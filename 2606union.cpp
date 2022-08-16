#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(101);

int find(int x){
    if(x == parent[x])
        return x;

    int y = find(parent[x]);
    parent[x] = y;
    return y;
}

void un(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y)
        parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, con;
    cin >> n;
    cin >> con;

    for(int i = 1; i <= n; i++)
        parent[i] = i;

    while(con--){
        pair<int, int> p;
        cin >> p.first >> p.second;
        un(p.first, p.second);
    }
    
    int cnt = 0;
    int root = find(1);

    for(int i = 2; i <= n; i++)
        if(find(i) == root)
            cnt++;

    cout << cnt;
}

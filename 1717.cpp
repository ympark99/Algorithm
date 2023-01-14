#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[1000000+1];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    // 작은 부모 노드 값으로 초기화
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) cout << "YES\n";
    else cout << "NO\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(!a)
            unionParent(b, c);
        else
            findParent(b, c);
    }
	return 0;
}

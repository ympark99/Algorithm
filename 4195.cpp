#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int parent[200000+1];
int fr_num[200000+1];
unordered_map<string, int> hashmap;

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a > b){
        parent[a] = b;
        fr_num[b] += fr_num[a];
    }
    else if(a < b){
        parent[b] = a;
        fr_num[a] += fr_num[b];
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        int F; cin >> F;
        int idx = 0;
        int idx_fr1 = 0, idx_fr2 = 0;
        for(int i = 0; i <= 200001; i++){
            parent[i] = i;
            fr_num[i] = 1;
        }

        string str1, str2;
        for(int i = 0; i < F; i++){
            string str1, str2;
            cin >> str1 >> str2;
            // map에 str1 없으면
            if(!hashmap.count(str1)){
                hashmap[str1] = ++idx;
                idx_fr1 = idx;
            }
            else
                idx_fr1 = hashmap[str1];
            
            if(!hashmap.count(str2)){
                hashmap[str2] = ++idx;
                idx_fr2 = idx;
            }
            else
                idx_fr2 = hashmap[str2];

            unionParent(idx_fr1, idx_fr2);
            int root = getParent(idx_fr1);
            cout << fr_num[root] << '\n';
        }
    }

    return 0;
}

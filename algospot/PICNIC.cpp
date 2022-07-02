#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v(m);
        for(int j = 0; j < m; j++){
            cin >> v[j].first >> v[j].second;
        }

    }

    return 0;
}

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]){
    int firstFree = -1;
    for(int i = 0; i < n; ++i){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = firstFree + 1; pairWith < n; ++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

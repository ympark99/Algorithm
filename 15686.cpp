#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[51][51];

void getComb(vector<pair<int, int>> store){
    do{
        /* code */
    }while (next_permutation(store.begin(), store.end()));
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> store; // 치킨집 위치 저장

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) store.push_back({i, j});
        }
    }
    
    getcomb(store);


    return 0;
}

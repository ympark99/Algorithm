#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int r, c, k;

int arr[101][101];
int numberCnt[101];
int timer;
int row = 3, col = 3;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> arr[i][j];
        }
    }
    while(arr[r][c] != k && timer <= 100){
        // R 연산
        if(row >= col){
            int nCol = 0;
            for(int i = 1; i <= row; i++){
                vector<pair<int, int>> v;
                memset(numberCnt, 0, sizeof(numberCnt));
                for(int j = 1; j <= col; j++) numberCnt[arr[i][j]]++;
                for(int j = 1; j < 101; j++)
                {
                    if (numberCnt[j] == 0) continue;
                    v.push_back(make_pair(numberCnt[j], j));
                }
                sort(v.begin(), v.end());
                for (int j = 1; j <= col; j++) arr[i][j] = 0;
                int idx = 1;
                for (int j = 0; j < v.size(); j++)
                {
                    arr[i][idx++] = v[j].second;
                    arr[i][idx++] = v[j].first;
                }
                nCol = max(nCol, --idx);
            }
            col = nCol;
        }
        // C 연산
        else{
            int nRow = 0;
            for(int i = 1; i <= col; i++){
                vector<pair<int, int>> v;
                memset(numberCnt, 0, sizeof(numberCnt));
                for(int j = 1; j <= row; j++) numberCnt[arr[j][i]]++;
                for(int j = 1; j < 101; j++){
                    if(numberCnt[j] != 0){
                        v.push_back(make_pair(numberCnt[j], j));
                    }
                }
                sort(v.begin(), v.end());
                for(int j = 1; j <= row; j++) 
                    arr[j][i] = 0;
                int idx = 1;
                for (int j = 0; j < v.size(); j++){
                    arr[idx++][i] = v[j].second;
                    arr[idx++][i] = v[j].first;
                }
                nRow = max(nRow, --idx);
            }
            row = nRow;
        }
        timer++;
    }

    if(arr[r][c] != k)
        cout << -1 << '\n';
    else cout << timer << '\n';

    return 0;
}

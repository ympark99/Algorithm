#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

char arr[100+1][100+1];
bool check[100+1][100+1] = {false, };
char nowCh;
int N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int row, int col, bool rg){
    if(!rg && arr[row][col] != nowCh)
        return;
    if(rg && (nowCh != 'B' && arr[row][col] == 'B'))
            return;
    else if(rg && (nowCh == 'B' && arr[row][col] != 'B'))
            return;
    
    check[row][col] = true;
    for(int i = 0; i < 4; i++){
        int nRow = row + dx[i];
        int nCol = col + dy[i];
        if(nRow > N || nCol > N || nRow < 1 || nCol < 1)
            continue;
        if(!check[nRow][nCol])
            dfs(nRow, nCol, rg);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int cnt1 = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!check[i][j]){
                nowCh = arr[i][j];
                cnt1++;
                dfs(i, j, false);
            }
        }
    }

    int cnt2 = 0;
    memset(check, false, sizeof(check));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!check[i][j]){
                nowCh = arr[i][j];
                cnt2++;
                dfs(i, j, true);
            }
        }
    }

    cout << cnt1 << " " << cnt2 << '\n';
}

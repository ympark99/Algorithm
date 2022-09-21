#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, x, y, K;
int arr[20][20];
int dice[3][3] = {0, };

// -1 2 -1 
// 4 1 3
// -1 5 6

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    int order = 0;
    int row = x;
    int col = y;
    bool flag = true;
    for(int i = 0; i < K; i++){
        flag = true;
        cin >> order;
        int tmp = dice[2][2];
        switch (order){
            case 1:
                if(col+1 >= M){
                    flag = false;
                    break;
                }
                col += 1;
                dice[2][2] = dice[1][2];
                dice[1][2] = dice[1][1];
                dice[1][1] = dice[1][0];
                dice[1][0] = tmp;
                break;
            case 2:
                if(col-1 < 0){
                    flag = false;
                    break;
                }
                col -= 1;
                dice[2][2] = dice[1][0];
                dice[1][0] = dice[1][1];
                dice[1][1] = dice[1][2];
                dice[1][2] = tmp;
                break;
            case 3:
                if(row-1 < 0){
                    flag = false;
                    break;
                }
                row -= 1;
                dice[2][2] = dice[0][1];
                dice[0][1] = dice[1][1];
                dice[1][1] = dice[2][1];
                dice[2][1] = tmp;
                break;
            case 4:
                if(row+1 >= N){
                    flag = false;
                    break;
                }
                row += 1;
                dice[2][2] = dice[2][1];
                dice[2][1] = dice[1][1];
                dice[1][1] = dice[0][1];
                dice[0][1] = tmp;
                break;                                                
        }

        if(flag) cout << dice[1][1] << '\n';

        if(!arr[row][col])
            arr[row][col] = dice[2][2];
        else dice[2][2] = arr[row][col];
    }
    return 0;
}

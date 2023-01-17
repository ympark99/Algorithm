#include <bits/stdc++.h>

using namespace std;

char arr1[50][50];
char arr2[50][50];
int cnt;

void reverse(int row, int col){
    for(int i = row; i < row+3; i++){
        for(int j = col; j < col+3; j++){
            arr1[i][j] = (arr1[i][j] == '1' ? '0' : '1');
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr1[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr2[i][j];

    for(int i = 0; i < N-2; i++){
        for(int j = 0; j < M-2; j++){
            if(arr1[i][j] != arr2[i][j]){
                reverse(i, j);
                cnt++;
            }
        }
    }

    bool flag = false;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(arr1[i][j] != arr2[i][j])
                flag = true;

    if(flag) cout << -1 << '\n';
    else cout << cnt << '\n';
	return 0;
}

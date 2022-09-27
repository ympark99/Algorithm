#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
int arr[500+1][500+1];
int ans;

void solution(int idx){
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < W; i++){
        if(arr[idx][i] == 1){
            if(flag){
                ans += cnt;
                cnt = 0;
            }
            flag = true;
        }
        else{
            if(flag) cnt++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> H >> W;

    int num;
    for(int i = 0; i < W; i++){
        cin >> num;
        for(int j = 1; j <= num; j++)
            arr[H - j][i] = 1;
    }

    for(int i = 0; i < H; i++)
        solution(i);

    cout << ans << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
vector<int> player(10);
int arr[50][9];
int ans = -1;
bool check[10];
bool diamond[4];

// 2
// 3456789
// 456789

void cal(){
    int outCnt = 0, inning = 1;
    int score = 0, idx = 1;

    while(inning <= N){
        if(idx > 9) idx %= 9;

        int num = arr[inning][player[idx]];

        if(!num)
            outCnt++;        
        else if(num == 1){
            if(diamond[3]){
                score++;
                diamond[3] = false;
            }
            for(int i = 2; i >= 1; i--){
                if(diamond[i]){
                    diamond[i+1] = true;
                    diamond[i] = false;
                }
            }
            diamond[1] = true;
        }
        else if(num == 2){
            if(diamond[3]){
                score++;
                diamond[3] = false;
            }
            if(diamond[2]){
                score++;
                diamond[2] = false;
            }                        
            if(diamond[1]){
                diamond[3] = true;
                diamond[1] = false;
            }            
            diamond[2] = true;
        }
        else if(num == 3){
            for(auto elem : diamond){
                if(elem) score++;
                elem = false;
            }
            diamond[3] = true;
        }
        else if(num == 4){
            for(auto elem : diamond){
                if(elem) score++;
                elem = false;
            }
            score++;
        }
        if(outCnt == 3){
            outCnt = 0;
            inning++;
        }
        idx++;
    }
    ans = max(ans, score);
    return;
}

void dfs(int level){
    if(level == 4)
        level++;

    if(level == 9+1){
        cal();
        return;
    }

    for(int i = 2; i <= 9; i++){
        if(check[i]) continue;
        check[i] = true;
        player[level] = i;
        dfs(level+1);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    player[4] = 1;
    check[1] = true;
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 9; j++){
            cin >> arr[i][j];
        }
    }

    dfs(1);
    cout << ans << '\n';

    return 0;
}

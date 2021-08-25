#include <iostream>
#include <math.h>

using namespace std;

const int MN = 3*3*3*3*3*3*3 + 1;

int arr[MN][MN] = {0, };

int ans[3+1] = {0,};

void div(int x, int y, int n){
    int comp = arr[y][x];
    bool next = false;
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(comp != arr[i][j]){
                next = true;
                break;
            }
        }
        if(next) break;
    }

    if(next){
        for(int i = y; i < y + n; i += n / 3){
            for(int j = x; j < x + n; j += n / 3){
                div(j, i, n / 3);
            }
        }        
    }
    else ans[comp + 2]++;

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    div(1, 1, n);

    cout << ans[1] << '\n' << ans[2] << '\n' << ans[3];
}

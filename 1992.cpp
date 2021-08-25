#include <iostream>
#include <string>

using namespace std;

const int MN = 64 + 1;

char arr[MN][MN];
string ans = "";

void div(int x, int y, int n){
    char comp = arr[y][x];
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
        ans += '(';
        for(int i = y; i < y + n; i += n / 2){
            for(int j = x; j < x + n; j += n / 2){
                div(j, i, n / 2);
            }
        }
        ans += ')';  
    }
    else{
        ans += comp;
    }
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

    cout << ans;
}

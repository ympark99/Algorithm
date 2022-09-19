#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
queue<pair<int, int>> q;
int event[100+1] = {0, };
bool check[100+1] = {false, };

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        event[a] = b;
    }
    
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        event[a] = b;
    }

    q.push({1, 0});
    while (!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i = 1; i <= 6; i++){
            int next = now + i;
            if(next == 100){
                cout << cnt+1;
                return 0;
            }
            if(event[next])
                next = event[next];
            if(!check[next]){
                q.push({next, cnt+1});
                check[next] = true;
            }
        }
    }
}

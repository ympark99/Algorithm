#include <iostream>
#include <queue>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    int sum = 0;
    queue<int> q;

    for(int i = M; i <= N; i++){
        if(i == 1) continue;
        else if(i == 2){
            sum += i;
            q.push(i);
            continue;
        }
        else{
            bool check = true;
            for(int j = 2; j < i; j++){
                if(i % j == 0){
                    check = false;
                    break;
                }
            }
            if(check){
                sum += i;
                q.push(i);
            }
        }
    }
    if(q.empty()) cout << -1;
    else cout << sum << '\n' << q.front();
}

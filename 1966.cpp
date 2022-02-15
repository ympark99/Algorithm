#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int T; cin >> T;

    while (T--){
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q; // key, value
        priority_queue<int> pq;

        int num = 0;
        for(int i = 0; i < N; i++){
            cin >> num;
            q.push(make_pair(i, num));
            pq.push(num);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int key = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                cnt++;
                if(q.front().first == M){
                    cout << cnt << '\n';
                    break;
                }
            }
            else q.push(make_pair(key, value));
        }
    }    
}

#include <iostream>
#include <queue>

using namespace std;

struct comp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        else return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    priority_queue<int, vector<int>, comp> pq;

    while (N--){
        int num; cin >> num;
        if(!num && pq.empty()) cout << 0 << '\n';
        else if(!num){
            cout << pq.top() << '\n';
            pq.pop();
        }
        else pq.push(num);
    }
}

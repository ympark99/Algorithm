#include <string>
#include <vector>
#include <queue>

using namespace std;

int ans = -1;
bool check[1000001];

void bfs(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        check[now] = true;
        q.pop();
        
        if(now == y) {
            ans = cnt;
            break;
        }
        
        if(now + n <= y && !check[now + n]) {
            check[now + n] = true;
            q.push({now + n, cnt+1});   
        }
        if(now * 2 <= y && !check[now * 2]) {
            check[now * 2] = true;
            q.push({now * 2, cnt+1});   
        }
        if(now * 3 <= y && !check[now * 3]) {
            check[now * 3] = true; 
            q.push({now * 3, cnt+1});   
        }
    }
}

int solution(int x, int y, int n) {   
    bfs(x, y, n);
    
    return ans;
}

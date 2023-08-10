#include <bits/stdc++.h>
 
using namespace std;

int F, start, target, U, D;
bool checked;

void bfs() {
    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<bool> visited(F+1, false);

    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        visited[now] = true;
        q.pop();

        if(now == target) {
            cout << cnt << '\n';
            checked = true;
            return;
        }

        if(now + U <= F && !visited[now + U]) {
            visited[now + U] = true;
            q.push({now + U, cnt+1});
        }

        if(now - D > 0 && !visited[now - D]) {
            visited[now - D] = true;
            q.push({now - D, cnt+1});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    cin >> F >> start >> target >> U >> D;

    bfs();

    if(!checked)
        cout << "use the stairs\n";

    return 0;
}

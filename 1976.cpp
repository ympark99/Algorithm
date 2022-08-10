#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, x;
int city[201][201];
bool visit[201];
bool flag;
vector<int> check_list;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> city[i][j];

    for (int i = 1; i <= M; i++){
        cin >> x;
        check_list.push_back(x);
    }

    q.push(check_list[0]);

    while (!q.empty()){
        int now = q.front();
        q.pop();

        visit[now] = true;

        for (int i = 1; i <= N; i++){
            // 갈수있고 방문한적이없는 도시라면
            if (city[now][i] == 1 && !visit[i])
                q.push(i);
        }
    }

    flag = true;

    for (int i = 0; i < check_list.size(); i++){
        if (!visit[check_list[i]]){
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO");
}

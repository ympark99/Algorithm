#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[8 + 1];
bool check[8 + 1] = {false, };
int ans = 0;

void dfs(int pre, int now, int cnt, int sum){
    if(cnt == N+1){
        ans = max(ans, sum);
        return;
    }

    if(!check[now]){
        check[now] = true;
        if(pre != now)
            sum += abs(arr[pre] - arr[now]);
        for(int i = 1; i <= N; i++){
            dfs(now, i, cnt + 1, sum);
        }
        check[now] = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = 1; i <= N; i++)
        dfs(i, i, 1, 0);

    cout << ans;
}

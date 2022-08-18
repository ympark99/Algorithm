#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 9

int N,M;
int first[MAX];
int arr[MAX];
bool visited[MAX];

void dfs(int num, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }else {
        for(int i = 1; i <= N; i++){
            if(!visited[i]) {
                visited[i]=true;
                arr[cnt] = first[i-1];
                dfs(i + 1, cnt + 1);
                visited[i]=false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> first[i];
    
    sort(first, first+N);

    dfs(1,0);
}

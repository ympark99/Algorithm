#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    for(int i = 1; i <= N; i++)
        v.push_back(i);

    do{
        for(auto elem : v){
            cout << elem << ' ';
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));   
}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int visited[8+1] = {false, };
bool flag = false;

void dfs(int cnt, vector<int> v){
    if(cnt == N){
        for(int i = 0; i < cnt; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            v[cnt] = i;
            dfs(cnt+1, v);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    vector<int> v(N);
    dfs(0, v);
}
*/

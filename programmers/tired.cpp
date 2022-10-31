#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] >= b[1];
    return a[0] > b[0];
}

int arr[1000+1];
int ans;

void dfs(vector<vector<int>> dungeons, vector<bool> check, int hp, int cnt){
    if(cnt > ans) ans = cnt;
    
    for(int i = 0; i < dungeons.size(); i++){
        if(check[i] || hp < dungeons[i][0]) continue;
        check[i] = true;
        dfs(dungeons, check, hp - dungeons[i][1], cnt+1);
        check[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end(), comp);
    vector<bool> check(8+1, false);
    
    for(int i = 0; i < dungeons.size(); i++){
        if(dungeons[i][0] > k) continue;
        check[i] = true;
        dfs(dungeons, check, k - dungeons[i][1], 1);
        check[i] = false;
    }
    return ans;
}

#include <bits/stdc++.h>

using namespace std;

int cnt, groupCnt;
bool check[100+1];
bool arr[100+1][100+1];
int nums[2];

void dfs(int start, int n){
    check[start] = true;
    nums[groupCnt]++;
    for(int i = 1; i <= n; i++)
        if(arr[start][i] && !check[i])
            dfs(i, n);
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 987654321;
    for(int i = 0; i < wires.size(); i++){
        arr[wires[i][0]][wires[i][1]] = true;
        arr[wires[i][1]][wires[i][0]] = true;
    }
    
    for(int i = 0; i < wires.size(); i++){
        arr[wires[i][0]][wires[i][1]] = false;
        arr[wires[i][1]][wires[i][0]] = false;    
        for(int j = 1; j <= n; j++){
            if(check[j]) continue;
            dfs(j, n);
            groupCnt++;
        }
        arr[wires[i][0]][wires[i][1]] = true;
        arr[wires[i][1]][wires[i][0]] = true;    
        
        if(groupCnt == 2)
            ans = min(ans, abs(nums[1] - nums[0]));
        
        groupCnt = 0;
        nums[0] = nums[1] = 0;
        memset(check, false, sizeof(check));
    }    
    return ans;
}

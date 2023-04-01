#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct rotation{
    int r;
    int c;
    int s;
};

int N, M, K;
int ans = 87654321;
int arr[51][51];
int tmp_arr[51][51];
vector<rotation> v;
bool check[6+1];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void rotate(rotation ro){
    memmove(tmp_arr, arr, sizeof(arr));

    for (int s = 1; s <= ro.s; s++){
		//오른쪽 위부터 시계방향으로
		int temp = tmp_arr[ro.r - s][ro.c + s];
 
		for (int j = ro.c + s; j > ro.c - s; j--)
			tmp_arr[ro.r - s][j] = tmp_arr[ro.r - s][j - 1];
 
		for (int i = ro.r - s; i < ro.r + s; i++)
			tmp_arr[i][ro.c - s] = tmp_arr[i + 1][ro.c - s];
 
		for (int j = ro.c - s; j < ro.c + s; j++)
			tmp_arr[ro.r + s][j] = tmp_arr[ro.r + s][j + 1];
 
		for (int i = ro.r + s; i > ro.r - s; i--)
			tmp_arr[i][ro.c + s] = tmp_arr[i - 1][ro.c + s];
 
		tmp_arr[ro.r - s + 1][ro.c + s] = temp;
	}
    
    return;
}

void solution(vector<rotation> cur){
    for(int i = 0; i < cur.size(); i++){
        rotation ro = cur[i];
        rotate(ro);
    }
    // 최솟값 구하기
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= M; j++){
            sum += tmp_arr[i][j];
        }
        ans = min(ans, sum);
    }
    return;
}

void dfs(vector<rotation> cur){
    if(cur.size() == v.size()){
        memmove(tmp_arr, arr, sizeof(arr));
        solution(cur);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        if(check[i]) continue;
        check[i] = true;
        cur.push_back(v[i]);
        dfs(cur);
        cur.pop_back();
        check[i] = false;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }
    vector<rotation> cur;
    dfs(cur);
    cout << ans << '\n';
    return 0;
}

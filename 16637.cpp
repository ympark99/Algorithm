#include <iostream>
#include <string>

using namespace std;

int N;
int ans = -987654321;
string str;

int cal(int a, int b, char ch){
	int num = a;
	switch (ch){
        case '+': num += b; break;
        case '*': num *= b; break;
        case '-': num -= b; break;
	}
	return num;
}

void dfs(int idx, int now){
    if(idx > N-1){
        ans = max(ans, now);
        return;
    }
    char ch = (idx == 0)? '+' : str[idx-1]; // 처음에는 0부터 더하므로

    // 괄호 묶을때(이전 + 괄호)
    if(idx + 2 < N){
        int bracket = cal(str[idx] - '0', str[idx+2] - '0', str[idx+1]);
        dfs(idx + 4, cal(now, bracket, ch));
    }
    dfs(idx + 2, cal(now, str[idx] - '0', ch)); // 괄호 안묶을때(이전 + 다음)
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> str;

    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}

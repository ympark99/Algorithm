#include <bits/stdc++.h>

using namespace std;

int arr[100000+1];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, S;
    cin >> N >> S;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    int start = 1, end = 1;
    int sum = arr[1];
    int ans = INT_MAX;
    while(start <= end && end <= N){
        if(sum >= S) ans = min(ans, end-start+1);
        if(sum < S){
            end++;
            sum += arr[end]; 
        }else{
            sum -= arr[start];
            start++;
        }
    }
    if(ans == INT_MAX) cout << 0 << '\n';
    else cout << ans << '\n';
	return 0;
}

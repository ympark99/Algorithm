#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    for(int i = 1; i <= N; i++) 
        cin >> arr[i];

    int start = 1;
    int end = 1;
    int sum = arr[1];
    int ans = 987654321;

    while(start <= end && end <= N){
        if(sum >= S) ans = min(ans, (end - start + 1));
        if(sum < S) {
            end++; 
            sum += arr[end];
        } else {
            sum -= arr[start];
            start++;
        }
    }

    if(ans == 987654321) cout << 0;
    else cout << ans;
}

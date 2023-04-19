#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
int top[500001];
int bottom[500001];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> H;
	int h;

	for(int i = 0; i < N; i++){
		cin >> h;
		if(i % 2 == 0)
			bottom[h]++;
		else top[H - h + 1]++;
	}

    for(int i = 1; i <= H; i++){
        top[i] += top[i-1];
        bottom[H-i] += bottom[H-i+1];
    }
    
    long long ans = 9876543231;
    int cnt = 0;
    for(int i = 1; i <= H; i++){
        if(top[i] + bottom[i] < ans){
            cnt = 1;
            ans = top[i] + bottom[i];
        }
        else if(top[i] + bottom[i] == ans){
            cnt++;
        }
    }    
    cout << ans << " " << cnt;

	return 0;
}

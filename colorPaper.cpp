#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int arr[100+1][100+1];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while(T--){
		int ans = 0;
		int N; cin >> N;
		for(int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			for(int j = a; j < a+10; j++){
				for(int k = b; k < b+10; k++){
					arr[j][k]++;
					if(arr[j][k] == 1)
						ans++;
				}
			}
		}
		memset(arr, 0, sizeof(arr));
		cout << ans << '\n';
	}
	
  return 0;
}

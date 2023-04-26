#include <iostream>
#include <vector>

using namespace std;

int arr[11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, left;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> left;
        for(int j = 0; j < N; j++){
            if(left == 0 && arr[j] == 0){ //만약 자기앞에 아무도 없고 빈자리라면 
                arr[j] = i+1; //착석한다.
                break;
            }
            else if(arr[j] == 0)
				left--;
        }
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }

	return 0;
}

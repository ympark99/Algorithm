#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000 + 1];
int dp_up[1000 + 1] = {0, };
int dp_down[1000 + 1] = {0, };

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int res_up, res_down = 0;
    int idx_up, idx_down = 0;

    for(int i = 0; i < n; i++){
        dp_up[i] = 1;
        dp_down[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j])
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            else if(arr[i] < arr[j])
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);                
        }

        res_up = max(res_up, dp_up[i]);
        res_down = max(res_down, dp_down[i]);
    }

    cout << res_up;

    return 0;
}

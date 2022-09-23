#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> wifi;

int solution(int N, int C){
    int l_dist = 0; // 1-> 1
    int r_dist = wifi[N-1] - 1; // 1-> N 간격

    int ans = 0;

    while (l_dist <= r_dist){
        int wifi_cnt = 1;
        int mid = (l_dist + r_dist) / 2;
        int start = wifi[0];

        for(int i = 1; i < N; i++){
            int end = wifi[i];

            if(end - start >= mid){
                wifi_cnt++;
                start = end;
            }
        }

        if(wifi_cnt >= C){
            ans = mid;
            l_dist = mid + 1;
        }
        else{
            r_dist = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    int loc;
    for(int i = 0; i < N; i++){
        cin >> loc;
        wifi.push_back(loc);
    }
    sort(wifi.begin(), wifi.end());

    cout << solution(N, C);

    return 0;
}2110.CP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> router;

int solution(int N, int C){
    int dist_left = 0;
    int dist_right = router[N-1] - 1;
    
    int ans = 0;

    while (dist_left <= dist_right){
        int cnt = 1;
        int mid = (dist_left + dist_right) / 2;
        int start = router[0];

        for(int i = 1; i < N; i++){
            int end = router[i];
            if(end - start >= mid){
                cnt++;
                start = end;
            }
        }
        // 많이 나왔을때
        if(cnt >= C){
            ans = mid;
            dist_left = mid + 1;
        }
        else dist_right = mid - 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        router.push_back(num);
    }

    sort(router.begin(), router.end());

    cout << solution(N, C);

    return 0;
}

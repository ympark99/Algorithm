#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int sensor[10000+1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> sensor[i];
    }
    sort(sensor, sensor+N);

    vector<int> dist(N-1, 0);

    for(int i = 0; i < N-1; i++)
        dist[i] = sensor[i+1] - sensor[i];

    sort(dist.begin(), dist.end());

    int ans = 0;
    
    for(int i = 0; i < N-K; i++){
        ans += dist[i];
    }

    cout << ans;
}

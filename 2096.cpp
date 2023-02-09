#include <iostream>
#include <algorithm>

using namespace std;

int mindp[3];
int maxdp[3];
int input[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    cin >> mindp[0] >> mindp[1] >> mindp[2];
    maxdp[0] = mindp[0];
    maxdp[1] = mindp[1];
    maxdp[2] = mindp[2];

    for(int i = 1; i < N; i++){
        cin >> input[0] >> input[1] >> input[2];

        int tmp_0 = maxdp[0], tmp_2 = maxdp[2];
        maxdp[0] = max(maxdp[0], maxdp[1]) + input[0];
        maxdp[2] = max(maxdp[1], maxdp[2]) + input[2];
        maxdp[1] = max(max(tmp_0, maxdp[1]), tmp_2) + input[1];

        tmp_0 = mindp[0], tmp_2 = mindp[2];
        mindp[0] = min(mindp[0], mindp[1]) + input[0];
        mindp[2] = min(mindp[1], mindp[2]) + input[2];
        mindp[1] = min(min(tmp_0, mindp[1]), tmp_2) + input[1];
    }

    cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << " " << min(min(mindp[0], mindp[1]), mindp[2]) << '\n';
}

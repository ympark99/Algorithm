#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<int> crane(N);
    for(int i = 0; i < N; i++)
        cin >> crane[i];
    sort(crane.begin(), crane.end(), greater<int>());
    cin >> M;
    vector<int> box(M);
    for(int i = 0; i < M; i++)
        cin >> box[i];
    sort(box.begin(), box.end(), greater<int>());

    if(box[0] > crane[0]){
        cout << -1 << '\n';
        return 0;
    }
    while(!box.empty()){
        ans++;
        for(int i = 0; i < crane.size(); i++){
            for(int j = 0; j < box.size(); j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
	return 0;
}

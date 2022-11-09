#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> v(N);
    vector<bool> check(N, true);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            if(v[j].substr(0, v[i].size()) == v[i]){
                check[i] = false;
                break;
            }
        }
    }

    int cnt = 0;
    for(auto elem : check)
        if(elem) cnt++;

    cout << cnt << '\n';  
    return 0;
}

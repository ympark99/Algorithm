#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    int num;
    while(n--){
       cin >> num;
       v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<int>());
    
    int answer = 0;
    for(int i = 1; i < v.size(); i++){
        answer += (v[i] + v[0]);
    }

    cout << answer;

    return 0;
}

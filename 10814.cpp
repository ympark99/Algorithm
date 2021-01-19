#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

bool compare(pair<int,string>v1, pair<int,string>v2){
    return v1.first < v2.first;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int,string>> v(n);
    

    for(int i = 0 ; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(),v.end(),compare);


    for(int i = 0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}

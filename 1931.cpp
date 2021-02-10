#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
   if(a.second == b.second){
       return a.first < b.first;
   }
   else{
       return a.second < b.second;
   }
}

int main(void){
    int n;
    cin >> n;

    vector<pair<int,int>> v;    

    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),comp);

    int now = v[0].second;
    int cnt = 1;
    for(int i=0; i<n;i++){
        if(now <= v[i].first){
            cnt++;
            now = v[i].second;
        }
    }
    cout << cnt;
}

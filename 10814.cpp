#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(pair<int,string> a, pair<int,string> b){
   return a.first < b.first;
}

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N;
   cin >> N;
   vector<pair<int,string>> v(N);
   for(int i = 0; i < N; i++){
      cin >> v[i].first >> v[i].second;
   }
   stable_sort(v.begin(), v.end(), comp);
   for(auto elem : v) cout << elem.first << " " << elem.second << '\n';
}

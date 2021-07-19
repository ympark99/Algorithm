#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);

   vector<string> v_str;

   string str;
   cin >> str;

   while(!str.empty()){
      v_str.push_back(str);
      str.erase(0,1);
   }

   sort(v_str.begin(), v_str.end());

   for(auto elem : v_str) cout << elem << '\n';
   
}

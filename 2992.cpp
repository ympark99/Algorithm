#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);

   string str;
   cin >> str;

   bool check = next_permutation(str.begin(), str.end());

   if(check) cout << str;
   else cout << '0';  
}

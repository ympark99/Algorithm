#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);
   int T;
   cin >> T;

   for(int i = 0; i < T; i++){
      string str;
      stack<char> st;
      cin >> str;
      bool isNO = false;
      for(int j = 0; j < str.size(); j++){
         if(str[j] == ')'){ 
            if(st.empty()){
               isNO = true;
               break;
            }
            else st.pop();
         }
         else st.push('(');
      }
      if(isNO == true) cout << "NO" << '\n';
      else if(!st.empty()) cout << "NO" << '\n';
      else cout << "YES" << '\n';
   }
}

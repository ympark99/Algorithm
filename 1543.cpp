#include <iostream>
#include <string>

using namespace std;

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);

   string str, search;

   getline(cin, str);
   getline(cin, search);
   
   if(search.length() > str.length()){
      cout << 0;
      return 0;
   }

   int answer = 0;

   for(int i = 0; i < str.length() - search.length();){
      bool check = true;
      for(int j = 0; j < search.length(); j++){
         if(str[i + j] != search[j]){
            check = false;
            break;
         }
      }
      if(check){
         answer++;
         i += search.length();
      }
      else i++;
   }
   
   cout << answer;
}

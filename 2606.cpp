#include <iostream>

using namespace std;

int com[101][101] = {0,};
int visited[101] = {0,};
int cnt = 0;

void dfs(int start, int num){
   visited[start] = 1;
   cnt++;

   for(int i=1; i <= num; i++){
      if(com[start][i] == 1 && visited[i] == 0){
         dfs(i, num);
      }
   }
}

int main(void) {
   ios_base::sync_with_stdio(false); cin.tie(NULL);

   int num, pair;
   cin >> num >> pair;

   for(int i=0; i < pair; i++){
      int a,b;
      cin >> a >> b;
      com[a][b] = 1;
      com[b][a] = 1;
   }

   dfs(1,num);
   cout << cnt-1;
   return 0;
}

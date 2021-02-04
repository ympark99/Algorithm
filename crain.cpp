#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for(int i=0; i<moves.size(); i++){
        int cnt=0;
        while(cnt < board.size()){
            if(board[cnt][moves[i]-1] != 0){
                if(!st.empty()){
                    if(st.top() == board[cnt][moves[i]-1]){
                        st.pop();
                        answer += 2;
                        board[cnt][moves[i]-1] = 0;
                        break;
                    }
                }
                st.push(board[cnt][moves[i]-1]);
                board[cnt][moves[i]-1] = 0;
                break;
            }
            else cnt++;
        }        
    }    
    
    return answer;
}

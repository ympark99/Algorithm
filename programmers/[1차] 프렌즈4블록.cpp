#include <string>
#include <vector>
#include <string.h>

using namespace std;

int ans;
bool check[31][31];

bool is_score(int m, int n, int row, int col, vector<string> board) {
    if(row + 1 == m || col + 1 == n) 
        return false;
    
    char pre = board[row][col];
    if(board[row+1][col] != pre || board[row][col+1] != pre || board[row+1][col+1] != pre) {
        return false;
    }
    
    check[row][col] = true;
    check[row+1][col] = true;
    check[row][col+1] = true;
    check[row+1][col+1] = true;
    
    return true;
}

void apply_check(int m, int n, vector<string> &board) {   
    // 체크 적용
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            if(check[i][j]) {
                ans++;
                // 위에서 땡겨옴
                for(int k = i; k > 0; k--) {
                    board[k][j] = board[k-1][j];
                    board[k-1][j] = 'X';
                }
            }
        }
    }
    memset(check, false, sizeof(check));
}

void check_board(int m, int n, vector<string> board) {
    bool check_next = false;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'X') continue;
            if(is_score(m, n, i, j, board)) {
                check_next = true;
            }
        }
    }
    if(!check_next) return;
    else {
        apply_check(m, n, board);
        check_board(m, n, board);
    }
}

int solution(int m, int n, vector<string> board) {
    
    check_board(m, n, board);
    
    return ans;
}

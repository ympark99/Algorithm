#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n+1, vector<int>(m+1, 1));

    for(int i = 0; i < puddles.size(); i++) {
        int y = puddles[i][1];
        int x = puddles[i][0];
        
        board[y][x] = 0;

        if(x == 1) {
            for(int j = y; j <=n; j++)
                board[j][1] = 0;
        }

        if(y == 1) {
            for(int j = x; j <= m; j++)
                board[1][j] = 0;
        }
    }


    for(int y = 2; y <= n; y++) {
        for(int x = 2; x <= m; x++) {
            if(board[y][x] == 0)
                continue;

            board[y][x] = (board[y-1][x] + board[y][x-1]) % 1000000007;
        }
    }

    return board[n][m];
}

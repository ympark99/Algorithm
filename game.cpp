#include <iostream>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    return 0;
}

bool hasWord(int y, int x, const string &word){
    if(!inRange(y, x)) return false; // 시작 위치 범위 밖

    if(board[y][x] != word[0]) return false; // 첫 글자 실패

    if(word.size() == 1) return true; // 단어 길이1

    for(int direction = 0; direction < 8; ++direction){
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if(hasWord(nextY, nextX, word.substr(1))) return true;
    }
    return false;
}

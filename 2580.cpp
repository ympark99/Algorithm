#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int arr[9][9];
vector<pair<int, int>> loc;
int cnt = 0;
bool found = false;
bool check(pair<int, int> p){
    int square_x = p.first / 3; 
    int square_y = p.second / 3;
    for(int i = 0; i < 9; i++){
        if(arr[p.first][i] == arr[p.first][p.second] && i != p.second) 
            return false;
        if(arr[i][p.second] == arr[p.first][p.second] && i != p.first)
            return false;
    }
    for(int i = 3*square_x; i < 3*square_x+3; i++)
        for(int j = 3*square_y; j < 3*square_y+3; j++){
            if(arr[i][j] == arr[p.first][p.second]){
                if(i != p.first && j != p.second)
                    return false;
            }
        }
    return true;
}
void sudoku(int N){
    if(N == cnt){
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
        found = true;
        return;
    }
        for(int j = 1; j <= 9; j++){
            arr[loc[N].first][loc[N].second] = j;
            if(check(loc[N]))
                sudoku(N+1);
            if(found)
                return;
        }
    arr[loc[N].first][loc[N].second] = 0;
    return;
}
int main() {
    pair<int, int> point;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                cnt++;
                point.first = i;
                point.second = j;
                loc.push_back(point);
            }
        }
    sudoku(0);
}

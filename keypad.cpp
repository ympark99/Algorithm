#include <string>
#include <vector>
#include <math.h>

using namespace std;

int calc(int mid, int num){
    int row_mid = (mid-1) / 3;
    int col_mid = (mid-1) % 3;
    int row_num = (num-1) / 3;
    int col_num = (num-1) % 3;

    return abs(row_mid - row_num) + abs(col_mid - col_num);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    for(int i=0; i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = numbers[i];
        }
        else{
            if(numbers[i] == 0) numbers[i] = 11;
            if(calc(numbers[i],left) == calc(numbers[i],right)){
                if(hand.compare("left")){
                    answer += "R";
                    right = numbers[i];
                }
                else if(hand.compare("right")){
                    answer += "L";
                    left = numbers[i];
                }                
            }
            else if(calc(numbers[i],left) < calc(numbers[i],right)){
                answer += "L";
                left = numbers[i];                
            }
            else if(calc(numbers[i],left) > calc(numbers[i],right)){
                answer += "R";
                right = numbers[i];                
            }            
        }
    }
    return answer;
}

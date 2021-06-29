#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;

        if(num == 1) continue;
        else if(num == 2){
            answer++;
            continue;
        }
        else{
            bool check = true;
            for(int j = 2; j < num; j++){
                if(num % j == 0){
                    check = false;
                    break;
                }
            }
            check == true? answer++ : NULL;
        }
    }
    cout << answer;
}

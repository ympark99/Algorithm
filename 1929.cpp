#include <iostream>
#define MAX 1000001

using namespace std;

int main(){
    bool check[MAX] = {false,};
    int M, N;
    cin >> M >> N;

    for(int i = M; i <= N; i++){
        if(check[i]) continue;
        if(i == 1) continue;
        else if(i == 2){
            cout << i << '\n';
            int num = 1;
            while (i * num <= N){
                check[i * num] = true;
                num++;
            }
        }
        else{
            bool isTrue = true;
            for(int j = 2; j < i; j++){
                if(check[j]) continue;
                if(i % j == 0) isTrue = false;
            }
            if(isTrue){
                cout << i << '\n';
                int num = 1;
                while (i * num <= N){
                    check[i * num] = true;
                    num++;
                }              
            }
        }
    }
}

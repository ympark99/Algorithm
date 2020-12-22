#include <iostream>

using namespace std;

int main(void){
    int n;
    int res;
    cin >> n;

    int arr[10001] = {0};

    for(int i=0; i< n; i++){
        int cnt;
        cin >> cnt;
        arr[cnt] += 1;        
    }

    for(int i=1; i<10001;i++){
        for(int j=0; j< arr[i]; j++)
            cout << i << "\n";    
    }
}

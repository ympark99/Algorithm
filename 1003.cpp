#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> v(41);

int fibo(int n){
    if(n == 0){
        v[0] = 0;
        return 0;
    }
    else if(n == 1){
        v[1] = 1;
        return 1;
    }    
    if(v[n] != 0) return v[n];
    else return v[n] = fibo(n-1) + fibo(n-2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        if(n == 0) cout << "1 0" << "\n";
        else if(n == 1) cout << "0 1" << "\n";
        else
        {
            fibo(n);
            cout << v[n-1] << " " << v[n] << "\n";
        }
        

    }

    return 0;
}

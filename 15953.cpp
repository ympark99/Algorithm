#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int a,b;
        int num_a,num_b;
        cin >> a >> b;
        if(a == 1) num_a = 500;
        else if(a>1 && a<=3) num_a = 300;
        else if(a>3 && a<=6) num_a = 200;
        else if(a>6 && a<=10) num_a = 50;
        else if(a>10 && a<=15) num_a = 30;
        else if(a>15 && a<=21) num_a = 10;
        else num_a = 0;

        if(b==1) num_b = 512;
        else if(b>1 && b<=3) num_b = 256;
        else if(b>3 && b<=7) num_b = 128;
        else if(b>7 && b<=15) num_b = 64;
        else if(b>15 && b<=31) num_b = 32;
        else num_b = 0;


        cout << num_a * 10000 + num_b * 10000 << "\n";
    }

    return 0;
}

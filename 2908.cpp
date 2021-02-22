#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string a;
    string b;
    string c ="";
    string d = "";

    cin >> a >> b;

    for(int i=0; i<3; i++){
        c += a[2-i];
        d += b[2-i];
    }

    cout << max(stoi(c),stoi(d));

    return 0;
}

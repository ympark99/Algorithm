#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str = "";
    cin >> str;
    vector<string> cro = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int idx = 0;
    for(int i = 0; i < cro.size(); i++){
        while(1){
            idx = str.find(cro[i]);
            if(idx == string::npos) break;
            str.replace(idx, cro[i].length(), "0");
        }
    }
    cout << str.length();
}

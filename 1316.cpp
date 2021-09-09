#include <iostream>
#include <string>

using namespace std;

int main(){

    int answer = 0;
    
    int n;
    cin >> n;

    string str;
    while (n--){
        cin >> str;

        bool alpha[26 + 1] = {0, };
        bool group = true;

        alpha[str[0] - 'a'] = true;
        for(int i = 1; i < str.length(); i++){
            if(alpha[str[i] - 'a'] == true && str[i-1] != str[i] ){
                group = false;
                break;
            }
            alpha[str[i] - 'a'] = true;
        }
        group? answer++ : NULL;
    }

    cout << answer;
}

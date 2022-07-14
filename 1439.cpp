#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int arr[2] = {0, 0};
    for(int i = 0; i < str.length(); i++){
        if(i == 0){
            arr[str[i] - '0']++;
        }
        else if(str[i - 1] != str[i]){
            arr[str[i] - '0']++;
        }
    }
    cout << min(arr[0], arr[1]);
}

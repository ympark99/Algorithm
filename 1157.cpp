#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    int max = 0;
    int cnt = 0;
    int target;
    int a[26] = {0,};

    transform(str.begin(), str.end(), str.begin(), (int(*)(int))toupper);

    for(int i = 0; i < str.length(); i++){
        a[str[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(max < a[i])
        {
            max = a[i];
            cnt = 0;
            target = i;
        }
        if(max == a[i])
            cnt++;
    }
    if(cnt > 1)
        cout << "?";
    else
        cout << (char)(target+'A');
    return 0;
}

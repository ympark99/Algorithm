#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){

    int T;
    cin >> T;
    
    while(T--){
        map<string, int> m;
        map<string, int>::iterator iter;

        int answer = 1;

        int n;
        cin >> n;

        while (n--){
            string name, kind;
            cin >> name >> kind;
            m[kind]++;
        }

        for(iter = m.begin(); iter != m.end(); iter++){
            answer *= (iter->second + 1);
        }

        cout << answer - 1 << '\n';
    }   

    return 0;
}

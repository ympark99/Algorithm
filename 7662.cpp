#include <iostream>
#include <set>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        multiset<int> s;
        multiset<int>::iterator iter;

        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            char ch;
            int num = 0;
            cin >> ch >> num;
            if(ch == 'I') s.insert(num);
            if(ch == 'D'){
                if(s.empty()) continue;
                else if(num == -1) s.erase(s.begin());
                else if(num == 1){
                    iter = s.end();
                    iter--;         
                    s.erase(iter);           
                }
            }
        }

        if(s.empty()) cout << "EMPTY" << '\n';
        else{
            iter = s.end();
            iter--;
            cout << *iter << " " << *s.begin() << '\n';
        }
    }
    return 0;
}

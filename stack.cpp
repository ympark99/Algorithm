#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    stack<int> st;
    stack<int> rst; // 초기 스택

    for(int i=0; i<n; i++){
        cin >> v[i];
        rst.push(n-i);
    }

    for(int i=0; i<n; i++){
        if(st.top() == v[i]){
            st.pop();
            cout << "-" << "\n";
        } 
        else{
            while(1){
                if(st.top() == v[i]){
                    st.pop();
                    cout << "-" << "\n";
                    break;
                }
                if(rst.empty()){
                    cout << "NO" << "\n";
                    return 0;
                }                
                st.push(rst.top());
                cout << "+" << "\n";
                rst.pop();
            }
        }    
    }

    return 0;
}

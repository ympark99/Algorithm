#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    stack<int> st;
    stack<int> rst; // 초기 스택
    string str = "";

    int no = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        rst.push(n-i);
    }

    for(int i=0; i<n; i++){        
        if(st.top() == v[i]){
            st.pop();
            str += "-";
        } 
        else{
            while(1){
                if(st.top() == v[i]){
                    st.pop();
                    str += "-";
                    break;
                }
                if(rst.empty()){
                    no = 1;
                    break;
                }
                else if(!rst.empty()){      
                    st.push(rst.top());
                    str += "+";
                    rst.pop();
                }
            }
        }     
    }

    if(no == 1){
        cout << "NO" << "\n";
        return 0;
    }
    else{
        for(int i=0; i<str.size(); i++){
            cout << str[i] << "\n";
        }
        return 0;
    }
}

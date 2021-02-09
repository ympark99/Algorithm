#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i< arr1.size();i++){
        int num1 = arr1[i];
        int num2 = arr2[i];
        string str = "";
        stack<int> st1;
        stack<int> st2;

        for(int j=0; j<n; j++){
            st1.push(num1 % 2);
            st2.push(num2 % 2);
            num1 /= 2;
            num2 /= 2;
        }
        for(int j=0; j<n; j++){
            if(st1.top() == 1 || st2.top() == 1){
                str += "#";
                st1.pop();
                st2.pop();
            }
            else{
                str += " ";
                st1.pop();
                st2.pop();                
            }
        }
        answer.push_back(str);
        str.clear();
    }

    return answer;
}

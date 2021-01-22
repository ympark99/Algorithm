#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N;
int num_operator[4];
vector<int> v_input;
vector<int> v_result;
vector<int> v_oper; 

int calculate(){
    int answer = v_input.front();

    for(int i=0;i<N-1;i++){
        switch (v_oper[i])
        {
        case 0:
            answer += v_input[i+1];
            break;
        case 1:
            answer -= v_input[i+1];
            break;
        case 2:
            answer *= v_input[i+1];
            break;
        case 3:
            answer /= v_input[i+1];
            break;     
        default:
            break;
        }
    }

    return answer;
}

void dfs(int depth){
    if(depth == N-1){
        v_result.push_back(calculate());
        return;
    }
    else{
        for(int i=0; i<4; i++){
            if(num_operator[i]){
                num_operator[i]--;
                v_oper.push_back(i);

                dfs(depth+1);

                num_operator[i]++;
                v_oper.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for ( int i = 0 ; i < N ; i++){
        int num;
        cin >> num;
        v_input.push_back(num);
    }
    
    for ( int i = 0 ; i < 4 ; i++)
        cin >> num_operator[i];
    
    v_oper.clear();
    
    dfs(0);
    
    sort(v_result.begin(), v_result.end());
    
    cout << v_result.back() << "\n" << v_result.front();
    
    return 0;
}

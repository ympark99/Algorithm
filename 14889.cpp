#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector< vector<int> > v;
vector<int> start;
vector<int> link;    

bool *check = new bool[n+1];
// bool check[20] = {0,}; // dfs 체크

int result(){
    for(int i=1; i<=n; i++){
        if(!check[i]) link.push_back(i); // 링크 팀 인원 확정
    }   

    cout << "start size" << " ";
    for(int i=0; i < start.size(); i++){
        cout << start[i] << " ";
    }
//    cout << "\n";

    int sum = 0;
    for(int i=0; i<start.size(); i++){
        int start_x = start[i];
        for(int j=0; j<start.size(); j++){
            int start_y = start[j];
            sum += v.at(start_x).at(start_y);
        }
    }

    cout <<"\t sum :" << sum << "\n";

    link.clear();
    return 0;
}

void dfs(int num, int depth){
    if(depth >= (n/2)){ // 스타트팀 인원 확정 
        result();
        return;
    }
    for(int i=num; i<=n; i++){
        if(!check[i]){ // 중복 제거
            check[i] = true;
            start.push_back(i);

            dfs(i+1, depth+1);

            check[i] = false;
            start.pop_back();
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){ // NxN 동적할당
        vector<int> element;
        v.push_back(element);

//        int input[n];
        int *input = new int[n];
        for(int j=0; j<n; j++){
            cin >> input[j];
            v[i].push_back(input[j]);        
        }
    }

    dfs(1,0);
    
    return 0;
}

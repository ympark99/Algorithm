#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long N;
    cin >> N;

    vector<long long> v;
    
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    long long b, c;
    cin >> b >> c;
    long long answer = 0;

    for(int i = 0; i < v.size(); i++){
        if(b >= v[i]){
            answer++;
            continue;
        } 
        else{
            answer++;
            answer += (v[i] -b) / c;
            if((v[i] -b) % c != 0) answer++;
        }
    }
    
    cout << answer;
}

#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return (a % b == 0 ? b : gcd(b, a % b));
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int cur = arrayA[0];
    
    for(int i = 1; i < arrayA.size(); i++) {
        cur = gcd(arrayA[i], cur);
        if(cur == 1) break;
    }
    if(cur != 1) {
        int i;
        for(i = 0; i < arrayB.size(); i++) {
            if(arrayB[i] % cur == 0) break;
        }
        if(i == arrayB.size()) answer = cur;
    }
    cur = arrayB[0];
    for(int i = 1 ; i < arrayB.size() ;i++){
        cur = gcd(cur, arrayB[i]);
        if(cur == 1) break;
    }
    if(cur != 1){
        int i;
        for(i = 0; i < arrayA.size(); i++){
            if(arrayA[i] % cur == 0) break;
        }
        if(i == arrayA.size()) answer = max(cur, answer);
    }
    return answer;
}

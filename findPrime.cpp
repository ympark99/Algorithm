#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    
    return true;    
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> toNum;
    
    for(int i = 0; i < numbers.length(); i++) v.push_back(numbers[i]);
    sort(v.begin(), v.end());
    
    do{
        string str = "";
        for(int i = 0; i < v.size(); i++){
            str.push_back(v[i]);
            toNum.push_back(stoi(str));
        }
    }while(next_permutation(v.begin(), v.end()));
    
    sort(toNum.begin(), toNum.end());
    toNum.erase(unique(toNum.begin(), toNum.end()), toNum.end());
    
    for(int i = 0; i < toNum.size(); i++)
        if(isPrime(toNum[i])) answer++;
    
    return answer;
}

#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

bool prime(ll n) {
    if (n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int get_answer(string num) {
    string tmp = "";
    int ret = 0;
    
    for(int i = 0; i < num.length(); i++) {
        if(num[i] == '0' && !tmp.empty()) {
            ll n = stoll(tmp);
            if(prime(n)) ret++;
            tmp = "";
        }
        else tmp += num[i];
    }
    
    if(!tmp.empty()) {
        ll n = stoll(tmp);
        if(prime(n)) ret++;
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = -1;
    
    int remain = n;    
    string convert = "";
    
    while(remain != 0) {
        convert += to_string(remain % k);
        remain /= k;        
    }
    reverse(convert.begin(), convert.end());
    
    return get_answer(convert);
}

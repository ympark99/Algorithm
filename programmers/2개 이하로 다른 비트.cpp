#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++) {
        string str = "";
        long long num = numbers[i];
        
        while(num > 0) {
            if(num % 2 == 0) {
                str += "0";    
            }
            else str += "1";
            num /= 2;
        }
        reverse(str.begin(), str.end());
        
        bool flag = false;
        for(int j = str.length() - 1; j >= 0; j--) {
            if(str[j] == '0') {
                str[j] = '1';
                for(int k = j + 1; k < str.length(); k++) {
                    if(str[k] == '1') {
                        str[k] = '0';
                        break;
                    }
                }
                flag = true;
                break;
            }
        }
        
        // 모든 이진수 1일때
        if(!flag) {
            str = "1" + str;
            str[1] = '0';
        }
        
        long long tmp = 1;
        long long sum = 0;
        for(int j = str.length() - 1; j >= 0; j--) {
            if(str[j] == '1')
                sum += tmp;
            tmp *= 2;
        }      
        answer.push_back(sum);
    }
    
    return answer;
}

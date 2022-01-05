#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26];
int midIdx = -1;

bool isNotPalin(){
	int cnt = 0;
	for(int i = 0; i < 26; i++){
		if(alpha[i] % 2 == 1){
			midIdx = i;
			cnt++;
		}
	}
	return cnt >= 2;
}

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	string str; cin >> str;

	string answer = "";

	for(int i = 0; i < str.length(); i++)
		alpha[str[i] - 'A']++;
	
	if(isNotPalin()){
		printf("I'm Sorry Hansoo");
		// cout << "I'm sorry Hansoo";
		return 0;
	}

    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 0) {
            for (int j = 0; j < alpha[i] / 2; j++) 
                answer += i + 'A';
    	}
	}

	string back = answer;
	reverse(back.begin(), back.end());

	if(midIdx != -1) answer += midIdx + 'A';
	answer += back;

	cout << answer;

	return 0;
} 

/*
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alpha[26];
int midIdx = -1;

bool isNotPalin(){
    int cnt = 0;
    for (int i = 0; i < 26; i++){
        if (alpha[i] > 0){
            if (alpha[i] % 2 == 1){
                midIdx = i;
                cnt++;
            }
        }
    }
    return cnt >= 2;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

    string str; cin >> str;

    for (int i = 0; i < str.length(); i++)
        alpha[str[i] - 'A']++;

    if (isNotPalin()){
        printf("I'm Sorry Hansoo");
        //cout << "I'm sorry Hansoo";
        return 0;
    }
    else {
        string answer = "";
        string back = "";
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 0) {
                for (int j = 0; j < alpha[i] / 2; j++) {
                    answer += i + 'A';
                }
            }
        }
        back = answer;
        reverse(back.begin(), back.end());
        if (midIdx != -1) {
            answer += midIdx + 'A';
        }
        answer += back;
        cout << answer;
    }
}
*/

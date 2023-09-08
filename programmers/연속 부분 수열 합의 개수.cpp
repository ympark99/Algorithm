#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> elements;
set<int> s;

void sumVector(int len) {
    for(int i = 0; i < elements.size(); i++) {
        int sum = 0;
        for(int j = i; j < i + len; j++) {
            if(j >= elements.size())
                sum += elements[j - elements.size()];
            else sum += elements[j];
        }
        s.insert(sum);
    }
}

int solution(vector<int> elements) {
    int answer = 0;
    
    ::elements = elements;
    
    int len = 1;
    while(len <= elements.size()) {
        sumVector(len);
        len++;
    }
    
    return s.size();
}

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool comp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numstr;

    for (auto i : numbers) numstr.push_back(to_string(i));

    sort(numstr.begin(), numstr.end(), comp);

    if (numstr.at(0) == "0") return "0";
    for (auto i : numstr)
        answer += i;
    return answer;
}

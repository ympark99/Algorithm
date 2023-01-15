#include <string>
#include <vector>

using namespace std;

int discount[4] = {10, 20, 30, 40};
vector<int> ans(2, 0);

void calculate(vector<int> sale, vector<vector<int>> users, vector<int> emoticons){
    int plus = 0, sum = 0;
    vector<int> buyPrice(users.size(), 0);
    vector<bool> check(users.size(), false);
    for(int i = 0; i < emoticons.size(); i++){
        int salePrice = (emoticons[i] * (100 - sale[i])) / 100; // 할인 임티 가격
        for(int j = 0; j < users.size(); j++){
            if(check[j]) continue;
            // 기준 넘으면 구매
            if(sale[i] >= users[j][0]){
                buyPrice[j] += salePrice;
                // 가격 기준 넘으면 플러스 가입
                if(buyPrice[j] >= users[j][1]){
                    plus++;
                    buyPrice[j] = 0;
                    check[j] = true;
                }
            }
        }
    }
    for(auto elem : buyPrice)
        sum += elem;
    if(plus > ans[0] || (plus == ans[0] && sum > ans[1])){
        ans[0] = plus;
        ans[1] = sum;
    }
}

void dfs(vector<int> sale, vector<vector<int>> users, vector<int> emoticons){
    if(sale.size() == emoticons.size()){
        calculate(sale, users, emoticons);
        return; 
    }
    
    for(int i = 0; i < 4; i++){
        sale.push_back(discount[i]);
        dfs(sale, users, emoticons);
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> sale;
    dfs(sale, users, emoticons);
    return ans;
}

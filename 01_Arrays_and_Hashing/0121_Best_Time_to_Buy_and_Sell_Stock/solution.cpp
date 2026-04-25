#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, current_profit, max_profit = 0;
        for (auto p : prices) {
            min_price = min(p, min_price);
            current_profit = p - min_price;
            max_profit = max(current_profit, max_profit);
        }
        return max_profit;
    }
};
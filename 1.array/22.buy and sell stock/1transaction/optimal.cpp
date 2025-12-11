Ques:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Code:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            m = min(m, prices[i]);
            profit = max(profit, prices[i] - m);
        }
        return profit;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Maximum Profit: " << sol.maxProfit(prices2) << endl;

    return 0;
}


Input 1:

prices = [7, 1, 5, 3, 6, 4]
Output 1:

Maximum Profit: 5

Time & Space Complexity:
Aspect	Complexity
Time	O(N) (single pass)
Aux Space	O(1) (in-place)
Ques:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][2][3];  // dp[i][canBuy][transactionsLeft]

    int dfs(vector<int>& prices, int i, int canBuy, int transactionsLeft) {
        if (i == prices.size() || transactionsLeft == 0)
            return 0;

        if (dp[i][canBuy][transactionsLeft] != -1)
            return dp[i][canBuy][transactionsLeft];

        int ans;
        if (canBuy) {
            // Option 1: Buy
            int buy = -prices[i] + dfs(prices, i + 1, 0, transactionsLeft);
            // Option 2: Skip
            int skip = dfs(prices, i + 1, 1, transactionsLeft);
            ans = max(buy, skip);
        } else {
            // Option 1: Sell
            int sell = prices[i] + dfs(prices, i + 1, 1, transactionsLeft - 1);
            // Option 2: Skip
            int skip = dfs(prices, i + 1, 0, transactionsLeft);
            ans = max(sell, skip);
        }
        return dp[i][canBuy][transactionsLeft] = ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return dfs(prices, 0, 1, 2);  // Start from day 0, can buy, 2 transactions left
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 5, 0, 1, 4};

    cout << "Maximum Profit with at most 2 transactions: "
         << sol.maxProfit(prices) << endl;

    return 0;
}

Input:

csharp
Copy
Edit
[3, 5, 0, 1, 4]
Output:

csharp
Copy
Edit
Maximum Profit with at most 2 transactions: 6

Time & Space Complexity:
Aspect	Complexity
Time	O(N * 2 * 3) = O(N)
Aux Space	O(N * 2 * 3) + Recursion Stack O(N)
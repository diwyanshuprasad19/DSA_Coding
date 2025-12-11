Ques:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i][canBuy][transactionsLeft]
    int dp[1001][2][101];

    int dfs(vector<int>& prices, int i, int canBuy, int transactionsLeft, int n) {
        if (i == n || transactionsLeft == 0)
            return 0;

        if (dp[i][canBuy][transactionsLeft] != -1)
            return dp[i][canBuy][transactionsLeft];

        int ans;
        if (canBuy) {
            // Option 1: Buy
            int buy = -prices[i] + dfs(prices, i + 1, 0, transactionsLeft, n);
            // Option 2: Skip
            int skip = dfs(prices, i + 1, 1, transactionsLeft, n);
            ans = max(buy, skip);
        } else {
            // Option 1: Sell
            int sell = prices[i] + dfs(prices, i + 1, 1, transactionsLeft - 1, n);
            // Option 2: Skip
            int skip = dfs(prices, i + 1, 0, transactionsLeft, n);
            ans = max(sell, skip);
        }
        return dp[i][canBuy][transactionsLeft] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));

        // Edge case: if k >= n/2, it's unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        return dfs(prices, 0, 1, k, n);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {12, 14, 17, 10, 14, 13, 12, 15};
    int k = 3;

    cout << "Maximum profit with at most " << k << " transactions: "
         << sol.maxProfit(k, prices) << endl;

    return 0;
}


Output:Maximum profit with at most 3 transactions: 12

Time & Space Complexity:
Aspect	Complexity
Time	O(n * k * 2) = O(n * k)
Aux Space	O(n * k * 2) + recursion stack


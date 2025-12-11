Ques:https://leetcode.com/problems/burst-balloons/description/

Sol:https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52

Code:

#include <bits/stdc++.h>
using namespace std;

// Memoized recursive function to calculate max coins
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int maxCoins = 0;

    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);
        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return dp[i][j] = maxCoins;
}

int maxCoins(vector<int> &original) {
    vector<int> nums = original;

    // Add 1 to both ends
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = original.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1)); // dp[1...n]

    return maxCoinsHelper(1, n, nums, dp);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int result = maxCoins(nums);
    cout << "Maximum coins obtained: " << result << endl;
    return 0;
}


 Time and Space Complexity:
Time Complexity: O(n^3)

There are O(n^2) subproblems.

Each subproblem tries all k in [i, j], i.e., O(n).

Space Complexity: O(n^2)

For dp table of size (n+2) x (n+2).

Recursion stack depth is O(n).

📌 Input:
cpp
Copy
Edit
nums = {3, 1, 5, 8}
✅ Output:
yaml
Copy
Edit
Maximum coins obtained: 167

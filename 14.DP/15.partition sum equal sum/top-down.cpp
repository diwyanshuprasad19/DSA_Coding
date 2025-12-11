Ques: https://leetcode.com/problems/partition-equal-subset-sum/description/

Code:

#include <bits/stdc++.h>
using namespace std;

bool solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index == 0) return nums[0] == target;

    if (dp[index][target] != -1) return dp[index][target];

    bool notTake = solve(index - 1, target, nums, dp);
    bool take = false;
    if (target >= nums[index])
        take = solve(index - 1, target - nums[index], nums, dp);

    return dp[index][target] = take || notTake;
}

bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Odd sum cannot be partitioned equally
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, nums, dp);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "true" : "false") << endl;  // Output: true
    return 0;
}


Sample Input & 📤 Output
🔹 Input:
cpp
Copy
Edit
nums = {1, 5, 11, 5}
🔹 Output:
arduino
Copy
Edit
true
🔹 Explanation:
Total sum = 22 → Target = 11

A subset {1, 5, 5} adds up to 11

📊 Time & Space Complexity
Metric	Value
⏱ Time Complexity	O(n * target) = O(n * (sum/2))
💾 Space Complexity	O(n * target) for DP + O(n) for recursion stack

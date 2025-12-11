Ques:https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

Code:

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int s1, int totalSum, vector<int>& arr, vector<vector<int>>& dp) {
    if (index < 0) {
        int s2 = totalSum - s1;
        return abs(s1 - s2);
    }

    if (dp[index][s1] != -1)
        return dp[index][s1];

    // Pick current element in subset 1
    int pick = solve(index - 1, s1 + arr[index], totalSum, arr, dp);

    // Don't pick (leave it in subset 2)
    int notPick = solve(index - 1, s1, totalSum, arr, dp);

    return dp[index][s1] = min(pick, notPick);
}

int minimumDifference(vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();

    // Max sum for one subset can be totalSum
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
    return solve(n - 1, 0, totalSum, arr, dp);
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minimumDifference(arr) << endl;  // Output: 1
    return 0;
}


Sample Input & 📤 Output
🔹 Input:
cpp
Copy
Edit
arr = {1, 6, 11, 5}
🔹 Output:
Copy
Edit
1
🔹 Explanation:
Partition 1: {1, 5, 6} → sum = 12

Partition 2: {11} → sum = 11

Difference = |12 - 11| = 1

📊 Time & Space Complexity
Metric	Value
⏱ Time Complexity	O(n * totalSum)
💾 Space Complexity	O(n * totalSum) DP + O(n) recursion stack
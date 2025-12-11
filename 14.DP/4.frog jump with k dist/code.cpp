Ques:https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

Code: 

#include <bits/stdc++.h>
using namespace std;

// Helper function with memoization
int frogJumpHelper(int idx, vector<int>& heights, int k, vector<int>& dp) {
    if (idx == 0) return 0;

    if (dp[idx] != -1) return dp[idx];

    int minCost = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (idx - j >= 0) {
            int jump = frogJumpHelper(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
            minCost = min(minCost, jump);
        }
    }

    return dp[idx] = minCost;
}

int frogJump(int n, int k, vector<int>& heights) {
    vector<int> dp(n, -1);
    return frogJumpHelper(n - 1, heights, k, dp);
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int n = heights.size();
    int k = 3;

    int result = frogJump(n, k, heights);
    cout << "Minimum energy required: " << result << endl;

    return 0;
}

🧪 Sample Input/Output
Input:

cpp
Copy
Edit
heights = {10, 30, 40, 50, 20}
k = 3
Output:

swift
Copy
Edit
Minimum energy required: 30
Explanation:

One optimal path is:

0 → 1 (|10 - 30| = 20)

1 → 4 (|30 - 20| = 10)

Total = 20 + 10 = 30

 Time and Space Complexity
Metric	Value
Time Complexity	O(n * k)
Space Complexity	O(n) (memo + stack)


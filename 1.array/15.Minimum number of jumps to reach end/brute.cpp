Ques:https://leetcode.com/problems/jump-game-ii/submissions/1623552928/

Code:

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, int arr[], vector<int> &dp) {
    // Base case: we have reached or crossed the last index
    if (i >= n - 1)
        return 0;

    // If we can't jump from here
    if (arr[i] == 0)
        return INT_MAX;

    // Memoization check
    if (dp[i] != -1)
        return dp[i];

    int minSteps = INT_MAX;

    // We have arr[i] choices for jump length
    for (int j = 1; j <= arr[i]; j++) {
        // Take: we move to i + j
        int take = solve(i + j, n, arr, dp);

        if (take != INT_MAX) {
            minSteps = min(minSteps, 1 + take);  // 1 jump + next result
        }

        // Not-Take: implicitly handled by continuing the loop to try next j
        // (no need to write anything because skipping is automatic here)
    }

    return dp[i] = minSteps;
}

int main() {
    int arr[] = {1, 4, 3, 2, 6, 7};  // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> dp(n, -1);

    int ans = solve(0, n, arr, dp);

    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}

Output:
2

Time and space complexity:

 Time Complexity
Each state (index i) is computed once → O(n).

For each index i, we try up to arr[i] jumps → worst-case O(n²).

So overall:
O(n²) (same as before).

✅ Space Complexity
Recursion stack: up to O(n) depth.

Memoization table: O(n).

➡️ Total: O(n).


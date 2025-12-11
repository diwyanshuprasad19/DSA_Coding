#include <bits/stdc++.h>
using namespace std;

/*
 Time Complexity: O(m * n)
   - Each cell (i, j) computed once.
   - Overlapping subproblems are memoized.

 Space Complexity: O(m * n) + O(m+n)
   - DP table of size m*n.
   - Recursion stack of depth (m+n).
*/

// Recursive function with memoization
int solve(int i, int j, vector<vector<int>>& dp) {
    // Base case
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    // Return if already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // Recursive relation: from top + left
    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);

    return dp[i][j] = up + left;
}

// Main function
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}

int main() {
    int m = 3, n = 7;
    int result = uniquePaths(m, n);
    cout << "Unique Paths (Memoization): " << result << endl;

    /*
     🧪 Input:
       m = 3, n = 7
     ✅ Output:
       Unique Paths (Memoization): 28
    */
    return 0;
}

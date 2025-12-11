 Ques: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

Sol: https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55

Code:

#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& num, int k, vector<int>& dp) {
    int n = num.size();
    if (ind == n) return 0;

    if (dp[ind] != -1) return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + solve(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n, -1);
    return solve(0, num, k, dp);
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}


Time and Space Complexity:
Time: O(n * k) → At most n states, and for each, we check up to k elements.

Space: O(n) for the dp array + recursion stack.

✅ Output:
python
Copy
Edit
The maximum sum is: 84
Ques: https://leetcode.com/problems/different-ways-to-add-parentheses/description/

Sol: https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=53

Code:


#include <bits/stdc++.h>
using namespace std;

int countWaysToEvaluate(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = s[k];

        int lt = countWaysToEvaluate(i, k - 1, 1, s, dp);
        int lf = countWaysToEvaluate(i, k - 1, 0, s, dp);
        int rt = countWaysToEvaluate(k + 1, j, 1, s, dp);
        int rf = countWaysToEvaluate(k + 1, j, 0, s, dp);

        if (op == '&') {
            if (isTrue) ways += lt * rt;
            else ways += lt * rf + lf * rt + lf * rf;
        } else if (op == '|') {
            if (isTrue) ways += lt * rt + lt * rf + lf * rt;
            else ways += lf * rf;
        } else if (op == '^') {
            if (isTrue) ways += lt * rf + lf * rt;
            else ways += lt * rt + lf * rf;
        }
    }

    return dp[i][j][isTrue] = ways;
}

int countWays(string s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return countWaysToEvaluate(0, n - 1, 1, s, dp); // isTrue = 1
}

int main() {
    string s = "T|T&F^T";
    cout << "Ways to parenthesize to true: " << countWays(s) << endl;
    return 0;
}


Time and Space Complexity
Metric	Value
Time	O(n³ * 2) (for all i, j, isTrue combinations)
Space	O(n² * 2) for memo + recursion stack

🧪 Example
cpp
Copy
Edit
Input: "T|T&F^T"
Output: 4
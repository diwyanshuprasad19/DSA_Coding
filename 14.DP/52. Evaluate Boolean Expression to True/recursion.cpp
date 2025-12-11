Ques: https://leetcode.com/problems/different-ways-to-add-parentheses/description/

Sol: https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=53

Code:

#include <iostream>
using namespace std;

int countWaysToEvaluate(int i, int j, bool isTrue, const string &s) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = s[k];

        // Count ways for all 4 combinations
        int lt = countWaysToEvaluate(i, k - 1, true, s);
        int lf = countWaysToEvaluate(i, k - 1, false, s);
        int rt = countWaysToEvaluate(k + 1, j, true, s);
        int rf = countWaysToEvaluate(k + 1, j, false, s);

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

    return ways;
}

int countWays(string expression) {
    return countWaysToEvaluate(0, expression.size() - 1, true, expression);
}

int main() {
    string s = "T|T&F^T";
    cout << "Ways to parenthesize to true: " << countWays(s) << endl;
    return 0;
}


Example
Input: "T|T&F^T"
Output: 4
(There are 4 ways to parenthesize it so it evaluates to true.)

🧩 Time and Space Complexity
Metric	Value
⏱ Time	Exponential: O(2^n) (due to overlapping subproblems)
🧠 Space	O(n) (stack depth of recursion)
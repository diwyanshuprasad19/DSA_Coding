Ques:https://leetcode.com/problems/132-pattern/description/

Sol:https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54

Code:


#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a substring is a palindrome
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive + Memoization function to calculate min cuts
int minPartitions(int i, int n, string &s, vector<int> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int minCost = INT_MAX;

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + minPartitions(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[i] = minCost;
}

// Wrapper function to compute result (min cuts = partitions - 1)
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n, -1);
    return minPartitions(0, n, s, dp) - 1;
}

int main() {
    string s = "aab";  // You can test with "BABABCBADCEDE" or any string
    cout << "Minimum cuts needed: " << minCut(s) << endl;
    return 0;
}



Sample Input/Output
Input:
txt
Copy
Edit
s = "aab"
Output:
txt
Copy
Edit
Minimum cuts needed: 1
🧠 Time & Space Complexity:
Time Complexity: O(n^2)

n recursive calls, each trying substrings of up to n length

Space Complexity: O(n) for dp array + recursion stack


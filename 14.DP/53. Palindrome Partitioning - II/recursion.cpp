Ques:https://leetcode.com/problems/132-pattern/description/

Sol:https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54

Code:

#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to calculate minimum cuts needed for palindrome partitioning
int minPartitions(int i, int n, string &str) {
    if (i == n) return 0;

    int minCost = INT_MAX;

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

// Wrapper function
int palindromePartitioning(string str) {
    int n = str.size();
    return minPartitions(0, n, str) - 1;  // subtract 1 to count cuts, not partitions
}

int main() {
    string str = "BABABCBADCEDE";
    int result = palindromePartitioning(str);
    cout << "Minimum cuts needed: " << result << endl;
    return 0;
}


Input & Output
makefile
Copy
Edit
Input:  BABABCBADCEDE
Output: Minimum cuts needed: 5
🧠 Time and Space Complexity
Time Complexity: Exponential → O(2^n) (worst-case, due to multiple recursive calls)

Space Complexity: O(n) recursion stack (due to function call depth)



Ques:https://leetcode.com/problems/shortest-common-supersequence/description/

Sol: https://www.youtube.com/watch?v=xElxAuBcvsU

Code:

#include <bits/stdc++.h>
using namespace std;

// Recursive function to build the SCS
string scs(int i, int j, string &s1, string &s2) {
    if (i < 0) return s2.substr(0, j + 1);
    if (j < 0) return s1.substr(0, i + 1);

    if (s1[i] == s2[j]) {
        return scs(i - 1, j - 1, s1, s2) + s1[i];
    }

    string op1 = scs(i - 1, j, s1, s2) + s1[i];
    string op2 = scs(i, j - 1, s1, s2) + s2[j];

    return (op1.length() < op2.length()) ? op1 : op2;
}

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    return scs(n - 1, m - 1, s1, s2);
}

int main() {
    string s1 = "abac", s2 = "cab";
    cout << "Shortest Common Supersequence (Recursive): " << shortestCommonSupersequence(s1, s2) << endl;
    return 0;
}


Sample Input & Output
Input:

ini
Copy
Edit
s1 = "abac", s2 = "cab"
Output:

java
Copy
Edit
Shortest Common Supersequence (Recursive): cabac
🧠 Time & Space Complexity (Recursive)
Metric	Value
⏱ Time Complexity	Exponential: O(2^(n+m))
💾 Space Complexity	O(n + m) stack space (max depth)
Ques: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

Sol: https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55

Code:


#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& num, int k) {
    int n = num.size();
    if (ind == n) return 0;

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + solve(j + 1, num, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

int maxSumAfterPartitioning(vector<int>& num, int k) {
    return solve(0, num, k);
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}


Input:
ini
Copy
Edit
num = [1, 15, 7, 9, 2, 5, 10], k = 3
✅ Output:
python
Copy
Edit
The maximum sum is: 84
🧠 Time Complexity (Recursion Only):
Time: Exponential, as it explores all partition possibilities: O(k^n) in worst case.

Space: O(n) due to recursion stack.


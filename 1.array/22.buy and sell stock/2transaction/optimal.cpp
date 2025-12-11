Ques:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

Code:

YES, this is the classic greedy approach for solving the Best Time to Buy and Sell Stock III (LeetCode 123) using constant space and a single pass.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 5, 0, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;

    for (int i = 0; i < n; i++) {
        buy1 = min(buy1, arr[i]);                         // Cheapest buy for first transaction
        profit1 = max(profit1, arr[i] - buy1);            // Max profit after first sell

        buy2 = min(buy2, arr[i] - profit1);               // Effective buy for 2nd transaction
        profit2 = max(profit2, arr[i] - buy2);            // Max profit after 2nd sell
    }

    cout << "Maximum Profit with at most 2 transactions: " << profit2 << endl;
    return 0;
}


Input:

csharp
Copy
Edit
[3, 5, 0, 1, 4]
Output:

csharp
Copy
Edit
Maximum Profit with at most 2 transactions: 6

Time & Space Complexity:
Aspect	Complexity
Time	O(N) (single pass)
Aux Space	O(1) (constant space)

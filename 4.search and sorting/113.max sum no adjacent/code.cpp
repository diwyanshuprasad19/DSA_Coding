Ques:https://leetcode.com/problems/house-robber/description/

Code:


#include <iostream>
#include <cstring>
using namespace std;

int dp[1000000];

// Recursive DP function to find max sum of non-adjacent elements
int solve(int arr[], int n) {
    if (n <= -1) return 0;
    if (dp[n] != -1) return dp[n];

    int include = arr[n] + solve(arr, n - 2); // Include current, skip one
    int exclude = solve(arr, n - 1);          // Skip current

    return dp[n] = max(include, exclude);
}

// Wrapper function to reset dp and call solve
int FindMaxSum(int arr[], int n) {
    memset(dp, -1, sizeof(dp));
    return solve(arr, n - 1);
}

// Main function to test
int main() {
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = FindMaxSum(arr, n);
    cout << "Maximum sum of non-adjacent elements: " << maxSum << endl;

    return 0;
}




Example Input/Output
Input:
cpp
Copy
Edit
arr = {5, 5, 10, 100, 10, 5}, n = 6
Output:
Copy
Edit
110
Pick elements at indices [0, 2, 3, 5] → 5 + 10 + 100 = 115 is not valid due to adjacency.
Best is 5 + 100 + 5 = 110



Time & Space Complexity
Metric	Value
Time Complexity	O(n)
Space Complexity	O(n) (due to dp[n])
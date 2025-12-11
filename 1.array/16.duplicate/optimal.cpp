Ques:https://leetcode.com/problems/find-the-duplicate-number/submissions/1623580349/

Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 1, 3, 4, 2};  // Input array
    int n = sizeof(arr) / sizeof(arr[0]);  // n = 5
    int k = n - 1;  // 4 (because numbers are 1 to 4)

    // Expected sum of numbers from 1 to k
    int sum = (k * (k + 1)) / 2;

    // Actual sum of array elements
    int sum1 = 0;
    for (int i = 0; i < n; i++)
        sum1 += arr[i];

    // The difference is the duplicate number
    int diff = sum1 - sum;

    cout << diff << endl;

    return 0;
}


Output:

3

Time and space compelxity:

✅ Time & Space Complexity:
Time: O(n) (single loop)

Space: O(1) (no extra space)
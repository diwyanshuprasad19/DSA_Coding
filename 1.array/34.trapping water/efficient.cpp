Ques:https://leetcode.com/problems/trapping-rain-water/description/

Sol:https://www.youtube.com/watch?v=1_5VuquLbXg

Code:

#include<bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n) {
    int left[n];
    int right[n];

    // Build the left max array
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }

    // Build the right max array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    // Calculate the trapped water
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        int waterHeight = min(left[i], right[i]);
        if (waterHeight > arr[i])
            res += waterHeight - arr[i];
    }
    return res;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxWater(arr, n);
    return 0;
}

	
Sample Input:
ini
Copy
Edit
arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
✅ Sample Output:
Copy
Edit
6

Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – Three full passes of the array
Space Complexity	O(n) – Two arrays (left and right)


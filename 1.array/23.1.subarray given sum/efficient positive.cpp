Ques:https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

Code:

#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int add = 23;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];

        // Shrink window when sum exceeds target
        while (sum > add && start < i) {
            sum = sum - arr[start];
            start++;
        }

        if (sum == add) {
            cout << "Subarray found from index " << start << " to " << i << endl;
            break;
        }
    }

    return 0;
}

Output:

Array: {15, 2, 4, 8, 9, 5, 10, 23}
Sum: 23

Subarray found from index 1 to 4


Time and Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – single pass with window sliding.
Space Complexity	O(1) – no extra data structures (just variables).

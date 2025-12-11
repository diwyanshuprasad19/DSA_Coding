Ques:https://leetcode.com/problems/maximum-subarray/description/

Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    int max_sum = INT_MIN;
    int sum = 0;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (max_sum < sum) {
            max_sum = sum;
            start = s;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }

    cout << "Maximum Sum: " << max_sum << endl;
    cout << "Subarray Indices (0-based): " << start << " to " << end << endl;

    return 0;
}


Output:
Maximum Sum: 7
Subarray Indices (0-based): 2 to 6


Time and space complexity:

Metric	Complexity
Time Complexity	O(n) ✅ (single pass)
Space Complexity	O(1) ✅ (constant space)
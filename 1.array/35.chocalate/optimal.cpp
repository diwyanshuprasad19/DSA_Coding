Ques:https://www.geeksforgeeks.org/chocolate-distribution-problem/

Code:

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
    sort(a.begin(), a.end());
    long long diff = INT_MAX;
    long long res;
    for (long long i = 0; i <= n - m; i++) {
        res = a[i + m - 1] - a[i];
        diff = min(diff, res);
    }
    return diff;
}

int main() {
    vector<long long> a = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    long long n = a.size();
    long long m = 7;  // Number of students

    long long result = findMinDiff(a, n, m);
    cout << "Minimum difference is: " << result << endl;

    // You can test another case:
    vector<long long> b = {7, 3, 2, 4, 9, 12, 56};
    n = b.size();
    m = 3;
    cout << "Minimum difference is: " << findMinDiff(b, n, m) << endl;

    return 0;
}


Sample Input:

Array:

[7, 3, 2, 4, 9, 12, 56]
n = 7
m = 3
✅ Sample Output:

2
✔️ Because after sorting: [2, 3, 4, 7, 9, 12, 56]
Best window: [2, 3, 4] → 4 - 2 = 2


Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n log n) (for sorting) + O(n) (window) ✅
Space Complexity	O(1) (if in-place sort)
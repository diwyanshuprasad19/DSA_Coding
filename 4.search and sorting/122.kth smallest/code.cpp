Ques:https://www.geeksforgeeks.org/kth-smallest-element-from-an-array-of-intervals/

Sol:https://www.youtube.com/watch?v=wCyZYPqAzko

Code:

#include <bits/stdc++.h>
using namespace std;

int findKthUnique(vector<pair<int, int>>& intervals, int k) {
    // Step 1: Sort intervals by start
    sort(intervals.begin(), intervals.end());

    // Step 2: Merge intervals
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        auto& last = merged.back();

        if (last.second >= intervals[i].first) {
            last.second = max(last.second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    // Step 3: Traverse merged intervals to find K-th unique number
    for (auto& [start, end] : merged) {
        int count = end - start + 1;

        if (k <= count) {
            return start + (k - 1);
        }

        k -= count;
    }

    return -1; // K is too large
}

int main() {
    vector<pair<int, int>> arr = {{5, 11}, {10, 15}, {12, 20}};
    int k = 12;

    int result = findKthUnique(arr, k);
    cout << "The " << k << "th unique number is: " << result << endl;

    return 0;
}




Sample Input:
cpp
Copy
Edit
arr[] = {{5, 11}, {10, 15}, {12, 20}}, K = 12
Step 1: Merge intervals:
css
Copy
Edit
→ [5, 20]
Step 2: Unique elements = [5, 6, ..., 20]
(count = 16)

Step 3: 12th smallest = 5 + 11 = 16
📤 Sample Output:
Copy
Edit
16



Time & Space Complexity
Metric	Complexity
Time Complexity	O(n log n) – for sorting and merging
Space Complexity	O(n) – for storing merged intervals



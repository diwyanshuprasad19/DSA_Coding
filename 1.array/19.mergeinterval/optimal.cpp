Ques:https://leetcode.com/problems/merge-intervals/description/

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on start times
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            // If current interval overlaps with next interval
            if (intervals[i][1] >= intervals[i + 1][0]) {
                // Merge: update next interval
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);

                // Mark current as merged
                intervals[i][0] = -1;
            }
        }

        // Collect merged intervals
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] != -1) {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input: {{6,8}, {1,9}, {2,4}, {4,7}}
    vector<vector<int>> intervals = {{6,8}, {1,9}, {2,4}, {4,7}};

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged Intervals:" << endl;
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}



 Another Test Input:
You can test with this in main():

vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
Expected Output:

Merged Intervals:
[1, 6]
[8, 10]
[15, 18]


Time Complexity: O(n log n)
Space Complexity: O(n)
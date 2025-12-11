Ques:https://leetcode.com/problems/minimum-size-subarray-sum/description/

Sol:https://leetcode.com/problems/minimum-size-subarray-sum/solutions/3724542/c-beginner-friendly-solution-using-2-pointer-approach2-poi/

Code:

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0;
    int sum = 0;
    int mini = INT_MAX;

    while (j < nums.size()) {
        sum += nums[j];
        while (sum >= target) {
            mini = min(mini, j - i + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if (mini == INT_MAX)
        return 0;
    return mini;
}

int main() {
    // Test Case 1
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = minSubArrayLen(target, nums);
    cout << "Minimum subarray length: " << result << endl;  // Expected: 2

    // Test Case 2
    vector<int> nums2 = {1, 4, 4};
    target = 4;
    result = minSubArrayLen(target, nums2);
    cout << "Minimum subarray length: " << result << endl;  // Expected: 1

    // Test Case 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    target = 11;
    result = minSubArrayLen(target, nums3);
    cout << "Minimum subarray length: " << result << endl;  // Expected: 0

    return 0;
}

Example:

Input:

target = 7
nums = [2,3,1,2,4,3]

Output:

2


Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – each element is added and removed at most once ✅
Space Complexity	O(1)
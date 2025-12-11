Ques: https://leetcode.com/problems/partition-equal-subset-sum/description/

Code:

#include <bits/stdc++.h>
using namespace std;

bool solve(int index, int target, vector<int> &nums) {
    if (target == 0) return true;
    if (index == 0) return nums[0] == target;

    bool notTake = solve(index - 1, target, nums);
    bool take = false;
    if (target >= nums[index])
        take = solve(index - 1, target - nums[index], nums);

    return take || notTake;
}

bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    return solve(nums.size() - 1, target, nums);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "true" : "false") << endl;  // Output: true
    return 0;
}


Sample Input & 📤 Output
Input:
cpp
Copy
Edit
nums = {1, 5, 11, 5}
Output:
arduino
Copy
Edit
true
Explanation:
Total sum = 22 → target = 11

A valid subset with sum = 11 exists: {1, 5, 5}

📊 Time and Space Complexity
Metric	Value
⏱ Time Complexity	O(2^n) (Exponential)
💾 Space Complexity	O(n) (Recursion stack)


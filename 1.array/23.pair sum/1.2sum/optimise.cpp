Ques:https://leetcode.com/problems/two-sum/description/


Code:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[nums[0]] = 0;
        int n = nums.size();
        vector<int> ans(2);

        for (int i = 1; i < n; i++) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end()) {
                ans[0] = i;
                ans[1] = m[diff];
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};

Sample Input:

nums = {2, 7, 11, 15}
target = 9

✅ Sample Output:

[1, 0] // (because nums[1] + nums[0] == 9)

Time and Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – one pass through the array
Space Complexity	O(n) – hashmap to store nums + indices
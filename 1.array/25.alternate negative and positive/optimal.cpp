Ques:https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/4723827/interview-approach-follow-up-question/
interview approach:

2 solution there :

Code:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};

Input:

nums = [3,1,-2,-5,2,-4]

Output:

[3, -2, 1, -5, 2, -4]

Time & Space:
✅ Aspect	Complexity
Time Complexity	O(n) – one full pass
Space Complexity	O(n) – extra array for output

Code:

**** when order not needed:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        while (pos < n && neg < n) {
            if (nums[pos] >= 0) pos += 2;
            else if (nums[neg] < 0) neg += 2;
            else {
                swap(nums[pos], nums[neg]);
            }
        }
        return nums;
    }
};

 Example (Order May Change):
Input:

nums = [3,1,-2,-5,2,-4]
Output (one valid output):

[3, -2, 1, -5, 2, -4]
OR:

[1, -2, 3, -5, 2, -4]

Time & Space:
✅ Aspect	Complexity
Time Complexity	O(n) – in-place pass
Space Complexity	O(1) – no extra array used ✅
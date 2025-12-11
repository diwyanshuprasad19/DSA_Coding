Question:https://leetcode.com/problems/single-number/description/

Code:

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;  // XOR cancels out duplicate values
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, 5, 4, 5, 3, 4};  // Example input

    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "Unique element is: " << result << endl;

    return 0;
}


Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(n)	One pass through the array of n elements
💾 Space Complexity	O(1)	Only one integer (ans) used — constant space ✅


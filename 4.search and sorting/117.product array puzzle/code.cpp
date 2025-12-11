Ques:https://leetcode.com/problems/product-of-array-except-self/description/


Yes, you are absolutely right ✅ — in the "Product of Array Except Self" problem, if the input array contains more than one zero, then:

✅ All elements in the output will be zero.

Code:

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);   // Prefix products
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        vector<int> right(n, 1);  // Suffix products
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}


Example
Input:
cpp
Copy
Edit
nums = [1, 2, 3, 4]
Output:
csharp
Copy
Edit
[24, 12, 8, 6]




Time & Space Complexity
Metric	Value
Time Complexity	O(n)
Space Complexity	O(n) (2 extra arrays)
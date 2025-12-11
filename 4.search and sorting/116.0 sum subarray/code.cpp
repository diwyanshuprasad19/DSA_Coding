Ques:https://leetcode.com/problems/subarray-sum-equals-k/description/


The approach uses a prefix sum + hashmap strategy, and it’s designed to handle any integer values, including negatives, because:

It doesn’t rely on array sorting, which is usually a problem when using two-pointers for subarray sums with negatives.

It simply tracks:

bash
Copy
Edit
sum[i] - sum[j] = k
⟹ sum[j] = sum[i] - k
Which holds regardless of whether elements are positive, zero, or negative.

Code:

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cnt += mpp[sum - k];
            mpp[sum]++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    
    cout << "Number of subarrays with sum = " << k << " is: " << sol.subarraySum(nums, k) << endl;
    return 0;
}




Sample Input
cpp
Copy
Edit
nums = [1, 2, 3], k = 3
Prefix sums:
csharp
Copy
Edit
[1, 3, 6]
Valid subarrays:
[1, 2] → 3

[3] → 3

Output:
Copy
Edit
2


Time & Space Complexity
Metric	Value
Time Complexity	O(n)
Space Complexity	O(n) (for map)

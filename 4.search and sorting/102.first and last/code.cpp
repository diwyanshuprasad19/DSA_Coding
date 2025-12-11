Ques:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Code:

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1; // search left half
                } else {
                    left = mid + 1;  // search right half
                }
            }
        }
        
        return idx;
    }    
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);
    cout << "First and last positions of " << target << " are: ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}


Sample Input
cpp
Copy
Edit
arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8}
x = 2
✅ Output
Copy
Edit
1 4

Time & Space Complexity
Metric	Value
Time Complexity	O(log n)
Space Complexity	O(1)


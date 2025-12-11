Ques:https://leetcode.com/problems/search-in-rotated-sorted-array/description/

Solve:https://www.youtube.com/watch?v=5qGrJbHhqFs

Code:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid is the target
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies in the left sorted half
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;  // search left
                else
                    low = mid + 1;   // discard left, search right
            } 
            else {
                // Right half must be sorted
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;   // search right
                else
                    high = mid - 1;  // discard right, search left
            }
        }

        return -1;  // not found
    }
};


 Sample Input/Output
Input:
cpp
Copy
Edit
nums = [4,5,6,7,0,1,2], target = 0
Output:
Copy
Edit
4
Explanation: nums[4] == 0



 Summary
Feature	Description
✅ Logic	Find the sorted half, then binary search in it
⏱️ Time	O(log n) (Binary Search)
💡 Notes	Must handle equality (<=) for correct range check
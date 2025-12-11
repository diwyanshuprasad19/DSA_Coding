Ques:https://leetcode.com/problems/median-of-two-sorted-arrays/

sol:https://www.youtube.com/watch?v=F9c7LpRZWVQ

Code:

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);  // Ensure nums1 is smaller

    int x = nums1.size();
    int y = nums2.size();

    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else if (maxLeftY > minRightX) {
    		low = partitionX + 1;
		}
    }

    // fallback in case input is invalid
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;  // 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;  // 2.5

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;  // 0.0

    nums1 = {};
    nums2 = {1};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;  // 1.0

    return 0;
}




Sample Input & Output
Input:

ini
Copy
Edit
ar1 = [900]
ar2 = [5, 8, 10, 20]
Output:

Copy
Edit
10
Explanation:
Merged array → [5, 8, 10, 20, 900]
Median → middle element (odd size) → 10


Time and Space Complexity
Aspect	Complexity
Time Complexity	O(log(min(m, n)))
Space Complexity	O(1)
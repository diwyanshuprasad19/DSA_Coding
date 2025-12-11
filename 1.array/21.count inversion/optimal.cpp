Ques://https://medium.com/@kapoorprakhar99/count-inversion-in-an-array-using-merge-sort-f8b66e2a5436#:~:text=Count%20Inversions%20%7C%20Practice%20%7C%20GeeksforGeeks&text=If%20array%20is%20already%20sorted,j%5D%20and%20i%20%3C%20j.

https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?source=post_page-----f8b66e2a5436--------------------------------

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
                count += (mid - i + 1);  // All remaining nums[i...mid] are greater
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
        return count;
    }

    int mergesort(vector<int>& nums, int left, int right) {
        int ic = 0;
        if (left < right) {
            int mid = (left + right) / 2;
            ic += mergesort(nums, left, mid);
            ic += mergesort(nums, mid + 1, right);
            ic += merge(nums, left, mid, right);
        }
        return ic;
    }

    int inversionCount(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {6, 3, 2, 1, 5, 4};
    Solution sol;
    int inversions = sol.inversionCount(nums);

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}




time:nlogn
space:n

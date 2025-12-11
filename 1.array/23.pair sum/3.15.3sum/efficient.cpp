Ques:https://leetcode.com/problems/3sum/description/

Code:

#include<bits/stdc++.h>
using namespace std;

void findTriplets(vector<int>& arr, int targetSum) {
    int n = arr.size();
    sort(arr.begin(), arr.end());  // Step 1: Sort the array

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currSum = arr[i] + arr[left] + arr[right];

            if (currSum == targetSum) {
                cout << arr[i] << " + " << arr[left] << " + " << arr[right] << " = " << targetSum << endl;

                // Move pointers to avoid duplicates
                left++;
                right--;
            } else if (currSum < targetSum) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int targetSum = 22;

    findTriplets(arr, targetSum);

    return 0;
}

Sample Input:

Array: {1, 4, 45, 6, 10, 8}
Sum: 22

✅ Sample Output:

4 10 8
(Explanation: 4 + 10 + 8 = 22 ✅)

Time and Space Complexity:
Aspect	Complexity
Time Complexity	O(n²) – Outer loop + inner loop with hashmap
Space Complexity	O(n) – for the unordered_set used in each outer loop
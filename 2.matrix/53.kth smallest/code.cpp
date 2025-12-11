Ques:https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

Code:

#include <iostream>
#include <vector>
#include <algorithm> // for upper_bound
using namespace std;

// Function to find the k-th smallest element in a sorted matrix
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count how many elements are ≤ mid
        for (int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

// Sample usage
int main() {
    vector<vector<int>> matrix = {
        { 1,  5,  9 },
        { 10, 11, 13 },
        { 12, 13, 15 }
    };
    int k = 8;

    int result = kthSmallest(matrix, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}

✅ Sample Input
csharp
Copy
Edit
Matrix:
[
 [ 1,  5,  9 ],
 [10, 11, 13],
 [12, 13, 15]
]
k = 8
✅ Sample Output
csharp
Copy
Edit
The 8-th smallest element is: 13


✅ Time and Space Complexity
⏱️ Time Complexity:
lua
Copy
Edit
O(n * log(max - min) * log n)
log(max - min) for binary search on the number range

O(log n) for upper_bound per row × n rows → O(n log n) per iteration

🧠 Space Complexity:
scss
Copy
Edit
O(1)`
No extra space used besides a few variables (purely in-place)

tc:O(nlogn)
sc:O(1)
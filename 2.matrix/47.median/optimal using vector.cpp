Ques:https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

Sol:https://www.youtube.com/watch?v=Q9wXgdxJq48

done using binry search
upper bound will alwasy point to the value gretaer than the number given.also takes log n time cmplexity for each operation

Code:

// C++ program to find median of a matrix
// using binary search
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Function to find the median in the matrix
int median(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int minVal = INT_MAX, maxVal = INT_MIN;
  
    // Finding the minimum and maximum elements in the matrix
    for (int i = 0; i < r; i++) {
        if (mat[i][0] < minVal)
            minVal = mat[i][0];
        if (mat[i][c - 1] > maxVal)
            maxVal = mat[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
	int lo = minVal, hi = maxVal;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int place = 0;

        // Count elements smaller than or equal to mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(mat[i].begin(), mat[i].end(), mid)
                     - mat[i].begin();
        
        // Adjust the range based on the count of elements found
        if (place < desired)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
int main() {
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << median(mat) << endl;
    return 0;
}

Sample Input & Output
🔹 Sample Input:
Matrix:

Copy
Edit
{
  {1, 3, 5},
  {2, 6, 9},
  {3, 6, 9}
}
🔹 Flattened Sorted Elements:
csharp
Copy
Edit
[1, 2, 3, 3, 5, 6, 6, 9, 9]
🔹 Output:
Copy
Edit
5


Time and Space Complexity Analysis
Assume:

n = number of rows

m = number of columns

maxVal, minVal = maximum and minimum elements in the matrix (used for search range)

⏱️ Time Complexity:
scss
Copy
Edit
O(n * log(m) * log(maxVal – minVal))
📘 Why?
Binary Search on Value Range:

The range of values is from minVal to maxVal.

Binary search on this range takes log(maxVal - minVal) iterations.

In Each Iteration:

You go through each row (n total) and do a binary search in each row (log m) using upper_bound.

Total Work per Iteration:

n * log(m)

✅ Therefore:
sql
Copy
Edit
Time = log(maxVal - minVal) * n * log(m)
So final time complexity is:

scss
Copy
Edit
O(n * log(m) * log(maxVal – minVal))
🧠 Space Complexity:
scss
Copy
Edit
O(1)
📘 Why?
No additional space or data structures are used.

Everything is computed using:

Scalar variables (lo, hi, mid, etc.)

Constant space for loop counters and index tracking.

You're not using any auxiliary arrays, heaps, maps, or recursion.

✅ Final Complexity Summary
Metric	Complexity
Time	O(n * log(m) * log(maxVal – minVal))
Space	O(1)
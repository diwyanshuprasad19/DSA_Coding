
Ques:https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

Code:

#include <iostream>
#include <algorithm>
using namespace std;

bool isPresent(int arr[], int low, int high, int num) {
    while (high >= low) {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
            return true;
        else if (arr[mid] > num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

bool findPair(int arr[], int size, int n) {
    sort(arr, arr + size);  // Step 1: Sort the array

    for (int i = 0; i < size; i++) {
        int target = arr[i] + n;
        if (isPresent(arr, i + 1, size - 1, target))  // Binary search
            return true;
    }
    return false;
}

int main() {
    int arr[] = {4, 12, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 8;

    if (findPair(arr, size, n))
        cout << "Yes, pair exists" << endl;
    else
        cout << "No such pair" << endl;

    return 0;
}


Sample Input / Output
Input:
cpp
Copy
Edit
arr = {4, 12, 3, 5}, n = 8
Output:
arduino
Copy
Edit
Yes, pair exists
Because: 4 + 8 = 12 → pair (4, 12) exists.

Time and Space Complexity
Metric	Value
Time Complexity	O(n log n)
- Sorting	O(n log n)
- Binary search	O(log n) for each of n elements
Space Complexity	O(1) (in-place)


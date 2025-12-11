Code:

#include <iostream>
using namespace std;

// Recursive Binary Search function
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if element is at mid
        if (arr[mid] == x)
            return mid;

        // If element is smaller, search in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        // Else search in right subarray
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element not found
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int x = 10;                     // Element to search
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, x);
    
    if (result == -1)
        cout << "Element is not present in array\n";
    else
        cout << "Element is present at index " << result << "\n";

    return 0;
}



Sample Input
cpp
Copy
Edit
arr[] = {2, 3, 4, 10, 40}
x = 10
📤 Sample Output
pgsql
Copy
Edit
Element is present at index 3



Time and Space Complexity
Metric	Value
Time Complexity	O(log n)
Space Complexity	O(log n) (due to recursion stack)
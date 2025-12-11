Ques:https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

Code:

#include <iostream>
#include <vector>
using namespace std;

// Binary search to find fixed point
int fixedPoint(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid)
            return mid;
        else if (arr[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // no fixed point
}

int main() {
    vector<int> arr = { -10, -5, 0, 3, 7 };
    int index = fixedPoint(arr);
    
    if (index != -1)
        cout << "Fixed point is at index: " << index << endl;
    else
        cout << "No fixed point found." << endl;

    return 0;
}

Input:

cpp
Copy
Edit
arr = {15, 2, 45, 4, 7}
Output:

csharp
Copy
Edit
[2, 4]

✅ Time and Space Complexity
Metric	Value
Time Complexity	O(log n)
Space Complexity	O(1)
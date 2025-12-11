Ques:https://leetcode.com/problems/find-the-duplicate-number/submissions/1623580349/

Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 3, 4, 2, 2};  // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);  // Sort the array

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            cout << arr[i] << endl;  // Print the duplicate
            break;
        }
    }

    return 0;
}


Output:
2


Time and space complexity:

✅ Time Complexity:
sort() takes O(n log n)

Loop takes O(n)

➡️ Total:
O(n log n)

✅ Space Complexity:
In-place sort → O(1) extra space (ignoring input size).
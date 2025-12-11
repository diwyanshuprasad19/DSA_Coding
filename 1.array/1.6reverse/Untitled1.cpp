Ques:https://leetcode.com/problems/reverse-string/

Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;              // Input size of array
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Reverse the array in-place
    for (int j = 0; j < n / 2; j++)
        swap(arr[j], arr[n - 1 - j]);

    // Print reversed array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

Output:

90 11 22 12 25 34 64 

Time and space complexity:
Time:O(n)
Space:O(1)
Ques:https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

Code:

#include <iostream>
#include <cmath>
using namespace std;

int *findTwoElement(int *arr, int n) {
    int a, b;

    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] < 0)
            a = abs(arr[i]);
        else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            b = i + 1;
    }

    int *v = new int[2];
    v[0] = a;
    v[1] = b;
    return v;
}

int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *res = findTwoElement(arr, n);
    cout << "Repeating = " << res[0] << ", Missing = " << res[1] << endl;
    delete[] res; // clean up memory
    return 0;
}


Sample Input
css
Copy
Edit
Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: [1, 5]
1 is repeating

5 is missing


Time & Space Complexity
Metric	Value
Time Complexity	O(n)
Space Complexity	O(1)
Extra Array	Only return array of 2 values (not counted)
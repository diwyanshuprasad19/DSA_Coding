Ques:https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/


Code:

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

pair<int, int> findMinMax(const vector<int>& arr) {
    int currentMin = numeric_limits<int>::max();
    int currentMax = numeric_limits<int>::min();

    for (int num : arr) {
        if (num > currentMax) {
            currentMax = num;
        }
        if (num < currentMin) {
            currentMin = num;
        }
    }
    return {currentMin, currentMax};
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pair<int, int> result = findMinMax(arr);
    cout << "Minimum: " << result.first << ", Maximum: " << result.second << endl;

    // Sample test case
    vector<int> test = {3, 5, 1, 8, 7};
    result = findMinMax(test);
    cout << "Test Case - Minimum: " << result.first << ", Maximum: " << result.second << endl;

    return 0;
}

Output:

Enter the number of elements: 5
Enter the elements: 3 5 1 8 7
Minimum: 1, Maximum: 8
Test Case - Minimum: 1, Maximum: 8

Time and space complexity:

Time Complexity:
O(n) → We traverse the array once.

Space Complexity:
O(1) → No extra space except a few variables (output doesn’t count as extra).


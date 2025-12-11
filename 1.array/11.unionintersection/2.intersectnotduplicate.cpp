Ques:https://www.geeksforgeeks.org/union-of-two-sorted-arrays/

Code:

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void unionArray(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> seen;

    // Insert all elements from arr1
    for (int num : arr1) {
        if (seen.find(num) == seen.end()) {
            cout << num << " ";
            seen.insert(num);
        }
    }

    // Insert elements from arr2 if not already seen
    for (int num : arr2) {
        if (seen.find(num) == seen.end()) {
            cout << num << " ";
            seen.insert(num);
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    cout << "Union of arrays: ";
    unionArray(arr1, arr2);

    // Sample test case
    vector<int> test1 = {1, 2, 2, 2, 3};
    vector<int> test2 = {2, 3, 4, 5};
    cout << "Sample Test - Union: ";
    unionArray(test1, test2);

    return 0;
}

Output:

Enter size of first array: 5
Enter elements of first array: 1 2 2 2 3
Enter size of second array: 4
Enter elements of second array: 2 3 4 5
Union of arrays: 1 2 3 4 5 
Sample Test - Union: 1 2 3 4 5 



Time and space complexity:

Time Complexity:

O(n + m)
👉 You loop through both arrays once each.

Space Complexity:

O(n + m)
👉 The unordered_set may store up to all unique elements.


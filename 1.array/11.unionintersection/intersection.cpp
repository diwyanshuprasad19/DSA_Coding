Ques:https://www.geeksforgeeks.org/intersection-of-two-sorted-arrays/


Code:

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void intersectionArray(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> elements(arr1.begin(), arr1.end());
    unordered_set<int> printed;  // To avoid duplicates

    for (int num : arr2) {
        if (elements.find(num) != elements.end() && printed.find(num) == printed.end()) {
            cout << num << " ";
            printed.insert(num);
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

    cout << "Intersection of arrays: ";
    intersectionArray(arr1, arr2);

    // Sample test case
    vector<int> test1 = {1, 2, 2, 2, 3};
    vector<int> test2 = {2, 3, 4, 5};
    cout << "Sample Test - Intersection: ";
    intersectionArray(test1, test2);

    return 0;
}


Output:

Enter size of first array: 5
Enter elements of first array: 1 2 2 2 3
Enter size of second array: 4
Enter elements of second array: 2 3 4 5
Intersection of arrays: 2 3 
Sample Test - Intersection: 2 3 



Time and space compleixty:

Time Complexity:

O(n + m)
👉 You loop through both arrays once.

Space Complexity:

O(n)
👉 The unordered_set stores unique elements of arr1.


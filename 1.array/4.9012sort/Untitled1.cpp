Ques:https://leetcode.com/problems/sort-colors/description/

Code:

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& arr) {
    int low = 0, curr = 0, high = arr.size() - 1;

    while (curr <= high) {
        if (arr[curr] == 0) {
            swap(arr[curr], arr[low]);
            low++;
            curr++;
        } else if (arr[curr] == 1) {
            curr++;
        } else {  // arr[curr] == 2
            swap(arr[curr], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements (0s, 1s, and 2s only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortColors(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Sample Test Case
    vector<int> test = {2, 0, 2, 1, 1, 0};
    sortColors(test);
    cout << "Sample Test - Sorted: ";
    for (int num : test) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



Output:

Enter the number of elements: 6
Enter the elements (0s, 1s, and 2s only): 2 0 2 1 1 0
Sorted array: 0 0 1 1 2 2 
Sample Test - Sorted: 0 0 1 1 2 2 


Time and space compelxity:

Time Complexity: O(n)
We traverse the array once.

Space Complexity: O(1)
We sort the array in-place without using extra space.
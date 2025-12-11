Ques:https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

Code:

#include <iostream>
#include <vector>
using namespace std;

void moveNegatives(vector<int>& arr) {
    int low = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            swap(arr[i], arr[low]);
            low++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveNegatives(arr);

    cout << "Array after moving negatives to one side: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sample Test Case
    vector<int> test = {1, -2, 3, -4, 5, -6};
    moveNegatives(test);
    cout << "Sample Test - Output: ";
    for (int num : test) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


Output:

Input:

Enter the number of elements: 6
Enter the elements: 1 -2 3 -4 5 -6

Output:

Array after moving negatives to one side: -2 -4 -6 3 5 1 
Sample Test - Output: -2 -4 -6 1 3 5 

Time and space compelxity:

Time Complexity:
O(n) → You loop through the array once to check each element.

Space Complexity:
O(1) → The swap is done in-place, no extra space used.
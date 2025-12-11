Ques:https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Code:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    if (k > arr.size()) {
        throw invalid_argument("k is larger than array size");
    }

    priority_queue<int> pq;  // Max-Heap

    for (auto& num : arr) {
        pq.push(num);
        if (pq.size() > k)
            pq.pop();  // Keep only k smallest
    }

    return pq.top();
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    try {
        int result = kthSmallest(arr, k);
        cout << k << "th Smallest Element is: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Sample test case
    vector<int> test = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    k = 4;
    cout << "\nSample Test: {10, 5, 4, 3, 48, 6, 2, 33, 53, 10}, k = 4" << endl;
    cout << "4th Smallest Element is: " << kthSmallest(test, k) << endl;

    return 0;
}


Output:

Enter number of elements: 6
Enter the elements: 7 10 4 3 20 15
Enter k: 3
3th Smallest Element is: 7

Sample Test: {10, 5, 4, 3, 48, 6, 2, 33, 53, 10}, k = 4
4th Smallest Element is: 5


Time and space complexity:

Time Complexity:
O(n log k)
👉 Each insertion/removal in the heap is O(log k), and we process n elements.

Space Complexity:
O(k)
👉 We maintain a heap of size at most k.
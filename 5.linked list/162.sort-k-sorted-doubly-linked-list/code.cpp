Ques:https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/

Sol:https://www.youtube.com/watch?v=hgcKeJiBCc8

Assumption: And specifically in the context of this heap-based approach, which assumes:
Each element is at most k positions away from its correct sorted position.

Code:

// c++ program to sort k sorted array
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  function to sorts a nearly sorted array
// where every element is at most
// k positions away from its target position.
void nearlySorted(vector<int> &arr, int k) {

    // length of array
    int n = arr.size();

    // creating a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // pushing first k elements in pq
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    int i;

    for (i = k; i < n; i++) {

        pq.push(arr[i]);

        // size becomes k+1 so pop it
        // and add minimum element in (i-k) index
        arr[i - k] = pq.top();
        pq.pop();
    }

    // puting remaining elements in array
    while (!pq.empty()) {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}

// This code is contributed by sachinejain74754.

Output
2 3 5 6 8 9 10 


✅ Time and Space Complexity
Using Heap - O(n*log k) Time and O(k) Space



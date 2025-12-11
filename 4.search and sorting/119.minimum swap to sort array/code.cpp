Ques:https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

Sol:https://www.youtube.com/watch?v=1BxbBgNSwHo

using greedy method here


Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwap(int arr[], int N) {
    vector<pair<int, int>> Vec(N);

    // Pair each element with its index
    for (int i = 0; i < N; i++) {
        Vec[i] = {arr[i], i};
    }

    // Sort by the value part (not index)
    sort(Vec.begin(), Vec.end());

    int swaps = 0;

    for (int i = 0; i < N; ++i) {
        // If element is already in correct position, skip
        if (Vec[i].second == i)
            continue;
        else {
            ++swaps;
            // Swap with the correct index
            swap(Vec[i], Vec[Vec[i].second]);
            --i; // recheck the new element at index i
        }
    }

    return swaps;
}

int main() {
    int arr[] = {1, 5, 4, 3, 2};
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = minSwap(arr, N);
    cout << "Minimum swaps required: " << result << endl;

    return 0;
}



Sample Input / Output
Input:
ini
Copy
Edit
nums = [4, 3, 2, 1]
Output:
bash
Copy
Edit
Minimum swaps to sort: 2


Time and Space Complexity
Metric	Value
Time Complexity	O(n log n)
Space Complexity	O(n)

O(n log n) due to sorting, and O(n) for visited array and vector of pairs.
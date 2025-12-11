Ques:https://leetcode.com/problems/jump-game-ii/submissions/1623552928/

Optimal Greedy Solution
👉 The key idea:

We track the current max reachable index (maxReach).

We track the end of the current jump range (end).

When we reach end, we make a jump and update end = maxReach.


Code: Greedy Solution

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;         // Already at the end
    if (arr[0] == 0) return -1;   // Can't move from start

    int jumps = 0;
    int maxReach = arr[0];
    int steps = arr[0];

    for (int i = 1; i < n; i++) {
        // If we've reached the end
        if (i == n - 1)
            return jumps + 1;

        // Update the farthest we can reach
        maxReach = max(maxReach, i + arr[i]);

        // Use a step to move forward
        steps--;

        // When no steps left, we must jump
        if (steps == 0) {
            jumps++;

            // Check if the current position is beyond maxReach
            if (i >= maxReach)
                return -1;

            // Reset steps for the new jump range
            steps = maxReach - i;
        }
    }

    return -1;  // Should not reach here normally
}

int main() {
    int arr[] = {1, 4, 3, 2, 6, 7};  // Input
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minJumps(arr, n) << endl;

    return 0;
}



Output:

2


Time and space complexity:

Time: O(n) 🔥

Space: O(1) (no extra array needed!)
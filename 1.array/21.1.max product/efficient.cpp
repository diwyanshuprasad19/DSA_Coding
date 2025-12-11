Ques:https://leetcode.com/problems/maximum-product-subarray/description/

Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = arr[0];
    int mi = ans;
    int ma = ans;

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            swap(ma, mi);  // Important: negative flips min/max
        ma = max(arr[i], ma * arr[i]);  // Max product till now
        mi = min(arr[i], mi * arr[i]);  // Min product till now
        ans = max(ans, ma);  // Update overall answer
    }
    cout << "Maximum product subarray: " << ans << endl;
    return 0;
}


Input:


arr = {6, -3, -10, 0, 2}
Output:

Maximum product subarray: 180

 Time & Space Complexity:
Aspect	Complexity
Time	O(N)
Aux Space	O(1) (in-place)
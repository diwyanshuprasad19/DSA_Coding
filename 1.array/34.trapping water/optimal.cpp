Ques:https://leetcode.com/problems/trapping-rain-water/description/

Sol:https://www.youtube.com/watch?v=1_5VuquLbXg
18:40 start

Code:
 
#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n) {
    int l = 0, r = n - 1;
    int left = 0, right = 0;
    long long res = 0;

    while (l < r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= left)
                left = arr[l];
            else
                res += left - arr[l];
            l++;
        } else {
            if (arr[r] >= right)
                right = arr[r];
            else
                res += right - arr[r];
            r--;
        }
    }
    return res;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total trapped water: " << trappingWater(arr, n) << endl;

    // You can test another case too:
    int arr2[] = {3, 0, 0, 2, 0, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Total trapped water: " << trappingWater(arr2, n2) << endl;

    return 0;
}

Explaination:

See here first know that we only transverse for the minimum value from both side.hence now for max on both side remember when 
left max we tqke from arr[i]>=left hence we know that from that point to the left veryhting is smaller than this hence 
like 1 4 7 was there hence we know that at 4 left now water can be saved and even though 7 is there at arr[i] ith poitn no water will be stored
also remember that min(left max,right max) and hence since we tranverse for min poitn on both pointer and hence for left<= right then we know that
at that point left -arr[i] will be value as we know that at that point right is since gretaer than current all the left point and hence 
min(left max,right max) can be used and hence direct value.see that right max is less than the current right value and ehcne left-arr[i] is taken.

1 4 7 we know how it works
now see that 
4 2 ... we know that it cannot be 3 as we are transversing pointer to min value and hence 3 would have been delat ealrier and hence 4 2 7 can only Complexity

Sample Input:
ini
Copy
Edit
arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
✅ Sample Output:
Copy
Edit
6

Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – single pass from both ends
Space Complexity	O(1) – only variables (no extra arrays) ✅


 Ques:https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
 
 Sol:https://www.youtube.com/watch?v=0Hkh1cjnBNA&t=59s

 Code:

#include <bits/stdc++.h>
using namespace std;

/*
   consider 1257 already 
   125 bad=1->hence net window 257 so arr[i]=1 and arr[j]=7 here in next window 
   7 is new bad hence bad++ as 257 2 bad there 7 is new bad while 5 earlier counted in bad
   same for arr[i]>k this has already been counted in earlier window hence bad--;
*/

int minSwap(int arr[], int n, int k) {
    /*
    consider 1257 already 
    125 bad=1->hence net window 257 so arr[i]=1 and arr[j]=7 here in next window 
    7 is new bad hence bad++ as 257 2 bad there 7 is new bad while 5 earlier counted in bad
    same for arr[i]>k this has already been counted in earlier window hence bad--;
    */

    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;

    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;

    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {

        // Decrement count of previous window
        if (arr[i] > k)
            --bad;

        // Increment count of current window
        if (arr[j] > k)
            ++bad;

        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
}

int main() {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    int result = minSwap(arr, n, k);
    cout << "Minimum swaps required: " << result << endl;  // Expected: 1

    return 0;
}


Sample Input & Output:
Input:

arr = {2, 1, 5, 6, 3}
k = 3
Process:

Elements ≤ 3: {2, 1, 3} → count = 3

Initial window: {2, 1, 5} → bad = 1 (5 is bad)

Slide window:

{1, 5, 6} → bad = 2

{5, 6, 3} → bad = 2

Minimum bad = 1 → 1 swap needed. 

Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n) – 1 pass to count + 1 pass sliding window
Space Complexity	O(1) – only variables
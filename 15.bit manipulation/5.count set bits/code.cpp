Ques:https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/

Leetcode:https://leetcode.com/problems/number-of-1-bits/submissions/1659374187/

Video:https://www.youtube.com/watch?v=g6OxU-hRGtY&t=771s

Code:

#include <iostream>
using namespace std;

// Function to find the largest power of 2 (<= n)
int largestPowerOf2InRange(int n) {
    int x = 0;
    while ((1 << x) <= n) {
        x++;
    }
    return x - 1;
}

// Recursive function to count total set bits from 1 to n
int countSetBits(int n) {
    if (n == 0) return 0;

    int x = largestPowerOf2InRange(n); // Highest power of 2 less than or equal to n

    int bitsTill2x = x * (1 << (x - 1));  // Set bits from 1 to 2^x - 1
    int msb2xton = n - (1 << x) + 1;      // Most significant bit (2^x) count from 2^x to n
    int rest = n - (1 << x);              // Remaining part after 2^x

    return bitsTill2x + msb2xton + countSetBits(rest);
}

int main() {
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    return 0;
}



✅ Time Complexity
Let n be the input number.

In each recursive call, we reduce n approximately by half.

Hence, Time Complexity: O(log n)

✅ Space Complexity
Due to recursion stack.

Space Complexity: O(log n)
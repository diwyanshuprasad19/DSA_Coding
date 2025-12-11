Ques:https://leetcode.com/problems/sum-of-two-integers/description/

Sol: https://www.youtube.com/watch?v=qeE4a1b5F_E

Code:

#include <iostream>
using namespace std;

// Function to add two integers without using '+' or '-'
int getSum(int a, int b) {
    while (b != 0) {
        unsigned carry = a & b;  // common set bits = carry
        a = a ^ b;               // sum without carry
        b = carry << 1;          // carry moved to next bit
    }
    return a;
}

int main() {
    int x = 6, y = 2;
    int result = getSum(x, y);
    cout << "Sum is: " << result << endl;
    return 0;
}



Time and Space Complexity
Metric	Value
⏱ Time Complexity	O(log(max(x, y))) -> bit time iteration to be done
In real-world code (like your C++ program):
Since you are working with standard int types which are 32-bit:

The maximum number of iterations is 32

Bitwise shift (carry << 1) can only go up to 31 bits

Therefore...

✅ You can safely say:
🧠 Time Complexity is constant → O(1) in practice


💾 Space Complexity	O(1)
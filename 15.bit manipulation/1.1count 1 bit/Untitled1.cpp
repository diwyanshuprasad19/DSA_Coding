Ques:




Code:

#include <iostream>
using namespace std;

// Function to count set bits in binary representation of a positive integer
unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;  // Add 1 if LSB is 1
        n >>= 1;         // Right shift by 1
    }
    return count;
}

int main() {
    int i = 13;  // Binary: 1101

    // Example: show LSB (Least Significant Bit) using i & 1
    cout << "LSB of " << i << " is: " << (i & 1) << endl;

    // Count the number of 1s in binary representation
    cout << "Number of set bits in " << i << " is: " << countSetBits(i) << endl;

    return 0;
}


Sample Input
cpp
Copy
Edit
i = 13  // Binary = 1101
📤 Sample Output
csharp
Copy
Edit
LSB of 13 is: 1
Number of set bits in 13 is: 3


Time and Space Complexity
Metric	Value
Time Complexity	O(log n)
Space Complexity	O(1)
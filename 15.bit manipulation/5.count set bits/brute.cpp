Ques:https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/

Leetcode:https://leetcode.com/problems/number-of-1-bits/submissions/1659374187/

Code:

// A simple program to count set bits
// in all numbers from 1 to n.
#include <iostream>
using namespace std;

// A utility function to count set bits
// in a number x
unsigned int countSetBitsUtil(unsigned int x);

// Returns count of set bits present in all
// numbers from 1 to n
unsigned int countSetBits(unsigned int n)
{
	int bitCount = 0; // initialize the result

	for (int i = 1; i <= n; i++)
		bitCount += countSetBitsUtil(i);

	return bitCount;
}

// A utility function to count set bits
// in a number x
unsigned int countSetBitsUtil(unsigned int x)
{
	if (x <= 0)
		return 0;
	return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
}

// Driver program to test above functions
int main()
{
	int n = 4;
	cout <<"Total set bit count is " <<countSetBits(n);
	return 0;
}

// This code is contributed by shivanisinghss2110.


📌 Sample Input & Output  
**Input:**
```cpp
int n = 4;
Output:

pgsql
Copy
Edit
Total set bit count is 5


🕒 Time and 🧠 Space Complexity

✅ Time Complexity:

The outer loop runs n times.

For each number i from 1 to n, the function countSetBitsUtil(i) is called.

This function runs in O(log i) time since it recursively divides i by 2.

So total time across all iterations becomes:
O(log 1 + log 2 + log 3 + ... + log n) ≈ O(n log n)

✅ Space Complexity:

Each recursive call stack for countSetBitsUtil(i) takes O(log i) space.

But since recursive calls are not simultaneous, the overall space complexity is:
O(log n)

vbnet
Copy
Edit

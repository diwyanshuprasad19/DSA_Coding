Ques:https://leetcode.com/problems/permutations/

Code:

#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string
void permute(string a, int l, int r)
{
    // Base case: if left == right, we have a full permutation
    if (l == r)
        cout << a << endl;
    else
    {
        // Generate all permutations
        for (int i = l; i <= r; i++)
        {
            // Swap current index with index l
            swap(a[l], a[i]);

            // Recurse for the rest
            permute(a, l + 1, r);

            // Backtrack to restore the original string
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string str = "ABCEFG";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}

// This is code is contributed by rathbhupendra

Sample Input:

ABC

✅ Sample Output (All Permutations):

ABC
ACB
BAC
BCA
CBA
CAB


Time & Space Complexity:
Aspect	Complexity
Time Complexity	O(n!) – total permutations
Space Complexity	O(n) – recursion stack + string (mutable)

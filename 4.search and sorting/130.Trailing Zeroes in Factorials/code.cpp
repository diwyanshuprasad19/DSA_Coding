Ques:https://leetcode.com/problems/factorial-trailing-zeroes/description/


Code:

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        for (int i = 5; i <= n; i *= 5) {
            fives += n / i;
        }
        return fives;
    }
};

int main() {
    Solution sol;

    // Sample Input
    int n = 100;
    int result = sol.trailingZeroes(n);

    cout << "Trailing zeroes in " << n << "! = " << result << endl;

    return 0;
}


 Sample Input
ini
Copy
Edit
n = 100
📤 Output
sql
Copy
Edit
Trailing zeroes in 100! = 24



⏱️ Time & Space Complexity
Metric	Value
Time Complexity	O(log₅ n)
Space Complexity	O(1)
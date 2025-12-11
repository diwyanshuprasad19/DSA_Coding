Ques: https://www.geeksforgeeks.org/dsa/count-of-subsets-with-given-difference/

✅ Approach
This reduces to a subset sum count problem:

Let total sum be S. Then:

markdown
Copy
Edit
S1 - S2 = d
S1 + S2 = S
----------------------
2*S1 = S + d
S1 = (S + d)/2
So we must count the number of subsets with sum = (S + d) / 2

Code:

#include <bits/stdc++.h>
using namespace std;

int countSubsets(int index, int target, vector<int>& arr) {
    if (target == 0) return 1;
    if (index == 0) return arr[0] == target;

    int notPick = countSubsets(index - 1, target, arr);
    int pick = 0;
    if (arr[index] <= target)
        pick = countSubsets(index - 1, target - arr[index], arr);

    return pick + notPick;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totalSum + d) % 2 != 0 || totalSum < d) return 0;

    int target = (totalSum + d) / 2;

    return countSubsets(n - 1, target, arr);
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int d = 1;
    cout << countPartitions(arr.size(), d, arr) << endl;  // Output: 3
    return 0;
}


✅ Sample Input & Output
cpp
Copy
Edit
Input: arr = {1, 1, 2, 3}, d = 1
Output: 3


✅ Time and Space Complexity
Metric	Value
⏱ Time Complexity	O(2^n)
💾 Space Complexity	O(n) stack depth
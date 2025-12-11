Ques:https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

Code:


#include <bits/stdc++.h>
using namespace std;

int solve(int index, int s1, int totalSum, vector<int>& arr) {
    if (index < 0) {
        int s2 = totalSum - s1;
        return abs(s1 - s2);
    }

    // Pick
    int pick = solve(index - 1, s1 + arr[index], totalSum, arr);

    // Not pick
    int notPick = solve(index - 1, s1, totalSum, arr);

    return min(pick, notPick);
}

int minimumDifference(vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    return solve(arr.size() - 1, 0, totalSum, arr);
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minimumDifference(arr) << endl;  // Output: 1
    return 0;
}

Sample Input & 📤 Output
🔹 Input:
cpp
Copy
Edit
arr = {1, 6, 11, 5}
🔹 Output:
Copy
Edit
1
🔹 Explanation:
One partition: {1, 6, 5} → sum = 12

Other: {11} → sum = 11

|12 - 11| = 1

📊 Time and Space Complexity
Metric	Value
⏱ Time Complexity	O(2^n) – every element has 2 choices (pick or not)
💾 Space Complexity	O(n) – recursion depth

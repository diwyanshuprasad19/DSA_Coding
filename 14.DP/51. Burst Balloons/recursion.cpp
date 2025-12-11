Ques:https://leetcode.com/problems/burst-balloons/description/

Sol:https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52

Code:

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum coins
int maxCoinsHelper(int i, int j, vector<int> &nums) {
    if (i > j) return 0;

    int maxCoins = 0;

    // Try bursting each balloon between i and j last
    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return maxCoins;
}

int maxCoins(vector<int> &original) {
    vector<int> nums = original;

    // Add 1 to both ends
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = original.size();
    return maxCoinsHelper(1, n, nums);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int result = maxCoins(nums);
    cout << "Maximum coins obtained: " << result << endl;
    return 0;
}



Input:
cpp
Copy
Edit
nums = {3, 1, 5, 8}
✅ Output:
yaml
Copy
Edit
Maximum coins obtained: 167
🧠 Time Complexity:
Exponential: O(2^n)
Every call tries all possible balloons to burst last, creating a large number of overlapping subproblems.

🧠 Space Complexity:
O(n) (Recursion stack)


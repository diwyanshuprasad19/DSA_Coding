Ques:https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Sol:https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
 
Code:

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] +
                   findMinimumCost(i, ind - 1, cuts, dp) +
                   findMinimumCost(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int minimumCost(int n, vector<int> &cuts) {
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
    return findMinimumCost(1, c, cuts, dp);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, cuts) << endl;
    return 0;
}


 Input:
cpp
Copy
Edit
n = 7;
cuts = {3, 5, 1, 4};
✅ Output:
pgsql
Copy
Edit
The minimum cost incurred is: 16
🧠 Time Complexity:
O(c² × c) where c = number of cuts

We check all combinations between i and j, and loop over all cuts inside it.

🧠 Space Complexity:
O(c²) for the dp table

O(c) recursion stack depth
Ques:https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Sol:https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
 
Code:

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the minimum cost
int findMinimumCost(int i, int j, vector<int> &cuts) {
    if (i > j) return 0;

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] +
                   findMinimumCost(i, ind - 1, cuts) +
                   findMinimumCost(ind + 1, j, cuts);

        mini = min(mini, cost);
    }

    return mini;
}

int minimumCost(int n, vector<int> &cuts) {
    int c = cuts.size();

    // Insert 0 at beginning and n at end for boundary cuts
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    return findMinimumCost(1, c, cuts);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, cuts) << endl;
    return 0;
}
 


 Input:
ini
Copy
Edit
n = 7
cuts = {3, 5, 1, 4}
✅ Output:
pgsql
Copy
Edit
The minimum cost incurred is: 16
🧠 Time Complexity (Recursion):
Exponential, i.e., O(2^n) where n = number of cuts (TLE for large inputs)

🧠 Space Complexity:
O(c) recursion stack space, where c = number of cuts


Ques:https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

Sol:https://www.youtube.com/watch?v=jIa_BC-p_AE

Code:

#include <bits/stdc++.h>
using namespace std;

// Helper to find the latest job (before index) that doesn't overlap
int latest_non_overlap_opt(vector<vector<int>>& job, int index) {
    int low = 0, high = index - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if this job ends before the current job starts
        if (job[mid][0] <= job[index][1]) {
            ans = mid;
            low = mid + 1; // search further right
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();

    // Step 1: Create job vector: {endTime, startTime, profit}
    vector<vector<int>> job(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        job[i] = {endTime[i], startTime[i], profit[i]};
    }

    // Step 2: Sort jobs by endTime
    sort(job.begin(), job.end());

    // Step 3: Initialize DP
    vector<int> dp(n, 0);
    dp[0] = job[0][2];  // profit of first job

    // Step 4: Process all jobs
    for (int i = 1; i < n; i++) {
        int incl = job[i][2];  // profit if we take current job
        int index = latest_non_overlap_opt(job, i);
        if (index != -1) {
            incl += dp[index];
        }

        int excl = dp[i - 1];  // profit if we skip current job

        dp[i] = max(incl, excl);  // max of including or excluding
    }

    return dp[n - 1];
}

int main() {
    // Sample input (same as shown in video/tutorial)
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime   = {3, 4, 5, 6};
    vector<int> profit    = {50, 10, 40, 70};

    int maxProfit = jobScheduling(startTime, endTime, profit);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}


Sample Input
cpp
Copy
Edit
startTime = [1, 2, 3, 3]
endTime =   [3, 4, 5, 6]
profit =    [50, 10, 40, 70]
💡 Explanation:
Best to pick Job 1 (1-3, 50) and Job 4 (3-6, 70)

Total = 50 + 70 = 120

📤 Output
yaml
Copy
Edit
Maximum Profit: 120



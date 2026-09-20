Ques:https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

Code: 

import sys

def frog_jump_helper(idx, heights, k, dp):
    if idx == 0:
        return 0

    if dp[idx] != -1:
        return dp[idx]

    min_cost = sys.maxsize

    for j in range(1, k + 1):
        if idx - j >= 0:
            jump = (
                frog_jump_helper(idx - j, heights, k, dp)
                + abs(heights[idx] - heights[idx - j])
            )
            min_cost = min(min_cost, jump)

    dp[idx] = min_cost
    return dp[idx]


def frog_jump(n, k, heights):
    dp = [-1] * n
    return frog_jump_helper(n - 1, heights, k, dp)


# -------------------------------
# Driver Code (same as C++)
# -------------------------------
heights = [10, 30, 40, 50, 20]
n = len(heights)
k = 3

result = frog_jump(n, k, heights)
print("Minimum energy required:", result)

🧪 Sample Input
heights = [10, 30, 40, 50, 20]
k = 3
✅ Sample Output
Minimum energy required: 30
🧠 Explanation (same logic)
One optimal path:

0 → 1 → 4
|10 - 30| = 20
|30 - 20| = 10
Total = 30
The frog can jump up to k steps at a time, and the cost is the absolute height difference.

⏱️ Time & Space Complexity
Metric	Value
Time Complexity	O(n × k)
Space Complexity	O(n)
Reason	DP array + recursion stack
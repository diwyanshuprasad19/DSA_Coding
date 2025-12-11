ques:https://leetcode.com/problems/maximal-rectangle/description/

Sol:https://www.youtube.com/watch?v=ttVu6G7Ayik&t=512s

Code:

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Your original histogram function
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    // Apply row-wise prefix sum + stack histogram
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            // Step 1: Build histogram with prefix sum
            for (int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            // Step 2: Use histogram area function
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};

// Driver code with sample input
int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution sol;
    int result = sol.maximalRectangle(matrix);
    cout << "Maximum rectangle area of 1s is: " << result << endl;

    return 0;
}


Sample Input
arduino
Copy
Edit
[
  ['1','0','1','0','0'],
  ['1','0','1','1','1'],
  ['1','1','1','1','1'],
  ['1','0','0','1','0']
]
✅ Sample Output
csharp
Copy
Edit
Maximum rectangle area of 1s is: 6

 Time & Space Complexity
Metric	Value
Time Complexity	O(rows * cols)
Space Complexity	O(cols)


Ques:https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Sol:https://www.youtube.com/watch?v=Bzat9vgD0fs&t=1193s
see till 12 min min brute force on next smaller and previous smaller element for brute force

optimal after that

Code:

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
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
};

int main() {
    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};

    Solution sol;
    int result = sol.largestRectangleArea(histogram);

    cout << "Largest rectangle area is: " << result << endl;

    return 0;
}

✅ Sample Input
ini
Copy
Edit
histogram = {6, 2, 5, 4, 5, 1, 6}
✅ Sample Output
csharp
Copy
Edit
Largest rectangle area is: 12
💡 Explanation:
The largest rectangle is 4 x 3 = 12 formed from bars: [2, 5, 4, 5] → minimum height 4, width 3

 Time & Space Complexity
⏱️ Time Complexity:
scss
Copy
Edit
O(n)
Every index is pushed and popped at most once from the stack.

🧠 Space Complexity:
scss
Copy
Edit
O(n)
Stack can hold up to n indices in the worst case.



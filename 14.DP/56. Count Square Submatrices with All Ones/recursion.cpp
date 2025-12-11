Ques: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

Sol: https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57

Code:



Input:
cpp
Copy
Edit
arr = {
  {0, 1, 1, 1},
  {1, 1, 1, 1},
  {0, 1, 1, 1}
};
✅ Output:
typescript
Copy
Edit
The number of squares: 15
📈 Time & Space Complexity:
Time Complexity: O(n * m) – single traversal of the matrix

Space Complexity: O(n * m) – for the dp matrix
(Can be optimized to O(m) using two rows)
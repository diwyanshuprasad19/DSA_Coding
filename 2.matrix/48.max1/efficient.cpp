Ques:https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/

Sol:https://www.youtube.com/watch?v=mmSSzbOGnPc
see this is upper bound solutiona nd hecne n*log m is time compelxity further can be reduce tiem compelxity

Code:

#include <bits/stdc++.h>
using namespace std;

// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(vector<vector<bool>>& mat) {
    int maxRow = -1, row = 0;
    int R = mat.size();
    int C = mat[0].size();
    int col = C - 1;

    // Move till we are inside the matrix
    while (row < R && col >= 0) {
        // If the current value is 0, move down to the next row
        if (mat[row][col] == 0) {
            row += 1;
        }
        // Else if the current value is 1, update ans and
        // move to the left column
        else {
            maxRow = row;
            col -= 1;
        }
    }
    return maxRow;
}

// Driver Code
int main() {
    vector<vector<bool>> mat = { { 0, 0, 0, 1 },
                                 { 0, 1, 1, 1 },
                                 { 1, 1, 1, 1 },
                                 { 0, 0, 0, 0 } };

    cout << "Index of row with maximum 1s is "
         << rowWithMax1s(mat);

    return 0;
}


 Time & Space Complexity
⏱️ Time Complexity:
scss
Copy
Edit
O(n + m)
At most, you move m steps left and n steps down.

🧠 Space Complexity:
scss
Copy
Edit
O(1)
No extra space used apart from variables.


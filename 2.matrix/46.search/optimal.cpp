Ques:https://leetcode.com/problems/search-a-2d-matrix-ii/

Code:

#include <iostream>
#include <vector>

using namespace std;

// Function to search for an element in a row-wise and column-wise sorted matrix
bool searchInSortedMatrix(const vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return false;

    int cols = matrix[0].size();
    int i = 0, j = cols - 1;

    // Start from top-right corner
    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) i++;  // Move down
        else j--;                             // Move left
    }

    return false;
}

// Main function with sample test cases
int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    // Sample Test Cases
    vector<int> testValues = {29, 10, 50, 34};

    for (int val : testValues) {
        cout << "Searching for " << val << ": ";
        bool found = searchInSortedMatrix(matrix, val);
        cout << (found ? "true" : "false") << endl;
    }

    return 0;
}


✅ Sample Output
yaml
Copy
Edit
Searching for 29: true
Searching for 10: true
Searching for 50: true
Searching for 34: false


 Time and Space Complexity
Time Complexity: O(n + m) where n = rows, m = cols

Space Complexity: O(1) constant space


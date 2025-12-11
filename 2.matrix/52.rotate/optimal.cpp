Ques:https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

Sol:https://www.youtube.com/watch?v=Z0R2u6gd3GU

Code:

#include <bits/stdc++.h>
using namespace std;

// Function to print matrix
void printMatrix(int arr[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int arr[4][4] = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 },
        {13, 14, 15, 16 }
    };

    int n = 4;

    // Step 1: Transpose
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n / 2; j++)
            swap(arr[i][j], arr[i][n - 1 - j]);

    cout << "Matrix after 90 degree rotation:\n";
    printMatrix(arr);

    return 0;
}

Sample Input
makefile
Copy
Edit
Matrix:
1  2  3  4  
5  6  7  8  
9 10 11 12  
13 14 15 16  
✅ Sample Output (Rotated 90° Clockwise)
Copy
Edit
13  9  5  1  
14 10  6  2  
15 11  7  3  
16 12  8  4  


Time and Space Complexity
Metric	Value
Time Complexity	O(n²)
Space Complexity	O(1)
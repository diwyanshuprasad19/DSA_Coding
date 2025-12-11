


Code:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5}; // Missing number is 4
    int n = sizeof(arr) / sizeof(arr[0]);

    int total = (n + 1) * (n + 2) / 2; // Sum of first n+1 natural numbers
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    int missing = total - sum;

    cout << "Missing number is: " << missing << endl;
    return 0;
}



Sample Input
cpp
Copy
Edit
arr[] = {1, 2, 3, 5}
📤 Sample Output
csharp
Copy
Edit
Missing number is: 4


Time and Space Complexity
Operation	Complexity
Time	O(n)
Space	O(1)
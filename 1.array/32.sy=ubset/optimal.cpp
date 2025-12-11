Ques:https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

Code:

#include <iostream>
#include <unordered_set>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a1[i]);

    int count = 0;
    for (int j = 0; j < m; j++) {
        if (s.find(a2[j]) != s.end())
            count++;
    }

    if (count == m)
        return "Yes";
    else
        return "No";
}

// Main function with sample input and output
int main() {
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};
    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    cout << "Is a2 a subset of a1? " << isSubset(a1, a2, n, m) << endl;

    // Another test case
    int b1[] = {1, 2, 3, 4, 5, 6};
    int b2[] = {1, 2, 4, 10};
    int nb1 = sizeof(b1) / sizeof(b1[0]);
    int nb2 = sizeof(b2) / sizeof(b2[0]);

    cout << "Is b2 a subset of b1? " << isSubset(b1, b2, nb1, nb2) << endl;

    return 0;
}


Sample Input & Output

Input 1:

a1 = {11, 1, 13, 21, 3, 7}
a2 = {11, 3, 7, 1}

Output 1:

Is a2 a subset of a1? Yes

Input 2:

b1 = {1, 2, 3, 4, 5, 6}
b2 = {1, 2, 4, 10}

Output 2:

Is b2 a subset of b1? No

Time & Space Complexity:

Time Complexity:

Building the unordered_set: O(n)

Checking each element of a2: O(m) (average case)

👉 Total:
O(n + m) average case.

Space Complexity:

Extra space for the unordered_set: O(n)


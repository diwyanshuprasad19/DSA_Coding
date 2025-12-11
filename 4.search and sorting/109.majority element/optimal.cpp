Ques:https://leetcode.com/problems/majority-element/description/

Code:

int majorityElement(int a[], int size) {
    int count = 0;
    int ele = 0;

    for (int i = 0; i < size; i++) {
        if (count == 0)
            ele = a[i];

        if (a[i] == ele)
            count++;
        else
            count--;
    }

    return ele; // assuming majority element always exists
}


Sample Input/Output
Input:
cpp
Copy
Edit
a[] = {2, 2, 1, 1, 1, 2, 2}
Output:
Copy
Edit
2


Time and Space Complexity
Metric	Value
Time Complexity	O(n)
Space Complexity	O(1)
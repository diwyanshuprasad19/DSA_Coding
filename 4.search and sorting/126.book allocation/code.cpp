Ques:https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

Sol:https://www.youtube.com/watch?v=Z0hwjftStI4


Code:

#include <bits/stdc++.h>
using namespace std;

// Helper to count how many students are needed if max pages per student = 'pages'
int countStudents(vector<int>& arr, int pages) {
    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

// Main function to find minimum of the maximum pages
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // Not enough books

    int low = *max_element(arr.begin(), arr.end()); // Every student needs at least the largest book
    int high = accumulate(arr.begin(), arr.end(), 0); // At most one student gets all

    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);

        if (students > m) {
            low = mid + 1; // Too many students needed → increase max pages allowed
        } else {
            result = mid;  // Store the possible answer
            high = mid - 1; // Try to minimize further
        }
    }

    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int n = books.size();
    int minPages = findPages(books, n, students);

    cout << "Minimum of the maximum pages: " << minPages << endl;

    return 0;
}


Sample Input
cpp
Copy
Edit
books = {12, 34, 67, 90}
students = 2
📤 Output
yaml
Copy
Edit
Minimum of the maximum pages: 113


Time & Space Complexity
Aspect	Complexity
Time Complexity	O(n * log(sum - max))
Space Complexity	O(1) (no extra space used beyond variables)


Ques:https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-than-a-given-value/

Code:

#include <iostream>
#include <algorithm>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum) {
    sort(arr, arr + n);
    long long count = 0;

    for (int i = 0; i < n; i++) {
        int low = i + 1;
        int high = n - 1;

        while (low < high) {
            if (arr[i] + arr[low] + arr[high] < sum) {
                count += (high - low); // All combos with low to high-1
                low++;
            } else {
                high--;
            }
        }
    }

    return count;
}

int main() {
    long long arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 12;

    cout << "Number of triplets with sum < " << sum << " = "
         << countTriplets(arr, n, sum) << endl;

    return 0;
}



Sample Input / Output
Input:
cpp
Copy
Edit
arr[] = {5, 1, 3, 4, 7}, n = 5, sum = 12
Sorted array:
Copy
Edit
{1, 3, 4, 5, 7}
Output:
Copy
Edit
4



 Time and Space Complexity
Metric	Value
Time Complexity	O(n^2)
Space Complexity	O(1)
Ques:https://www.geeksforgeeks.org/assign-stalls-to-k-cows-to-maximize-the-minimum-distance-between-them/

Sol:https://www.youtube.com/watch?v=R_Mfw4ew-Vo

Code:


    #include <bits/stdc++.h>

    using namespace std;
    bool isPossible(int a[], int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
    }
    int main() {
      int n = 5, cows = 3;
      int a[]={1,2,8,4,9};
      sort(a, a + n);

      int low = 1, high = a[n - 1] - a[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      cout << "The largest minimum distance is " << high << endl;

      return 0;
    }


Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: We can place cow 1 at position 1, cow 2 at position 4 and cow 3 at position 9. So, the maximum possible minimum distance between two cows is 3.


Time Complexity: O(n * log(MAX - MIN)) - where n is the size of the array, MAX is the maximum element in the array and MIN is minimum element in the array.
Auxiliary Space: O(1)
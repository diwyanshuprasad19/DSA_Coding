Ques:https://leetcode.com/problems/k-diff-pairs-in-an-array/description/


Sol:

Solution Logic (Using Hash Map)
cpp
Copy
Edit
unordered_map<int, int> freqMap;
for (int num : nums)
    freqMap[num]++;
This builds a frequency map of all numbers, e.g. for:

cpp
Copy
Edit
nums = [3, 1, 4, 1, 5]
→ freqMap = {1: 2, 3: 1, 4: 1, 5: 1}
✅ Case 1: When k == 0
You only want pairs like (1, 1) where the number is repeated:

cpp
Copy
Edit
if (k == 0 && freq > 1)
    count++;
This only counts a number once if it appears ≥ 2 times

Ensures (1,1) is counted only once → no duplicates

✅ Case 2: When k > 0
We check:

cpp
Copy
Edit
if (freqMap.find(num + k) != freqMap.end())
    count++;
This finds exactly one match per unique num

It does not use indices — only the presence of the target = num + k

That means:

(1, 3) and (3, 1) are the same pair (only counted once)

You only count (1, 3) if both 1 and 3 exist

Because we only loop through the keys of the map (unique elements), we avoid counting:

Duplicates (like multiple (1, 3))

Permutations (like (3, 1) after (1, 3))





Code:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int count = 0;

        // Count frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto& pair : freqMap) {
            int num = pair.first;
            int freq = pair.second;

            if (k == 0) {
                // If k == 0, count numbers that appear more than once
                if (freq > 1)
                    count++;
            } else {
                // For k > 0, check if num + k exists
                if (freqMap.find(num + k) != freqMap.end())
                    count++;
            }
        }

        return count;
    }
};

// Sample main function
int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    int result = sol.findPairs(nums, k);
    cout << "Number of unique k-diff pairs: " << result << endl;

    return 0;
}


Sample Input
ini
Copy
Edit
nums = [3, 1, 4, 1, 5]
k = 2
✅ Output:
javascript
Copy
Edit
Number of unique k-diff pairs: 2
✅ Explanation:
The pairs with diff = 2 are: (1, 3) and (3, 5)


 Time & Space Complexity
Metric	Complexity
Time Complexity	O(n)
Space Complexity	O(n)
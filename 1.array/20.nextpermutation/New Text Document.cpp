
Ques:https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
//use link for better understanding
https://www.geeksforgeeks.org/next-permutation/

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        
        // Step 1: Find the first index 'k' from the end where nums[k] < nums[k + 1]
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        
        if (k < 0) {
            // If no such index found, it's the last permutation -> reverse to smallest
            reverse(nums.begin(), nums.end());
        } else {
            // Step 2: Find the first index 'l' from the end where nums[l] > nums[k]
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            // Step 3: Swap nums[k] and nums[l]
            swap(nums[k], nums[l]);
            // Step 4: Reverse from nums[k + 1] to end to get the next smallest permutation
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3};
    cout << "Original: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}

 Input:

nums = {1, 2, 3}
Output:

Original: 1 2 3 
Next Permutation: 1 3 2

 Time & Space Complexity:
Aspect	Complexity
Time	O(N) (single pass + reverse)
Aux Space	O(1) (in-place)



🌟 What does next permutation mean?

👉 It means the next bigger arrangement of the same numbers, just like the next word in a dictionary.

📖 Example with letters (like dictionary)

Take the word:

CAT


The next word in dictionary order is:

CTA


After that:

TAC





🎲 Imagine

You have numbers lined up in a row, like blocks:

1  3  5  4  2


Now you want to make them into the next bigger arrangement (not too big, just the next one in order).

Think of it like turning pages in a dictionary:

After "CAT" comes "CATCH" or "CATTLE".

After one word, you always go to the smallest next word.

🔎 Step 1: Find the "drop"

Look from right side (end of line).

We are searching for the place where the number suddenly goes down.

Check 2 (end) → before is 4 → 4 > 2 ✅ drop here
Check 4 → before is 5 → 5 > 4 ✅ another drop
Check 5 → before is 3 → 3 < 5 ❌ stop! (this is our pivot)


So, pivot is 3.
Why? → Because after 3, the numbers go down (5,4,2).
This means: "3 can still be made bigger!"

🔎 Step 2: Find the "helper" number

Now look to the right of 3.
We need the smallest number that is bigger than 3.

In [5,4,2], the first bigger from right side is 4.

So, helper = 4.

🔄 Step 3: Swap them

Swap pivot (3) and helper (4).

Before: 1  3  5  4  2
After:  1  4  5  3  2

🔄 Step 4: Fix the "messy tail"

The part after pivot (after 4) is [5,3,2].
Right now it is in descending order (biggest first).
We flip it (reverse) so it becomes ascending order (smallest first).

[5,3,2] → [2,3,5]


So now:

1  4  2  3  5


This is the next permutation.

🧠 Why does this work? (Logic in baby-words)

From right, the first "drop" is the place where we can still increase.

We pick the next bigger number so it grows just a little, not too much.

Then we rearrange the rest into the smallest order so we don’t skip ahead.

It’s like:

You write the smallest bigger number in the “pivot” place.

Then you clean the mess after it into neat ascending order.

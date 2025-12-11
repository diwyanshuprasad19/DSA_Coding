Ques:https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

code:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        
        // Separate negative and positive numbers
        for (auto num : nums) {
            if (num < 0)
                neg.push_back(num);
            else
                pos.push_back(num);
        }
        
        vector<int> result;
        int nIndx = 0, pIndx = 0;
        
        // Alternate positive and negative
        while (nIndx < neg.size() && pIndx < pos.size()) {
            result.push_back(pos[pIndx++]);
            result.push_back(neg[nIndx++]);
        }
        
        return result;
    }
};

Sample Input and Output
Input:

ini
Copy
Edit
nums = [3,1,-2,-5,2,-4]
Output:

csharp
Copy
Edit
[3, -2, 1, -5, 2, -4]


 Time and Space Complexity
Metric	Complexity
Time Complexity	O(n) → single pass to split, single pass to merge
Space Complexity	O(n) → extra vectors pos, neg, and result
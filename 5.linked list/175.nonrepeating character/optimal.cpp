Ques:https://leetcode.com/problems/first-unique-character-in-a-string/description/

Code:
/* 387. First Unique Character in a String
   Return the 0-based index of the first character that appears exactly once.
   If no such character exists, return -1.                                */
class Solution {
public:
    int firstUniqChar(const string& s) {
        const int ALPHA = 26;
        int freq[ALPHA] = {0};

        /* pass-1: frequency count */
        for (char ch : s)
            ++freq[ch - 'a'];

        /* pass-2: first index whose freq == 1 */
        for (int i = 0; i < (int)s.size(); ++i)
            if (freq[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};


Input : "leetcode"
Output: 0      // 'l' is the first and only non-repeating character

Input : "loveleetcode"
Output: 2      // index-2 == 'v'

Input : "aabb"
Output: -1     // no unique character


Complexity
Cost
Time	O(n) (two linear passes)
Extra Space	O(1) (26-element array)

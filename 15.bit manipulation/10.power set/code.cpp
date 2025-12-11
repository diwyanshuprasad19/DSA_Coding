Ques:https://leetcode.com/problems/subsets/description/

Sol:https://www.youtube.com/watch?v=LqKaUv1G3_I

Code:

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.size();
        int total = 1 << n;  // 2^n subsets
        vector<string> ans;

        for (int i = 1; i < total; i++) { // Start from 1 to skip empty string
            string temp = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp += s[j];
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    string input = "abc";
    Solution sol;
    vector<string> result = sol.AllPossibleStrings(input);

    cout << "All non-empty subsequences in lexicographical order:\n";
    for (string str : result) {
        cout << str << "\n";
    }

    return 0;
}


Time and Space Complexity
Let n = s.length():

Aspect	Complexity	Why?
⏱ Time Complexity	O(2^n * n)	2^n subsequences, each up to length n, then sorting the result.
💾 Space Complexity	O(2^n * n)	All subsequences are stored in a vector.

Note:

pow(2, n) = 2^n subsets

Sorting 2^n strings = O(2^n log 2^n) = O(2^n * n) in total
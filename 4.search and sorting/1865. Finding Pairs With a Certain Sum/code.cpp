Ques:https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

Code:


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    vector<int> v1, v2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;

        for (int val : nums2) {
            freq[val]++;
        }
    }

    void add(int index, int val) {
        freq[v2[index]]--;            // Decrease frequency of current value
        v2[index] += val;             // Update the value
        freq[v2[index]]++;            // Increase frequency of new value
    }

    int count(int tot) {
        int result = 0;
        for (int a : v1) {
            int target = tot - a;
            result += freq[target];   // Count pairs that satisfy the condition
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4};

    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    // Initial count
    cout << "Count of pairs with sum 5: " << obj->count(5) << endl;  // Expected: 2 (1+4, 2+3)

    // Perform update
    obj->add(0, 1);  // nums2 becomes {4, 4}

    // Count after update
    cout << "Count of pairs with sum 6: " << obj->count(6) << endl;  // Expected: 2 (2+4, 2+4)

    // Another test
    cout << "Count of pairs with sum 7: " << obj->count(7) << endl;  // Expected: 1 (3+4)

    delete obj;
    return 0;
}



Count of pairs with sum 5: 2
Count of pairs with sum 6: 2
Count of pairs with sum 7: 1



Time & Space Complexity
Operation	Time Complexity	Space Complexity
Constructor	O(n2)	O(n2)
add(index, v)	O(1)	O(1)
count(tot)	O(n1)	O(1) (amortized for lookup)

Where n1 = nums1.size(), n2 = nums2.size().


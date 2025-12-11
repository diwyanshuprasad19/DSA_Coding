Ques:https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Sol:https://www.youtube.com/watch?v=1UOPsfP85V4

Code:


#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class as per LeetCode 25
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; ++i)
                kth = kth->next;
            if (!kth) break; // Not enough nodes for a full group

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse the group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect with previous group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};

// Utility: Create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

// Utility: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

// Main function
int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 3;

    ListNode* head = createList(vals);

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    head = sol.reverseKGroup(head, k);

    cout << "\nReversed in k-groups of " << k << ":\n";
    printList(head);

    return 0;
}


Original List:
1 -> 2 -> 3 -> 4 -> 5

Reversed in k-groups of 3:
3 -> 2 -> 1 -> 4 -> 5


✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(n)	Each node is visited and reversed once
💾 Space Complexity	O(1)	Only a few pointers used, no recursion or stack


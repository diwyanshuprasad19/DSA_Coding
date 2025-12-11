Ques:https://leetcode.com/problems/middle-of-the-linked-list/description/

Code:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

// Helper to insert at end
void insert(ListNode** head_ref, int data) {
    ListNode* new_node = new ListNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    ListNode* temp = *head_ref;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Print list from given node
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Main
int main() {
    ListNode* head = NULL;

    // Create list: 1 → 2 → 3 → 4 → 5 → 6
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle node and after: ";
    printList(mid);

    return 0;
}



Example Input/Output
Input 1:
makefile
Copy
Edit
List: 1 → 2 → 3 → 4 → 5
Output: 3
Input 2:
makefile
Copy
Edit
List: 1 → 2 → 3 → 4 → 5 → 6
Output: 4  (second middle)

Middle node and after: 4 5 6



 Time and Space Complexity
Type	Value
Time Complexity	O(N) — traverses list once
Space Complexity	O(1) — constant pointers used
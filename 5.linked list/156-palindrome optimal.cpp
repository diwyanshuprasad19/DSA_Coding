Ques:https://leetcode.com/problems/palindrome-linked-list/description/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* prev = NULL;
        Node* curr = slow;
        Node* next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare first half and reversed second half
        Node* first = head;
        Node* second = prev;
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// Helper functions
void insert(Node** head_ref, int val) {
    Node* new_node = new Node(val);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main
int main() {
    Node* head = NULL;

    // Palindrome example: 1 → 2 → 3 → 2 → 1
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "Is Palindrome? " << (result ? "Yes" : "No") << endl;

    return 0;
}

Example Input/Output
Input:
Copy
Edit
1 → 2 → 3 → 2 → 1
Output: true

Input:
Copy
Edit
1 → 2 → 3 → 4
Output: false


Time and Space Complexity
Type	Value
Time Complexity	O(N)
Space Complexity	O(1) (in-place)


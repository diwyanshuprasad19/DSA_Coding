Ques:https://www.geeksforgeeks.org/dsa/sort-a-linked-list-of-0s-1s-or-2s/

Code:

#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Solution class
class Solution {
public:
    Node* segregate(Node* head) {
        Node* zero1 = new Node(0);
        Node* one1 = new Node(0);
        Node* two1 = new Node(0);
        Node* zero = zero1;
        Node* one = one1;
        Node* two = two1;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Connect the 0s list to 1s list or 2s if 1s is empty
        zero->next = one1->next ? one1->next : two1->next;
        one->next = two1->next;
        two->next = NULL;

        Node* newHead = zero1->next;

        delete zero1;
        delete one1;
        delete two1;

        return newHead;
    }
};

// Utility to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility to insert at tail
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Main function
int main() {
    Node* head = NULL;

    // Input: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    append(&head, 1);
    append(&head, 2);
    append(&head, 0);
    append(&head, 1);
    append(&head, 2);
    append(&head, 0);
    append(&head, 1);

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    Node* sortedHead = sol.segregate(head);

    cout << "Sorted List:\n";
    printList(sortedHead);

    return 0;
}


Original List:
1 2 0 1 2 0 1 
Sorted List:
0 0 1 1 1 2 2 


✅ Time & Space Complexity
Metric	Value	Reason
⏱ Time Complexity	O(n)	Traverse list once to partition into 3 sublists.
💾 Space Complexity	O(1) (Auxiliary)	No extra space used except a few dummy nodes.


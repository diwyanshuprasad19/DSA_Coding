Ques:https://leetcode.com/problems/middle-of-the-linked-list/description/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create and insert a new node at the end of circular list
void push(Node** head_ref, int data) {
    Node* new_node = new Node{data, NULL};
    Node* temp = *head_ref;

    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_node;
    } else {
        new_node->next = new_node;  // First node points to itself
    }

    *head_ref = new_node;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to split the circular linked list into two halves
void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = *head1_ref;  // First half circular

    Node* curr = *head2_ref;
    while (curr->next != head)
        curr = curr->next;
    curr->next = *head2_ref;  // Second half circular
}

int main() {
    Node* head = NULL;

    // Creating a circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> back to 1
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitList(head, &head1, &head2);

    cout << "First half circular linked list: ";
    printList(head1);

    cout << "Second half circular linked list: ";
    printList(head2);

    return 0;
}


Output
sql
Copy
Edit
First half circular linked list: 1 2 3 
Second half circular linked list: 4 5 


⏱ Time Complexity: O(n)
Finding the midpoint with slow and fast pointer → O(n/2)

Traversing to the end of second half to reconnect → another O(n/2)

Overall = O(n/2 + n/2) = O(n)

✅ Efficient – each node is visited at most once.

💾 Space Complexity: O(1)
No extra arrays or data structures

Only uses a few pointer variables (slow, fast, curr, etc.)

✅ Constant space
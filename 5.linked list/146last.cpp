Ques:https://www.geeksforgeeks.org/dsa/move-last-element-to-front-of-a-given-linked-list/

Code:

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Push node at head
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Move last node to front
void moveToFront(Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    Node* secondLast = NULL;
    Node* last = *head_ref;

    // Traverse till last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // Disconnect last from secondLast
    secondLast->next = NULL;

    // Move last to front
    last->next = *head_ref;
    *head_ref = last;
}

// Print list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Linked list before moving last to front" << endl;
    printList(head);

    moveToFront(&head);

    cout << "Linked list after moving last to front" << endl;
    printList(head);

    return 0;
}

Input Example
The linked list:

Copy
Edit
1 → 2 → 3 → 4 → 5
After moving the last to the front:

Copy
Edit
5 → 1 → 2 → 3 → 4

Output
pgsql
Copy
Edit
Linked list before moving last to front
1 2 3 4 5 
Linked list after moving last to front
5 1 2 3 4 

✅ Time and Space Complexity
Metric	Value
Time Complexity	O(N) — one traversal to reach the last node
Space Complexity	O(1) — constant space, done in-place



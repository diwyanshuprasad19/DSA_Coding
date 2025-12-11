Ques:https://leetcode.com/problems/reverse-linked-list/description/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Iterative function to reverse singly linked list
Node* reverseSLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;    // Save next node
        curr->next = prev;    // Reverse current node's pointer
        prev = curr;          // Move prev one step ahead
        curr = next;          // Move curr one step ahead
    }

    return prev; // New head
}

// Utility to insert at end
void append(Node** head, int data) {
    Node* newNode = new Node(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Utility to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Create list: 1 → 2 → 3 → 4 → 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    cout << "Original list: ";
    printList(head);

    head = reverseSLL(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}

Original DLL: 1 2 3 4 5 
Reversed DLL: 5 4 3 2 1 


✅ Time and Space Complexity
Metric	Value	Why?
⏱ Time	O(n)	You traverse each node once
💾 Space	O(1)	No extra space used – in-place reversal
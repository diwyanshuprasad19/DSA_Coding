Ques:https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Code:

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Insert node at head
void insert(int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Display the linked list
void display(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Reverse a linked list
Node* reverse(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* nex = NULL;
    while (current != NULL) {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
    return prev;
}

// Add 1 to the number represented by the linked list
Node* addOne(Node* head) {
    head = reverse(head);
    bool carry = true;
    Node* curr = head;

    while (curr != NULL && carry == true) {
        if (curr->next == NULL && curr->data == 9) {
            curr->data = 1;
            Node* temp = new Node();
            temp->data = 0;
            temp->next = head;
            head = temp;
            curr = curr->next;
        } else if (curr->data == 9) {
            curr->data = 0;
            curr = curr->next;
        } else {
            curr->data += 1;
            carry = false;
        }
    }

    head = reverse(head);
    return head;
}

// Main function
int main() {
    // List: 3 → 1 → 7 → 2 → 9 (represents 91723)
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);

    cout << "Original linked list: ";
    display(head);

    head = addOne(head);

    cout << "After adding one: ";
    display(head);

    return 0;
}

Output:
Original linked list: 9 2 7 1 3 
After adding one: 9 2 7 1 4 

✅ Time and Space Complexity
Metric	Value
Time Complexity	O(N) — Reversal + Traversal
Space Complexity	O(1) — In-place
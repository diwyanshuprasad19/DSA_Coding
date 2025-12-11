Ques:https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

Code:

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Insert at head
void insert(int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Display linked list
void display() {
    struct Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Remove adjacent duplicates from sorted linked list
void removeDuplicates() {
    if (head == NULL) return;

    struct Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            // Skip duplicate
            temp->next = temp->next->next;
        } else {
            // Move to next distinct element
            temp = temp->next;
        }
    }
}

// Main driver
int main() {
    insert(4);
    insert(3);
    insert(3);
    insert(3);
    insert(2);
    insert(2);
    insert(2);
    insert(1);

    cout << "Original linked list: ";
    display();

    removeDuplicates();

    cout << "After removing duplicates: ";
    display();

    return 0;
}

Output:
Original linked list: 1 2 2 2 3 3 3 4 
After removing duplicates: 1 2 3 4 

✅ Time & Space Complexity
Metric	Value
Time Complexity	O(N) – where N is number of nodes
Space Complexity	O(1) – done in-place
Assumption	List is sorted
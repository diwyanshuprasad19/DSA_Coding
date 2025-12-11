Ques: https://www.geeksforgeeks.org/dsa/remove-duplicates-from-an-unsorted-linked-list/

Code:

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Global head
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

// Remove all duplicates from an unsorted linked list
void removeDuplicates() {
    if (head == NULL) return;

    unordered_map<int, bool> seen;

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (seen[current->data]) {
            // Duplicate found: remove it
            prev->next = current->next;
            // Do not move prev
        } else {
            seen[current->data] = true;
            prev = current;
        }
        current = current->next;
    }
}

// Main
int main() {
    insert(4);
    insert(2);
    insert(5);
    insert(2);
    insert(4);
    insert(1);
    insert(1);

    cout << "Original linked list: ";
    display();

    removeDuplicates();

    cout << "After removing duplicates: ";
    display();

    return 0;
}

Output:
Original linked list: 1 1 4 2 5 2 4 
After removing duplicates: 1 4 2 5 


✅ Time & Space Complexity
Metric	Value
Time Complexity	O(N)
Space Complexity	O(N) – for unordered_map
Ques:https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

// Merges two sorted linked lists using bottom pointers
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = nullptr;  // important: flatten requires only 'bottom'
    return result;
}

// Recursively flattens the list
Node* flatten(Node* root) {
    if (!root || !root->next) return root;

    // Flatten rest of the list
    root->next = flatten(root->next);

    // Merge this list with next
    root = merge(root, root->next);

    return root;
}

// Helper to add a node at the beginning of the bottom list
Node* push(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->bottom = head;
    return newNode;
}

// Print flattened linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    /*
    Create this linked list:
    5 -> 10 -> 19 -> 28
    |    |     |     |
    7    20    22    35
    |          |     |
    8          50    40
    |                |
    30               45
    */

    Node* head = new Node(5);
    head->bottom = push(head->bottom, 7);
    head->bottom = push(head->bottom, 8);
    head->bottom = push(head->bottom, 30);

    head->next = new Node(10);
    head->next->bottom = push(head->next->bottom, 20);

    head->next->next = new Node(19);
    head->next->next->bottom = push(head->next->next->bottom, 22);
    head->next->next->bottom = push(head->next->next->bottom, 50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = push(head->next->next->next->bottom, 35);
    head->next->next->next->bottom = push(head->next->next->next->bottom, 40);
    head->next->next->next->bottom = push(head->next->next->next->bottom, 45);

    Node* flatHead = flatten(head);

    cout << "Flattened linked list: ";
    printList(flatHead);

    return 0;
}

Flattened linked list: 5 7 8 10 19 20 22 28 30 35 40 45 50

✅ Time and Space Complexity
Approach	Time Complexity	Space Complexity	Notes
Brute Force	O(N log N)	O(N)	Copy all nodes, sort, and relink
Recursive Merge	O(N)	O(1) aux / O(k) stack	Merges sorted lists in-place
Min-Heap	O(N log K)	O(K)	Uses priority queue

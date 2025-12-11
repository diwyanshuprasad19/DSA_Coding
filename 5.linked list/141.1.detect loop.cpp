Ques:https://leetcode.com/problems/linked-list-cycle/description/

Code:

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct node {
    int data;
    struct node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Linked list class
struct linkedlist {
    node* head;

    linkedlist() {
        head = NULL;
    }

    // Push new node at head
    void push(int data) {
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

    // Display the list (safe for non-looped lists)
    void display() {
        struct node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Detect loop using Floyd's Cycle Detection Algorithm
    bool detectLoop(node* head) {
        node* slow = head;
        node* fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Move slow by 1
            fast = fast->next->next;     // Move fast by 2

            if (slow == fast) {
                return true;             // Loop detected
            }
        }

        return false;                    // No loop
    }
};

// Main driver
int main() {
    linkedlist l;
    l.push(2);
    l.push(5);
    l.push(4);
    l.push(3);
    l.push(2);
    l.push(1);

    cout << "Linked List: ";
    l.display();

    // Optional: Introduce loop for testing
    // Example: Connect last node to the 3rd node
    // l.head->next->next->next->next->next = l.head->next->next;  // Creates loop

    bool hasLoop = l.detectLoop(l.head);
    if (hasLoop)
        cout << "Loop found" << endl;
    else
        cout << "Loop not found" << endl;

    return 0;
}

Output:

Linked List: 1 2 3 4 5 2 
Loop not found


✅ Time and Space Complexity
Time Complexity: O(N) — each node visited once

Space Complexity: O(1) — no external data structure used
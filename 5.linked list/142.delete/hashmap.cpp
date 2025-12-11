
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

void push(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void display() {
    struct node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 → 2 → 3 → 4 → 5 → 6 → 7
    push(7);
    push(6);
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);

    // Create a loop: 7 → points to node with value 3
    struct node* t = head;
    struct node* t1 = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t1 = t1->next->next;  // Point to 3rd node (value = 3)
    t->next = t1;

    // Detect and remove loop using hashmap
    unordered_map<node*, int> m;
    struct node* curr = head->next;
    struct node* prev = head;

    while (!m[curr]) {
        m[prev] = 1;
        prev = curr;
        curr = curr->next;
    }

    // Break the loop
    prev->next = NULL;

    // Display the list
    display();

    return 0;
}

✅ Time and Space Complexity
Metric	Value
⏱ Time Complexity	O(n)
💾 Space Complexity	O(n) (because of unordered_map)


✅ What the Code Does
1. You create a linked list:
cpp
Copy
Edit
1 → 2 → 3 → 4 → 5 → 6 → 7  
                      ↑  
                      └── points to 3 (loop)
2. You detect and break the loop using hashing:
cpp
Copy
Edit
unordered_map<node*, int> m;
If a node already exists in the map, break the loop by setting prev->next = NULL


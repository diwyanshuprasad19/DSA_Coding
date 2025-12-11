Ques:https://leetcode.com/problems/two-sum/description/

Code:

#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List node
struct Node {
    int data;
    Node *next, *prev;
};

// Function to find pairs with given sum x
void pairSum(Node *head, int x) {
    unordered_map<int, int> m;
    Node* curr = head;

    while (curr != NULL) {
        int a = curr->data;
        if (m.find(x - a) != m.end()) {
            cout << a << " " << (x - a) << endl;
        }
        m[a] = 1;
        curr = curr->next;
    }
}

// Function to insert at head
void insert(Node **head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

int main() {
    Node *head = NULL;

    // Creating doubly linked list: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 7;
    pairSum(head, x);

    return 0;
}



✅ Input
Doubly Linked List: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
Target Sum x = 7

✅ Output
Copy
Edit
5 2
6 1

✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(n)	One pass through the list
💾 Space Complexity	O(n)	Hash map stores up to n elements

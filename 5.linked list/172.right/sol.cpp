Ques:https://www.geeksforgeeks.org/dsa/delete-nodes-which-have-a-greater-value-on-right-side/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Utility to insert node at end
void insert(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
}

// Utility to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    Node* compute(Node* head) {
        head = reverse(head);       // Step 1: Reverse list
        Node* curr = head;
        Node* prev = head;
        int maxVal = head->data;

        while (head) {
            if (head->data >= maxVal) {
                maxVal = head->data;
                prev = head;
                head = head->next;
            } else {
                prev->next = head->next; // Remove current node
                head = prev->next;
            }
        }

        return reverse(curr);       // Step 3: Reverse back
    }
};

int main() {
    Node* head = nullptr;
    insert(head, 12);
    insert(head, 15);
    insert(head, 10);
    insert(head, 11);
    insert(head, 5);
    insert(head, 6);
    insert(head, 2);
    insert(head, 3);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    Node* result = sol.compute(head);

    cout << "Modified List: ";
    printList(result);

    return 0;
}

Original List: 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2 -> 3
Modified List: 15 -> 11 -> 6 -> 3


✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(N)	Each node is visited a constant number of times
💾 Space Complexity	O(1)	In-place reversal and filtering
Ques:https://www.geeksforgeeks.org/dsa/multiply-two-numbers-represented-linked-lists/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to insert a node at the end
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if (!(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
}

// Function to multiply two linked lists as numbers
long long multiplyTwoLists(Node* l1, Node* l2) {
    long long num1 = 0, num2 = 0;
    long long mod = 1e9 + 7;

    while (l1) {
        num1 = (num1 * 10 + l1->data) % mod;
        l1 = l1->next;
    }

    while (l2) {
        num2 = (num2 * 10 + l2->data) % mod;
        l2 = l2->next;
    }

    return (num1 * num2) % mod;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    // Example: Number 123
    append(&l1, 1);
    append(&l1, 2);
    append(&l1, 3);

    // Example: Number 45
    append(&l2, 4);
    append(&l2, 5);

    cout << "Number 1: ";
    printList(l1);
    cout << "Number 2: ";
    printList(l2);

    cout << "Product: " << multiplyTwoLists(l1, l2) << endl;

    return 0;
}

Number 1: 123
Number 2: 45
Product: 5535


✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(N + M)	N = length of first list, M = second
💾 Space Complexity	O(1)	No extra space except a few variables


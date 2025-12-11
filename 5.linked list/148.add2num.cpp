Ques:https://leetcode.com/problems/add-two-numbers-ii/description/

Code:

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* curr) {
        Node* prev = NULL;
        Node* nex;
        while (curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    Node* addTwoLists(Node* first, Node* second) {
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        Node* res = NULL;
        Node* curr = NULL;

        while (first != NULL || second != NULL) {
            int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
            carry = sum / 10;
            sum = sum % 10;

            Node* temp = new Node(sum);
            if (res == NULL) res = temp;
            else curr->next = temp;

            curr = temp;

            if (first) first = first->next;
            if (second) second = second->next;
        }

        if (carry > 0) {
            Node* temp = new Node(carry);
            curr->next = temp;
        }

        res = reverse(res);
        return res;
    }
};

// Utility functions
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main
int main() {
    Node* first = NULL;
    Node* second = NULL;

    // Number 1: 6->4->3 = 643
    push(&first, 3);
    push(&first, 4);
    push(&first, 6);

    // Number 2: 5->6->4 = 564
    push(&second, 4);
    push(&second, 6);
    push(&second, 5);

    Solution ob;
    Node* result = ob.addTwoLists(first, second);

    cout << "Resultant list is: ";
    printList(result);

    return 0;
}



Example Input/Output
Input:
yaml
Copy
Edit
List 1:  6 → 4 → 3   (represents 643)
List 2:  5 → 6 → 4   (represents 564)
Output:
scss
Copy
Edit
1 → 2 → 0 → 7        (represents 1207)


✅ Time and Space Complexity
Metric	Value
Time Complexity	O(max(N, M)) – where N and M are lengths of input lists
Space Complexity	O(max(N, M)) – for result list
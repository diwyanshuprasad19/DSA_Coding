Ques:https://leetcode.com/problems/sort-list/description/

Code:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Utility to insert at end
void insert(Node** head, int data) {
    Node* newNode = new Node{data, NULL};
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Utility to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* mergeSort(Node* head) {
        MergeSorting(&head);
        return head;
    }

private:
    void MergeSorting(Node** head) {
        Node* curr = *head;
        if (curr == NULL || curr->next == NULL) return;

        Node* first;
        Node* second;

        FindMiddle(curr, &first, &second);
        MergeSorting(&first);
        MergeSorting(&second);
        *head = MergeBoth(first, second);
    }

    void FindMiddle(Node* curr, Node** first, Node** second) {
        Node* slow = curr;
        Node* fast = curr->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }

    Node* MergeBoth(Node* first, Node* second) {
        if (first == NULL) return second;
        if (second == NULL) return first;

        Node* result;
        if (first->data <= second->data) {
            result = first;
            result->next = MergeBoth(first->next, second);
        } else {
            result = second;
            result->next = MergeBoth(first, second->next);
        }
        return result;
    }
};

int main() {
    Node* head = NULL;

    insert(&head, 7);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 1);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}


✅ Time and Space Complexity
Metric	Value	Why?
⏱ Time	O(n log n)	Recursively splits + merges
💾 Space	O(log n) (stack)	Due to recursion call stack
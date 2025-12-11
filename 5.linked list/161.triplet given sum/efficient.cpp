Ques:https://leetcode.com/problems/3sum/

Code:


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next, *prev;
};

// Function to count triplets
int countTriplets(Node* head, int x) {
    unordered_map<int, Node*> um;
    Node *ptr1, *ptr2;
    int count = 0;

    for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            int p_sum = ptr1->data + ptr2->data;
            if (um.find(x - p_sum) != um.end()
                && um[x - p_sum] != ptr1
                && um[x - p_sum] != ptr2)
                count++;
        }
    }

    return count / 3;
}

// Insert node at head
void insert(Node** head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;

    if (*head == NULL)
        *head = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 17;

    cout << "Count = " << countTriplets(head, x) << endl;
    return 0;
}




✅ Input
cpp
Copy
Edit
Doubly Linked List: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
Target Sum x = 17
✅ Output
ini
Copy
Edit
Count = 2


🧠 Example: Let’s say the valid triplet is (2, 6, 9)
During iteration, this triplet will be detected in 3 different pair combinations:

Pair (ptr1, ptr2)	Third element from hashmap
(2, 6)	Checks for 9
(6, 9)	Checks for 2
(2, 9)	Checks for 6


✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(n^2)	Outer loop + inner loop + hashmap check
💾 Space Complexity	O(n)	Hashmap stores all nodes once


Ques:https://www.geeksforgeeks.org/dsa/merge-k-sorted-linked-lists-set-2-using-min-heap/

Code:

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge k sorted linked lists using Min Heap
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Custom comparator for min-heap
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap by value
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

    // Add first node of each list to heap
    for (auto list : lists) {
        if (list) minHeap.push(list);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = smallest;

        if (smallest->next)
            minHeap.push(smallest->next);
    }

    return dummy.next;
}

// Utility function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : vals) {
        ListNode* node = new ListNode(val);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    // Input: 3 sorted linked lists
    vector<vector<int>> input = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<ListNode*> lists;
    for (auto& arr : input) {
        lists.push_back(createList(arr));
    }

    cout << "Merged Sorted Linked List:\n";
    ListNode* mergedHead = mergeKLists(lists);
    printList(mergedHead);

    return 0;
}



//https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/
how top works.

Output:
Merged Sorted Linked List:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6


✅ Time and Space Complexity
Metric	Value	Explanation
⏱ Time Complexity	O(N log K)	N = total number of nodes across all lists, K = number of linked lists
💾 Space Complexity	O(K)	Min-heap stores up to K nodes at any point
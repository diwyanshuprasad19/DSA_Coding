Ques:https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

Code:

Node* findIntersection(Node* head1, Node* head2)
{
    Node* ptr = head1;
    Node* ptr1 = head2;
    Node* curr = NULL;
    Node* head = NULL;

    while (ptr != NULL && ptr1 != NULL)
    {
        if (ptr->data == ptr1->data)
        {
            Node* temp = new Node(ptr->data);
            if (head == NULL)
            {
                head = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }
        else if (ptr->data < ptr1->data)
        {
            ptr = ptr->next;
        }
        else
        {
            ptr1 = ptr1->next;
        }
    }

    return head;
}

Sample Input/Output
Input:
makefile
Copy
Edit
List1: 1 → 2 → 3 → 4 → 6  
List2: 2 → 4 → 6 → 8
Output:
mathematica
Copy
Edit
Intersection List: 2 → 4 → 6


 Time & Space Complexity
Type	Value
Time Complexity	O(N + M) — where N, M = lengths of both lists
Space Complexity	O(K) — where K = number of common elements (new list)
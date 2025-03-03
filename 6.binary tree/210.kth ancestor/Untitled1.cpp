Ques:https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/


Code:
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Temporary node to keep track of Node returned from previous recursive call
Node* temp = NULL;

// Recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node, int &k) {
    // Base case
    if (!root)
        return NULL;
    
    if (root->data == node ||
        (temp = kthAncestorDFS(root->left, node, k)) ||
        (temp = kthAncestorDFS(root->right, node, k))) {
        
        if (k > 0) {
            k--; // Reduce k as we move up
        } else if (k == 0) {
            // Print the kth ancestor
            cout << "Kth ancestor is: " << root->data << endl;
            
            // Return NULL to stop further backtracking
            return NULL;
        }
        // Return current node to previous call
        return root;
    }
    return NULL;
}

// Utility function to create a new tree node
Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main() {
    // Construct the binary tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // Print kth ancestor of given node
    Node* parent = kthAncestorDFS(root, node, k);
    
    // Check if parent is not NULL, it means there is no Kth ancestor of the node
    if (parent)
        cout << "-1" << endl;

    return 0;
}


Explaintion:
Example Run
Input:
Binary Tree:

markdown
Copy
Edit
        1
       / \
      2   3
     / \
    4   5
k = 2
node = 5
Output:
csharp
Copy
Edit
Kth ancestor is: 1



Time and Space Complexity Analysis
Time Complexity:
The function performs a Depth First Search (DFS) traversal of the tree.
In the worst case, the function visits all nodes in the tree.
Since it traverses each node only once, the time complexity is:
𝑂
(
𝑁
)
O(N)
where 
𝑁
N is the number of nodes in the tree.
Space Complexity:
The space required is O(H) where 
𝐻
H is the height of the tree.
In a balanced tree, the height is log(N), so O(log N) space.
In a skewed tree (like a linked list), the height is O(N).
Hence, worst-case space complexity:
𝑂
(
𝑁
)
O(N)
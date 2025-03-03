Ques:https://leetcode.com/problems/construct-string-from-binary-tree/description/

Code:

#include<bits/stdc++.h>
#include <iostream>  
#include<string>  
using namespace std;

struct Node{
	int data;
	 Node* left;
	Node* right;
Node(int val):data(val),left(NULL),right(NULL){}
	~Node(){}
};
void solve(TreeNode* root, string &ans){
        if(!root) return ;

        ans += to_string(root->val) ;
        if(root->left){
            ans+="(" ;
            solve(root->left,ans) ;
            ans+=")" ;
        }

        if(root->left == NULL && root->right!=NULL){
            ans+="()" ;
        }

        if(root->right){
            ans+="(" ;
            solve(root->right,ans) ;
            ans+=")" ;
        }
    }

    string tree2str(TreeNode* root) {
        if(!root) return "" ;

        string ans = "" ;
        solve(root, ans) ;

        return ans ;
    }

int main()
{
	Node* n1=new Node(1);
	Node* n2=new Node(2);
	Node* n3=new Node(3);
	Node* n4=new Node(4);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	string q="";
	func(n1,q);
	cout<<q;
	
	
	return 0;
}

Time and space complexity:

Time Complexity Analysis:
Each Node is Visited Once:

Traverses the tree in preorder.
𝑂
(
𝑁
)
O(N) where 
𝑁
N is the number of nodes.
String Concatenation:

Each node contributes 
𝑂
(
1
)
O(1) appends.
𝑂
(
𝑁
)
O(N) overall.
Total Time Complexity:
𝑂
(
𝑁
)
O(N)
(Since each node is processed once)

Space Complexity Analysis:
Recursive Stack Storage:

𝑂
(
𝐻
)
O(H) where 
𝐻
H is the tree height.
Worst case (skewed tree) → 
𝑂
(
𝑁
)
O(N).
Best case (balanced tree) → 
𝑂
(
log
⁡
𝑁
)
O(logN).
String Storage:

Stores tree structure → 
𝑂
(
𝑁
)
O(N).
Total Space Complexity:

𝑂
(
𝑁
)
O(N)
(For recursion and result storage)

Final Complexity Summary:
Time Complexity: 
𝑂
(
𝑁
)
O(N)
Space Complexity: 
𝑂
(
𝑁
)
O(N)


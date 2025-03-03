Ques:https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Code:

// C++ program for printing vertical order of a given binary tree
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
	int key;
	Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

// Utility function to store vertical order in map 'm'
// 'hd' is horizontal distance of current node from root.
// 'hd' is initially passed as 0
void get(Node* root)
{
      queue<pair<Node*,pair<int,int>>> q;      //node,vertical,level
      map<int,map<int,multiset<int>>> m;     //vertical,level,node data
      q.push({root,{0,0}});
      while(q.empty()==false)
      {
          auto p=q.front();
          q.pop();
          Node* curr=p.first;
          int vertical=p.second.first;
          int level=p.second.second;
          m[vertical][level].insert(curr->key);
          if(curr->left!=NULL)
          q.push({curr->left,{vertical-1,level+1}});
          if(curr->right!=NULL)
          q.push({curr->right,{vertical+1,level+1}});
      }
      vector<vector<int>>v;
      for(auto p:m)    //for every level
      {
          vector<int>c;
          for(auto w:p.second)
          {
              c.insert(c.end(),w.second.begin(),w.second.end());     //in vector insert function insert value before the given pos
          }
          v.push_back(c);
      }
  int n=v.size();
  int m1=v[0].size();
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<v[i].size();j++)
      cout<<v[i][j]<<" ";
      cout<<endl;
  }
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is n";
	get(root);
	return 0;
}

Time and sapce complexity:
Time Complexity:
BFS Traversal: Each node is visited once → 
𝑂
(
𝑁
)
O(N).
Insertion in Map: Each node's key is inserted into a nested map → 
𝑂
(
log
⁡
𝑁
)
O(logN).
Sorting (multiset ensures sorted order automatically): Since insertion in multiset takes 
𝑂
(
log
⁡
𝑁
)
O(logN), the total sorting is 
𝑂
(
𝑁
log
⁡
𝑁
)
O(NlogN).
Final Output Processing: Iterating over the map to extract sorted elements takes 
𝑂
(
𝑁
)
O(N).
Total Complexity:
𝑂
(
𝑁
log
⁡
𝑁
)
O(NlogN) (due to sorting using multiset and map insertions)

Space Complexity:
Queue: Stores up to 
𝑂
(
𝑁
)
O(N) elements.
Map (m): Stores nodes categorized by vertical and level, leading to 
𝑂
(
𝑁
)
O(N) space usage.
Vector (v): Stores final results, needing 
𝑂
(
𝑁
)
O(N) space.
Total Space Complexity:
𝑂
(
𝑁
)
O(N) (for storing nodes in the map and queue)




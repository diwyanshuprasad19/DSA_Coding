#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node* left;
   struct node* right;	
};

struct node* newnode(int inputdata)
{
	
	struct node* node= new struct node; // dynamic allocation
	node->data = inputdata;
	node->left=NULL;
	node->right=NULL;
	return (node);
}

int main()
{
	
	struct node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	cout<<root->left->left->data;
	
	return 0;
}

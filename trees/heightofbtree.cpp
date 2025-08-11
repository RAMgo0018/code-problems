// This code is used to find the height of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node  //This structure defines a node of the binary tree
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int height(Node *root){// This function calculates the height of the binary tree
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}  

int main() {// Main Part
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	cout<<height(root);
}
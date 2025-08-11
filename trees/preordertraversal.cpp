//This code is used to perform preorder traversal of a binary tree
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

void preorder(Node *root){//This function performs preorder traversal of the binary tree
    //In preorder traversal, the root node is visited first, then the left subtree, and finally the right subtree.
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);    
    }
}  
//Main Part
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	preorder(root);
}
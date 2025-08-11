//This code is used to perform postorder traversal of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node //This structure defines a node of the binary tree 
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void postorder(Node *root){//This function performs postorder traversal of the binary tree
    //In postorder traversal, the left subtree is visited first, then the right subtree, and finally the root node.
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}  

int main() {//Main Part
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	postorder(root);
}
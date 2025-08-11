//This is a code to traverse the inorder traversal of a binary tree
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

void inorder(Node *root){//This function performs inorder traversal of the binary tree
    //In inorder traversal, the left subtree is visited first, then the root node, and finally the right subtree.
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  

int main() {//Main Part
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	inorder(root);
}
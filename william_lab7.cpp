#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

struct Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(Node* root){
  if(root->left)
    inorder(root->left);
  cout << root->data << endl;
  if(root->right)
    inorder(root->right);
}

void preorder(Node* root){
  cout << root->data << endl;
  if(root->left)
    preorder(root->left);
  if(root->right)
    preorder(root->right);
}

void postorder(Node* root){
  if(root->left)
    preorder(root->left);
  if(root->right)
    preorder(root->right);
  cout << root->data << endl;
}

void BFS_tree(Node* root){
  if(root == NULL){
    return;
  }
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
    Node *node = q.front();
    cout << node->data << " ";
    q.pop();
    if (node->left)
      q.push(node->left);
    if (node->right != NULL)
      q.push(node->right);
  }
  cout << endl;
}

void rtl_recure(Node* root, queue<Node*> path){
  if(root){
    path.push(root);
  }
  if(root->left == NULL and root->right == NULL){
    while(!path.empty()){
      Node * current;
      current = path.front();
      path.pop();
      cout << current->data;
    }
    cout << endl;
  }
  else{
    rtl_recure(root->left, path);
    rtl_recure(root->right, path);
  }
}

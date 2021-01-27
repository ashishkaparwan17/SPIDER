#include<bits/stdc++.h>
using namespace std;
struct bstNode{
  struct bstNode *left;
  int data;
  struct bstNode *right;
}*root=NULL;
struct bstNode* insert(struct bstNode* root, int d){
  struct bstNode *newNode=(struct bstNode*)malloc(1*sizeof(struct bstNode));
  newNode->left=NULL;
  newNode->data=d;
  newNode->right=NULL;
  if(root==NULL){
    root=newNode;
  }else if(d<=root->data){
    root->left=insert(root->left,d);
  }else{
    root->right=insert(root->right,d);
  }
  return root;
}
//recursive approach
void findMaxR(struct bstNode *root){
  if(root==NULL){
    printf("Error: empty tree\n");
    return;
  }
  if(root->right==NULL){
    printf("%d\n",root->data );
    return;
  }
  findMaxR(root->right);
}
//iterative approach
void findMaxI(struct bstNode *root){
  if(root==NULL){
    printf("Error: empty tree\n");
    return;
  }
  while(root->right!=NULL){
    root=root->right;
  }
  printf("%d\n",root->data);
}
//recursive approach
void findMinR(struct bstNode *root){
  if(root==NULL){
    printf("Error: empty tree\n");
    return;
  }
  if(root->left==NULL){
    printf("%d\n",root->data);
    return;
  }
  findMinR(root->left);
}
// iterative approach
void findMinI(struct bstNode *root){
  if(root==NULL){
    printf("Error: empty tree\n");
    return;
  }
  while(root->left!=NULL){
    root=root->left;
  }
  printf("%d\n",root->data);
}
int search(struct bstNode* root,int d){
  if(root==NULL) return 0;
  else if(root->data==d) return 1;
  else if(d<=root->data) return search(root->left,d);
  else return search(root->right,d);
}
int findHeight(struct bstNode *root){
  if(root==NULL)
    return -1;
  else{
    int lHeight=findHeight(root->left);
    int rHeight=findHeight(root->right);
    return lHeight>rHeight?lHeight+1:rHeight+1;
  }
}
void levelOrder(struct bstNode* root){
  if(root==NULL){
    return;
  }
  queue<struct bstNode*> q;
  q.push(root);
  while(!q.empty()){
    struct bstNode* curr=q.front();
    printf("%d ",curr->data);
    if(curr->left!=NULL) q.push(curr->left);
    if(curr->right!=NULL) q.push(curr->right);
    q.pop();
  }
}
//DLR - data,left,right
void preOrder(struct bstNode* root){
  if(root==NULL){
    return;
  }
  printf("%d ",root->data);
  preOrder(root->left);
  preOrder(root->right);
}
//LDR - left,data,right
void inOrderA(struct bstNode* root){
  if(root==NULL){
    return;
  }
  inOrderA(root->left);
  printf("%d ",root->data);
  inOrderA(root->right);
}
//LDR - right,data,left
void inOrderD(struct bstNode* root){
  if(root==NULL){
    return;
  }
  inOrderD(root->right);
  printf("%d ",root->data);
  inOrderD(root->left);
}
//LRD - left,right,data
void postOrder(struct bstNode* root){
  if(root==NULL){
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  printf("%d ",root->data);
}
int bstOrNot(struct bstNode* root,int max,int min){
  if(root==NULL)
    return 1;
  if(root->data<min || root->data>max){
    return 0;
  }
  return bstOrNot(root->left,root->data,min) && bstOrNot(root->right,max,root->data);
}
struct bstNode* findMin(struct bstNode* root){
  while(root->left!=NULL)
    root=root->left;
  return root;
}
struct bstNode* deleteNode(struct bstNode* root,int d){
  if(root==NULL) return NULL;
  else if(d<root->data) root->left=deleteNode(root->left,d);
  else if(d>root->data) root->right=deleteNode(root->right,d);
  else{
    //CASE 1 Node has no children
    if(root->left==NULL && root->right==NULL){
      free(root);
      root=NULL;
    }
    //CASE 2 Left node has one children
    else if(root->left==NULL){
      struct bstNode* temp=root;
      root=root->right;
      free(temp);
    }
    //CASE 2 Right node has one children
    else if(root->right==NULL){
      struct bstNode* temp=root;
      root=root->left;
      free(temp);
    }
    //CASE 3 Node has two children
    else{
      struct bstNode* temp=findMin(root->right);
      root->data=temp->data;
      root->right=deleteNode(root->right,d);
    }
  }
  return root;
}
int main(){
  root=insert(root,10);root=insert(root,5);root=insert(root,50);root=insert(root,40);
  root=insert(root,23);root=insert(root,100);root=insert(root,19);root=insert(root,35);
  if(search(root,23))
    printf("Found\n");
  else
    printf("Not found\n");
  printf("Max iterative: ");findMaxI(root);
  printf("Min iterative: ");findMinI(root);
  printf("Max recursive: ");findMaxR(root);
  printf("Min recursive: ");findMinR(root);
  printf("Height of bst: %d\n",findHeight(root));
  printf("Level order: ");levelOrder(root);printf("\n");
  printf("Pre order: ");preOrder(root);printf("\n");
  printf("In order (ascending): ");inOrderA(root);printf("\n");
  printf("In order (descending): ");inOrderD(root);printf("\n");
  printf("Post order: ");postOrder(root);printf("\n");
  printf("Whether binary tree is BST or not: ");
  if(bstOrNot(root,INT_MAX,INT_MIN)) printf("Yes\n");
  else printf("No\n");
  deleteNode(root,100);
  printf("After deleting: \n");
  printf("Level order: ");levelOrder(root);printf("\n");
  printf("Pre order: ");preOrder(root);printf("\n");
  printf("In order (ascending): ");inOrderA(root);printf("\n");
  printf("In order (descending): ");inOrderD(root);printf("\n");
  printf("Post order: ");postOrder(root);printf("\n");
  return 0;
}

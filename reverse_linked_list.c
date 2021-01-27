#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
}*head=NULL;
void print(){
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void insert(int a){
  struct node* temp=(struct node*)malloc(1*sizeof(struct node));
  temp->data=a;temp->next=NULL;
  if(head==NULL){
    head=temp;
    print();
    return;
  }
  temp->next=head;
  head=temp;
  print();
}
void iterativeReverseList(){
  struct node *prev,*curr,*forward;
  curr=head;
  prev=NULL;
  while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  head=prev;
}
void recursiveReverseList(struct node* temp){
  if(temp->next==NULL){
    head=temp;
    return;
  }
  recursiveReverseList(temp->next);
  struct node* forward=temp->next;
  forward->next=temp;
  temp->next=NULL;
}
int main(){
  int i;
  for(i=0;i<20;i+=2) insert(i);
  //iterativeReverseList();
  recursiveReverseList(head);
  print();
  return 0;
}

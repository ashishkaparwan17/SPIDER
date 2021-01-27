#include<stdio.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
}*head=NULL;
void print(){
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void insertAtBeg(int d){
  struct node *temp=(struct node*)malloc(1*sizeof(struct node));
  temp->data=d;
  temp->next=NULL;
  temp->prev=NULL;
  if(head==NULL){
    head=temp;
    return;
  }
  head->prev=temp;
  temp->next=head;
  head=temp;
}
void insertAtEnd(int d){
  struct node *temp=(struct node*)malloc(1*sizeof(struct node));
  temp->data=d;
  temp->next=NULL;
  temp->prev=NULL;
  if(head==NULL){
    head=temp;
    return;
  }
  struct node *p=head;
  while (p->next!=NULL) {
    p=p->next;
  }
  p->next=temp;
  temp->prev=p;
}
int main(){
  int i;
  for(i=2;i<=20;i+=2) insertAtBeg(i);
  print();
  for(i=2;i<=20;i+=2) insertAtEnd(i);
  print();
  return 0;
}

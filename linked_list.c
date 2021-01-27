#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *head=NULL;
void print(){
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void insert(int a,int pos){
  int i;
  struct node *temp1=(struct node*)malloc(1*sizeof(struct node));
  temp1->data=a;
  temp1->next=NULL;
  if(pos==1){
    temp1->next=head;
    head=temp1;
    print();
    return;
  }
  struct node *temp2=head;
  for(i=0;i<pos-2;i+=1){
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
  print();
}
void deleteNode(int pos){
  struct node* prev=head;
  int i;
  if(pos==1){
    head=prev->next;
    free(prev);
    printf("After deletion:  ");print();
    return;
  }
  for(i=0;i<pos-2;i+=1){
    prev=prev->next;
  }
  struct node* temp=prev->next;
  prev->next=temp->next;
  free(temp);
  printf("After deletion:  ");print();
}
int main(){
  int a,i;
  insert(23,1);insert(432,2);insert(1,2);
  deleteNode(1);deleteNode(1);deleteNode(1);
  insert(56,1);insert(74,1);insert(44,3);
  deleteNode(4);
  return 0;
}

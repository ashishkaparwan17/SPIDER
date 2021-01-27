/*
*
* Two sorted linked lists are given. We have to copy one linked list to other 
* and the resultant linked list should also be sorted.
*
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *head1=NULL,*head2=NULL;
void print(){
  struct node *temp1=head1,*temp2=head2;
  printf("First: ");
  while (temp1!=NULL) {
    printf("%d ",temp1->data);
    temp1=temp1->next;
  }
  printf("\nSecond: ");
  while (temp2!=NULL) {
    printf("%d ",temp2->data);
    temp2=temp2->next;
  }
}
void insert1(int d){
  struct node *temp=(struct node*)malloc(1*sizeof(struct node));
  temp->data=d;
  temp->next=NULL;
  if(head1==NULL){
    head1=temp;
    return;
  }
  temp->next=head1;
  head1=temp;
}
void insert2(int d){
  struct node *temp=(struct node*)malloc(1*sizeof(struct node));
  temp->data=d;
  temp->next=NULL;
  if(head2==NULL){
    head2=temp;
    return;
  }
  temp->next=head2;
  head2=temp;
}

void copy_linked_list(){
  struct node *prev1=head1,*temp1=head1,*temp2=head2;
  while(temp1 && temp2){
    if(temp1->data>temp2->data){
      head2=head2->next;
      temp2->next=temp1;
      if(head1==temp1){
        head1=temp2;
        prev1=head1;
      }else{
        prev1->next=temp2;
        prev1=temp2;
      }
      temp2=head2;
    }else{
      prev1=temp1;
      temp1=temp1->next;
    }
  }
  if(!temp1){
    prev1->next=temp2;
  }
}
int main(){
  //struct node* ptr;
  insert2(11);insert2(9);insert2(8);insert2(7);insert2(5);insert2(4);
  insert1(13);insert1(12);insert1(10);insert1(9);insert1(2);insert1(2);insert1(1);
  print();
  printf("\nAFTER COPYING\n");
  copy_linked_list();
  print();
  return 0;
}

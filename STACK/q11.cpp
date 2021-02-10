//REVERSE LINKED LIST USING STACK
#include<iostream>
#include<stack>
using namespace std;
struct node{
  char data;
  node *next;
}*head=NULL;
void pushStringInLL(char ch){
  node *temp=new node;
  temp->data=ch;
  temp->next=head;
  if(head==NULL){
    head=temp;
    return;
  }
  head=temp;
}
void reverseLLUsingStack(){
  stack<node*> s;
  node *temp=head;
  while(temp!=NULL){
    s.push(temp);
    temp=temp->next;
  }
  temp=s.top();
  head=temp;
  s.pop();
  while(!s.empty()){
    temp->next=s.top();
    s.pop();
    temp=temp->next;
  }
  temp->next=NULL;
}
void printLL(){
  node *temp=head;
  while(temp!=NULL){
    cout<<temp->data;
    temp=temp->next;
  }
}
int main(){
  string str;
  cout<<"Enter string to push into LL: ";
  getline(cin,str);
  for(int i=str.length()-1;i>=0;i-=1){
    pushStringInLL(str[i]);
  }
  reverseLLUsingStack();
  printLL();
}

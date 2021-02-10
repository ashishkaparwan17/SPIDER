//REVERSE STRING USING STACK

#include<iostream>
#include<stack>
using namespace std;
void reverseStringUsingStack(string str){
  stack<char> s;
  for(int i=0;i<str.length();i+=1){
    s.push(str[i]);
  }
  for(int i=0;i<str.length();i+=1){
    str[i]=s.top();
    s.pop();
  }
  cout<<"Reversed string:  "<<str;
}
int main(){
  string str;
  cout<<"Enter string:  ";
  getline(cin,str);
  reverseStringUsingStack(str);
}

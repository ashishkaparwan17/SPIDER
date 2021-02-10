// link: https://practice.geeksforgeeks.org/problems/count-the-reversals/0/?category[]=Stack&category[]=Stack&problemType=full&page=1&query=category[]StackproblemTypefullpage1category[]Stack
// topic: Count the Reversals

#include <bits/stdc++.h>
using namespace std;

int main() {
  int ts,i;
  cin>>ts;
  cin.ignore();
  while(ts--){
    string str;
    cin>>str;
    int count=0;
    if(str.length()%2==0){
      stack<char> s;
      s.push(str[0]);
      for(i=1;i<str.length();i+=1){
        if(!s.empty() && s.top()=='{' && str[i]=='}'){
          s.pop();
        }else{
          s.push(str[i]);
        }
      }
      if(s.empty()){
        cout<<0<<endl;
      }
      else{
        string x="";
        while(!s.empty()){
          x.push_back(s.top());
          s.pop();
        }
        reverse(x.begin(),x.end());
        for(i=1;i<x.length();i+=2){
          if((x[i-1]=='{'&& x[i]=='{') || (x[i-1]=='}' && x[i]=='}')){
            count+=1;
          }else{
            count+=2;
          }
        }
        cout<<count<<endl;
      }
    }else{
      cout<<-1<<endl;
    }
  }
  return 0;
}

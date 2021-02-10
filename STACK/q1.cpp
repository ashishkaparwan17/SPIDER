// LINK: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/i-hate-even-subarrays/
// TITLE: I HATE EVEN SUBARRAYS

#include<bits/stdc++.h>
using namespace std;
int main(){
  int ts,i,l;
  cin>>ts;
  string str;
  while(ts--){
    stack<char> stck;
    cin>>str;
    stck.push(str[0]);
    for(i=1;i<str.length();i+=1){
      if(!stck.empty() && stck.top()==str[i]){
        stck.pop();
      }else{
        stck.push(str[i]);
      }
    }
    if(stck.empty())
      cout<<"KHALI";
    else{
      string ans;
      int j;
      while(!stck.empty()){
        ans.push_back(stck.top());
        stck.pop();
      }
      for(j=ans.length()-1;j>=0;j-=1){
        cout<<ans[j];
      }
    }
    cout<<endl;
  }
}

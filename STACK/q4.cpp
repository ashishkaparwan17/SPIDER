// TITLE: Fun Game <Capillary>
// LINK: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/fun-game-91510e9f/submissions/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
  int i,n;
  cin>>n;
  stack<int> s1,s2;
  vector<int> v(n);
  for(i=0;i<n;i+=1){
    cin>>v[i];
    s2.push(v[i]);
  }
  for(i=n-1;i>=0;i-=1){
    s1.push(v[i]);
  }
  while(!s1.empty() && !s2.empty()){
    if(s1.top()>s2.top()){
      cout<<1<<" ";s2.pop();
    }else if(s1.top()<s2.top()){
      cout<<2<<" ";s1.pop();
    }else{
      cout<<0<<" ";s1.pop();s2.pop();
    }
  }
}

// LINK: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
// TITLE: A GAME OF NUMBERS

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    vector<int> v(n),next_greater(n),next_smaller(n);
    for(i=0;i<n;i+=1) cin>>v[i];
    stack<int> s;
    s.push(0);
    for(i=1;i<n;i+=1){
      while(!s.empty() && v[s.top()]<v[i]){
        next_greater[s.top()]=i;
        s.pop();
      }
      s.push(i);
    }
    while(!s.empty()){
      next_greater[s.top()]=-1;
      s.pop();
    }
    s.push(0);
    for(i=1;i<n;i+=1){
      while(!s.empty() && v[s.top()]>v[i]){
        next_smaller[s.top()]=i;
        s.pop();
      }
      s.push(i);
    }
    while(!s.empty()){
      next_smaller[s.top()]=-1;
      s.pop();
    }
    //   3 7  1 7  8 4  5  2
    //G: 1 4  3 4 -1 6 -1 -1
    //S: 2 2 -1 5  5 7  7 -1
    for(i=0;i<n;i+=1){
      if(next_greater[i]!=-1 && next_smaller[next_greater[i]]!=-1){
        cout<<v[next_smaller[next_greater[i]]]<<" ";
      }else{
        cout<<-1<<" ";
      }
    }
}

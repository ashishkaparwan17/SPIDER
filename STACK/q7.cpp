// https://practice.geeksforgeeks.org/problems/remove-repeated-digits-in-a-given-number/0/?category[]=Stack&category[]=Stack&problemType=full&page=1&query=category[]StackproblemTypefullpage1category[]Stack
// title: Remove repeated digits in a given number

#include <bits/stdc++.h>
using namespace std;

int main() {
  int ts;
  cin>>ts;
  while(ts--){
    long long n;
    cin>>n;
    stack<int> s;
    s.push(n%10);
    n/=10;
    while(n!=0){
      if(n%10!=s.top())
      s.push(n%10);
      n/=10;
    }
    n=0;
    while(!s.empty()){
      n+=s.top();
      n*=10;
      s.pop();
    }
    cout<<n/10<<endl;
  }
  return 0;
}

// TITLE: Stack and Queue <Nissan>
// LINK: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/staque-1-e790a29f/submissions/

#include<bits/stdc++.h>
using namespace std;
int main(){
  long i,j,n,k;
  cin>>n>>k;
  long arr[n],sum=0,maxSum;
  for(i=0;i<n;i+=1) cin>>arr[i];
  for(i=0;i<k;i+=1){
    sum+=arr[i];
  }
  maxSum=sum;
  for(i=k-1,j=n-1;i>0;i-=1,j-=1){
    sum=sum+arr[j]-arr[i];
    maxSum=max(sum,maxSum);
  }
  cout<<maxSum;
}

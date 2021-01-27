#include<bits/stdc++.h>
using namespace std;
//O(n*log(logn))
int main(){
  int n,i,j;
  cin>>n;
  bool arr[n+1]={0};
  //   1 2 3 4 5 6 7 8 9 10 11
  // 0 0 0 0 1 0 1 0 1 1 1  0
  for(i=2;i*i<=n;i+=1){
    if(arr[i]==0){
      for(j=i*i;j<=n;j+=i){
        arr[j]=1;
      }
    }
  }
  for(i=2;i<=n;i+=1){
    if(arr[i]==0)
      cout<<i<<" ";
  }
}

// link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/submissions/
// title: Array Formation <Liv.ai>

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	int i,j,arr[n];
	for(i=0;i<n;i+=1) cin>>arr[i];
	bool sieve[1000001]={0};
	for(i=2;i*i<1000001;i+=1){
		if(sieve[i]==0){
			for(j=i*i;j<1000001;j+=i){
				sieve[j]=1;
			}
		}
	}
	stack<int> s;
	queue<int> q;
	for(i=0;i<n;i+=1){
		if(sieve[arr[i]]==0){
			q.push(arr[i]);
		}else{
			s.push(arr[i]);
		}
	}
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

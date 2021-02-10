// title: Minimum Add to Make Parentheses Valid
// link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/minimum-add-to-make-parentheses-valid-9cba6259/submissions/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin>>str;
	stack<char> s;
	int i;
	s.push(str[0]);
	// ( ) ) ) ( (
	for(i=1;str[i];i+=1){
		if(!s.empty() && s.top()=='(' && str[i]==')'){
			s.pop();
		}else{
			s.push(str[i]);
		}
	}
	cout<<s.size();
}

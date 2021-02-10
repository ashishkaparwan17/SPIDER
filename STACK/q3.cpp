// TITLE: BALANCED BRACKETS
// LINK: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/submissions/

#include <iostream>
#include <stack>
using namespace std;
int main() {
	int i,n,f;string str;
	cin>>n;
	while(n--){
		stack<char> s;f=0;
    cin>>str;
		for(i=0;i<str.length();i+=1){
			if(str[i]=='('||str[i]=='{'||str[i]=='['){
				s.push(str[i]);
			}else if((str[i]==')'||str[i]=='}'||str[i]==']') && s.empty()){
        f=1;break;
      }else if( (str[i]==')' &&  s.top()!='(') || (str[i]=='}' &&  s.top()!='{') || (str[i]==']' &&  s.top()!='[') ){
        f=1;break;
			}else{
        s.pop();
      }
		}
    if(f==1 || !s.empty()){
      cout<<"NO"<<endl;
    }else{
      cout<<"YES"<<endl;
    }
	}
}

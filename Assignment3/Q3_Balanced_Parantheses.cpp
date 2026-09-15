#include<iostream>
#include<stack>
using namespace std;

int main(){
	string exp;
	cin>>exp;
	
	stack<char> s;
	
	for(char ch : exp){
		if(ch=='(')
		s.push(ch);
	else if(ch==')'){
		if(s.empty()){
			cout<<"not balanced";
			return 0;
		}
		s.pop();
	}
	}
	if(s.empty())
		cout<<"balanced";
	else
		cout<<"not balanced";
	
	return 0;
}

#include <iostream>
#include<stack>
using namespace std;

int main(){
	string str;
	cin>>str;
	
	stack<char> s;
	
	for(char ch:str)
		s.push(ch);
		
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	return 0;
}

#include<iostream>
#include<stack>
using namespace std;

int priority(char ch)
{
  if(ch =='^')
    return 3;
  if(ch == '*' || ch == '/')
    return 2;
  if(ch == '+' || ch =='-')
    return 1;

  return 0;
}

int main(){
  string exp;
  cin>> exp;

  stack<char> s;
  string result = "";

  for(char ch : exp){
    if(isalnum(ch)){
      result += ch;
    }
    else if(ch =='(')
    {
      s.push(ch);
    }
    else if(ch == ')'){
      while(!s.empty() && s.top() != '('){
        result += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }
  while(!s.empty()){
    result += s.top();
    s.pop();
  }
  cout<<result;
  return 0;
}

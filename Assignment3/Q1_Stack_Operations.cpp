#include<iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top=-1;

void push(int value){
	if(top==MAX - 1)
		cout<<"Stack Overflow.\n";
	else
		stackArr[++top]=value;
}

void pop(){
	if(top==-1)
		cout<<"Stack overflow\n";
	else
		cout<<"Popped:"<< stackArr[top--]<<endl;
}

void isEmpty(){
	if (top==-1)
		cout<<"Stack is Empty.\n";
	else
		cout<<"Stack is Not Empty.\n";
}

void isFull(){
	if(top ==MAX -1)
		cout<<"Stack is Full\n";
	else
		cout<<"Stack is not full\n";
}

void peek(){
	if(top==-1)
		cout<<"Stack is Empty\n";
	else
		cout<<"Top element:"<<stackArr[top]<<endl;
}

void display(){
	if (top==-1){
		cout<<"Stack is empty\n";
		return;
	}
	for(int i=top; i>=0;i--)
		cout<<stackArr[i]<<" ";
		
	cout<<endl;
}

int main(){
	int choice, value;
	
	do{
		cout<<"\n1.Push";
		cout<<"\n2.Pop";
		cout<<"\n3.isEmpty";
		cout<<"\n4.isFull";
		cout<<"\n5.Peek";
		cout<<"\n5.display";
		cout<<"Enter choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter value:";
				cin>>value;
				push(value);
				break;
		}
		
			case 2:
				pop();
				break;
				
			case 3:
				isEmpty();
				break;
				
			case 4:
				isFull();
				break;
			
			case 5:
				display();
				break;
				
			case 6:
				peek();
				break;
			
			case 7:
				cout<<"Exiting....";
				break;
			
			default:
				cout<<"Invalid choice\n";
	}
}while(choice!=7);
	
	  return 0;
}

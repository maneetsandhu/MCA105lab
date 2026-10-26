#include<iostream>
using namespace std;

#define MAX 100
 int queueArr[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if((rear+1)%MAX == front)
    {
        cout<<"queue is full\n";
    }
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%MAX;
        }
        queueArr[rear]= value;
        cout<<"Element inserted\n";
        
    }
}

void dequeue(){
    if(front == -1){
        cout<<"Queue is Empty\n";
    }
    else{
        cout<<"Deleted element:"<<queueArr[front]<<endl;
        if(front ==rear){
            front = -1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }
}

void isEmpty(){
    if(front==-1)
        cout<<"queue is empty\n";
    else
        cout<<"queue is not empty";
}

void isFull(){
    if((rear + 1)%MAX==front)
        cout<<"queue is fll\n";
    else
        cout<<"queue is empty\n";
}

void display(){
    if(frnt==-1){
        cout<<"queue is empty\n";
        return;
    }
    int i= front;
    while(true)
        {
            cout<<queueArr[i]<<" ";
            if (i == rear)
                break;
            i=(i+1)%MAX;
        }
}

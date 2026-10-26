#include<iostream>
using namespace std;

#define MAX 100
 int queueArr[MAX];
int front = -1;
int rear = -1;
void enqueue(int value){
    if(rear ==MAX -1){
        cout<<"Queue is full.";
    }
    else{
        if(front == -1)
            front =0;
        rear++;
        queueArr[rear] = value;
        cout<<"element inserted.";
    }
}

int main(){
    int value;
    cin>>value;
    enqueue(value);
    
    return 0;
}

#include<iostream>
using namespace std;

#define MAX 100
 int queueArr[MAX];
int front = -1;
int rear = -1;

void isFull(){
    if(rear == MAX -1)
        cout<<"Queue is full";
    else
        cout<<"queue is not full";
}

int main(){
    isFull();
    return 0;
}

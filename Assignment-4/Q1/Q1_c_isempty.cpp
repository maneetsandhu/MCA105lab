#include<iostream>
using namespace std;

#define MAX 100
 int queueArr[MAX];
int front = -1;
int rear = -1;

void isEmpty(){
    if(front ==-1 || front>rear)
        cout<<"Queue is empty";
    else
        cout<<"queue is not empty";
}

int main(){
    isEmpty();
    return 0;
}

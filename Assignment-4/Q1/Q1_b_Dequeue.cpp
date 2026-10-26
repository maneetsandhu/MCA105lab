#include<iostream>
using namespace std;

#define MAX 100
 int queueArr[MAX];
int front = -1;
int rear = -1;

void dequeue(){
    if(front == -1 || front>rear){
        cout<<"queue is empty";
    }
    else{
        cout<<"deleted element:"<<queueArr[front];
        front++;
    }
}
int main(){
    queueArr[++rear]=10;
    queueArr[++rear]=20;
    queueArr[++rear]=30;
    front = 0;

    dequeue();
    return 0;
}

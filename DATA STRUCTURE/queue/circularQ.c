#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max],rear=-1,front=-1;

int isFull() {
    return ( front == (rear+1)%max);
}
int isEmpty() {
    return ( front== -1);
}

void enqueue() {
    if(isFull()) {
        printf("queue is full\n");
        return;
    }
    int data;
    printf("enter the data to be inserted : ");
    scanf("%d",&data);
    if(front == -1) 
        front = rear = 0;
    else
        rear = (rear + 1) % max;
    queue[rear] = data;
    printf("%d inserted\n",data);
}

void dequeue() {
    if(isEmpty()) {
        printf("queue is empty\n");
        return;
    }
    int data = queue[front];
    printf("%d deleted successfully\n",data);
    if(front == rear) {
        front = rear = -1;
    }
    else {
        front = (front+1) % max;
    }
}
void display() {
    if(isEmpty()) {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements are : \n");
    int i = front;
    while(1){
        printf("%d ",queue[i]);
        if (i == rear)
            break;
        i = (i+1) % max;
    }
    printf("\n");
}
int main() {
    int choice;
    while(1) {
        printf("\n1.enqueue  2.dequeue  3.display  4.exit  : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: printf("enter a valid number!");
        }
    }
}
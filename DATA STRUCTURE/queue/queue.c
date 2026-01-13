#include<stdio.h>
#include<stdlib.h>

#define max 10

int queue[max];
int rear=-1,front=-1;

void enqueue();
void dequeue();
void display();
int isFull();
int isEmpty();

int main() {
	while (1) {
		int choice;
		printf("Enter 0 to print, 1 to enqueue, 2 to dequeue, 5 to exit: ");
		scanf("%d", &choice);
		switch(choice) {
			case 0:
				display();
				break;
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	}
    return 0;
}


int isEmpty() {
    if(front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(rear == max-1) {
        return 1;
    }
    return 0;
}

void display() {
    if(isEmpty()) {
        printf("queue is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void enqueue() {
    if(isFull()) {
        printf("overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    int item;
    printf("element : ");
    scanf("%d",&item);
    rear++;
    queue[rear] = item;
    display();
}

void dequeue() {
    if(isEmpty()) {
        printf("underflow");
        return;
    }
    int element = queue[front];
    front++;
    if(front>rear) {
        front = rear = -1;
    }
    display();
}

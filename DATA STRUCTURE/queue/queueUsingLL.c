#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front=NULL,*rear = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue() {
    int data;
    printf("enter the data to be inserted : ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    if(front == NULL) {
        front = rear = newNode;
        printf("entered the data : ",data);
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("entered the data : ",data);
}

void dequeue() {
    if(front == NULL) {
        printf("queue is empty\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    printf("%d is deleted",temp->data);
    if(front == NULL) {
        rear = NULL;
    }
    free(temp);
}
void display() {
    if(front == NULL) {
        printf("queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("queue : \n");
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice;
    while(1) {
        printf("\n1.enqueue 2.dequeue 3.display 4.exit : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:exit(0);break;
            default: printf("enter a valid number ");
        }
    }
}
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push() {
    int data;
    printf("enter the value : ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    printf("%d pushed to the stack\n",data);
}

void pop() {
    if(top == NULL) {
        printf("stack underflow!\n");
        return;
    }   
    struct Node *temp = top;
    top = top->next;
    printf("deleted %d from stack\n",temp->data);
    free(temp);
}

void display() {
    if(top == NULL) {
        printf("stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    while(temp != NULL) {
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while(1){
        printf("choose an option\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            break;
            default:
            printf("enter a valid number!\n");
        }
    }
}
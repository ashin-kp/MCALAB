#include<stdio.h>
#define max 50
int stack[max],top=-1;

void push() {
    if(top == max-1) {
        printf("stack overflow! \n ");
        return;
    }
    int num;
    printf("enter the number : ");
    scanf("%d",&num);
    stack[++top] = num;
    printf("entered to the stack\n");
}
void pop(){
    if(top== -1) {
        printf("stack underflow! \n");
        return;
    }
    printf("deleted %d from stack",stack[top]);
    top--;
}

void display() {
    if(top == -1) {
        printf("stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--) {
        printf("%d ",stack[i]);
    }
}

void main() {
    int choice;
    while(1) {
        printf("enter 1 to push, 2 to pop ,3 to display and 4 to exit : ");
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
            return;
            break;
            default:
            printf("enter a valid number : \n");
        }
    }
}
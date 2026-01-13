#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;

void display();

struct Node *createNode(){
    int data;
    printf("enter a data : ");
    scanf("%d",&data);
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//insert at beginning 

void insertAtBeginning() {
    struct Node *newNode = createNode();
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    display();
}

//insert at end

void insertAtEnd() {
    struct Node *newNode = createNode();
    if(head == NULL) {
        head = newNode;
        display();
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    display();
}

//insert at position

void insertAtPosition() {
    printf("enter the position : ");
    int pos;
    scanf("%d",&pos);
    if(pos == 1) {
        insertAtBeginning();
        return;
    }
    struct Node *newNode = createNode();
    struct Node *temp = head;
    for(int i=1;i<pos-1 && temp!= NULL;i++) {
        temp = temp->next;
    }
    if(temp == NULL){
        printf("position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    //check whether there is another node if there is make its pre as new node
    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    display();
}

void display() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d - > ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtBeginning() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node *temp = head;
    if(head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node *temp = head;
    if(head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPostition() {
    printf("enter a position : ");
    int pos;
    scanf("%d",&pos);
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }

    if(pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    for(int i=1;i<pos && temp!=NULL;i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("position out of range\n");
        return;
    }
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next; 
    free(temp);
}

int main() {
    int choice;
    while(1) {
        printf("\n1.insert at beg 2.insert at end 3.insert at position 4.display 5.exit : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:insertAtBeginning();break;
            case 2:insertAtEnd();break;
            case 3:insertAtPosition();break;
            case 4:display();break;
            case 5:exit(0);break;
            default:printf("enter a valid number!");
        }
    }
}
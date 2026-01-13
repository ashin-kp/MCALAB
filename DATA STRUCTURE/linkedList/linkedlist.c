#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void display();

struct Node *createNode() {
    int data;
    printf("enter the data : ");
    scanf("%d",&data);
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning() {
    struct Node *newNode = createNode();
    newNode->next = head;
    head = newNode;
    display();
}

void insertAtEnd() {
    struct Node *newNode = createNode();
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    display();
}

void insertAtPosition() {
    int pos;
    printf("enter the position : ");
    scanf("%d",&pos);
    //insert at beginning
    if(pos <= 0) {
        printf("invalid position!\n");
        return;
    }
    struct Node *newNode = createNode();
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for(int i=1;i< pos-1 && temp!=NULL;i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    display();
}

void deleteAtBeginning() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    display();
}

void deleteAtEnd() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    if(head->next == NULL) { //only one node
        free(head);
        head = NULL;
        return;
    }
    struct Node *prev = NULL , *curr = head;
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    display();

}

void deleteAtPosition() {
    int pos;
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    printf("enter the position : ");
    scanf("%d",&pos);
    if(pos == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL , *curr = head;
    for(int i=1;i<pos && curr != NULL;i++) {
        prev = curr;
        curr = curr->next;
    } 
    if(curr == NULL) {
        printf("position out of range!\n");
        return;
    }
    prev->next = curr->next;
    free(curr);
    display();

}


void display() {
    if(head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice;
    while(1) {
        printf("\n1.insert at first 2.insert at end 3.insert at position 4.delete at beg 5.delete at end 6.delete at pos 7.display 8.exit : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:insertAtBeginning();break;
            case 2:insertAtEnd();break;
            case 3:insertAtPosition();break;
            case 4:deleteAtBeginning();break;
            case 5:deleteAtEnd();break;
            case 6:deleteAtPosition();break;
            case 7:display();break;
            case 8:exit(1);break;
            default:printf("enter a valid number!");
        }
    }
}
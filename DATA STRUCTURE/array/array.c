#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int arr[MAX];
int size = -1;

void insert() {
    int num,pos;
    printf("enter the element to be inserted : ");
    scanf("%d",&num);
    printf("enter the position : ");
    scanf("%d",&pos);

    pos--;

    if( pos < 0 || pos > size +1 || size >= MAX-1) {
        printf("position is invalid\n");
        return;
    }
    for(int i=size; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = num;
    size++;
    printf("element inserted successfully");
}

void display() {
    if(size<0) {
        printf("array is empty\n");
        return;
    }
    printf("elements are : \n");
    for(int i=0; i<=size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void delete() {
    int pos;
    printf("enter the position of the element to delete : ");
    scanf("%d",&pos);
    pos--;
    if(size < 0) {
        printf("array is empty \n");
        return;
    }
    if(pos < 0 || pos > size) {
        printf("invalid position\n");
        return;
    }
    printf("element deleted is %d",arr[pos]);
    for(int i=pos; i < size ;i++){
        arr[i] = arr[i+1];
    }
    size--;
 }

 void search() {
    int key,found=0;
    printf("enter the element to search : ");
    scanf("%d",&key);
    for(int i=0;i<=size;i++) {
        if(arr[i] == key) {
            found = 1;
            printf("item is found at the position %d",i+1);
            break;
        }
    }
    if(!found) {
        printf("element is not found at the array\n");
    }
}
int main() {
    while(1) {
        int choice;
        printf("enter 1 to insert,2 to display,4 to exit : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            insert();
            break;
            case 2:
            display();
            case 4:
            exit(0);
            break;
            default:
            printf("enter a valid number\n");
        }
    }
}
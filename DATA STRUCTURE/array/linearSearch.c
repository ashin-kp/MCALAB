#include<stdio.h>

int search(int a[],int n,int key) {
    for(int i=0;i<n;i++) {
        if(a[i] == key)
            return i+1;
    }
    return -1;
}

int main () {
    int n,temp,a[50],key;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the elements : ");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("enter the key to search : ");
    scanf("%d",&key);
    int result  = search(a,n,key);
    if(result == -1) {
        printf("item not found");
    }
    else {
        printf("item found at the %d position",result);
    }
}
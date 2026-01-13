#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[50],b[50],c[100],n1,n2,i=0,j=0,k=0;
    printf("enter the size of array 1 : ");
    scanf("%d",&n1);
    printf("enter elements of the sorted array : ");
    for(i=0;i<n1;i++) {
        scanf("%d",&a[i]);
    }
    printf("enter the size of array 2 : ");
    scanf("%d",&n2);
    printf("enter elements of the sorted array : ");
    for(i=0;i<n2;i++) {
        scanf("%d",&b[i]);
    }
    i=0;
    while(i<n1 && j<n2) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } 
        else {
            c[k++] = b[j++];
        }
    }
    while(i < n1) {
        c[k++] = a[i++];
    }
    while(j < n2) {
        c[k++] = b[j++];
    }
    printf("merge sorted array : \n");
    for(i=0;i<k;i++) {
        printf("%d ",c[i]);
    }
}
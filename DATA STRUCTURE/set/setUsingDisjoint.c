#include<stdio.h>

#define max 100

int parent[max];

void makeSet(int n) {
    for(int i=0;i<n;i++) 
        parent[i] = i;
}

int findSet(int i) {
    while( i!=parent[i]) {
        i = parent[i];
    }
    return i;
}

void unionSet(int a,int b) {
    int A = findSet(a);
    int B = findSet(b);

    if(A != B) {
        parent[A] = B;
        printf("union done between %d and %d \n",a,b);
    }
    else {
        printf("they are already in the same set\n");
    }
}
void display(int n) {
    printf("element : parent\n");
    for(int i=0;i<n;i++) {
        printf("%d : %d\n",i,findSet(i));
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while (1) {
        printf("\n1. Find\n2. Union\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                printf("Set representative of %d is %d\n", x, findSet(x));
                break;

            case 2:
                printf("Enter two elements: ");
                scanf("%d %d", &x, &y);
                unionSet(x, y);
                break;

            case 3:
                display(n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
#include<stdio.h>
#define max 100

int adj[max][max];
int visited[max];
int queue[max];
int front=-1,rear=-1;

void enqueue(int value) {
    if(rear == max-1) {
        printf("queue overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int isEmpty() {
    if(front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

int dequeue() {
    if(front == -1 || front>rear){
        printf("queue underflow\n");
        return -1;
    }
    return queue[front++];
}

void BFS(int start,int n) {
    front = rear = -1;
    int current;
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()) {
        current = dequeue();
        printf("%d ",current);
        for(int i=0;i<n;i++) {
            if(adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n,e,u,v,start;
    printf("enter the nof of vertices : ");
    scanf("%d",&n);

    //initialixa adj matrix
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            adj[i][j] = 0;
        }
    }
    //initializa visited
    for(int i=0;i<n;i++) {
        visited[i] = 0;
    }

    //
    printf("enter the no of edges : ");
    scanf("%d",&e);

    for(int i=0;i<e;i++) {
        printf("enter the edge from u to v : ");
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    printf("enter the starting vertex : ");
    scanf("%d",&start);
    BFS(start,n);
    return 0;

}
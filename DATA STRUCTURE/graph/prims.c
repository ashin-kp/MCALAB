#include<stdio.h>

#define max 100
#define INF 9999

int adj[max][max];
int visited[max];


void Prims(int start,int n) {
    int total_cost = 0;
    int edges = 0;

    visited[start] = 1;

    printf("edges in mst : ");

    while(edges < n-1) {
        int min = INF;
        int u = -1;
        int v = -1;

        for(int i=0;i<n;i++) {
            if(visited[i] == 1) {
                for(int j=0;j<n;j++) {
                    if(visited[j] == 0 && adj[i][j] != 0 ) {
                        if( adj[i][j] < min) {
                            min = adj[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            } 
        }
        printf("%d - %d : %d\n",u,v,min);
        visited[v] = 1;
        total_cost += min;
        edges++;
    }
    printf("total cost = %d\n",total_cost);
}


int main() {
    int n,e,u,v,start,cost;

    printf("enter the no of vertices : ");
    scanf("%d",&n);

    //initialize the matrix with 0
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            adj[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++)
        visited[i] = 0;

    printf("enter the no of edges : ");
    scanf("%d",&e);

    for(int i=0;i<e;i++) {
        printf("enter the edge from u to v and cost ( u v cost) : ");
        scanf("%d %d %d",&u,&v,&cost);
        adj[u][v] = cost;
        adj[v][u] = cost;
    }

    printf("enter the starting vertex : ");
    scanf("%d",&start);

    Prims(start,n);

    return 0;
}
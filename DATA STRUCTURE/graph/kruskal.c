#include <stdio.h>

#define max 100
#define INF 9999

int adj[max][max];
int parent[max];

/* Find parent (Disjoint Set) */
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

/* Union two sets */
void unionSet(int a, int b) {
    parent[a] = b;
}

void Kruskals(int n) {
    int total_cost = 0;
    int edges = 0;


    printf("edges in mst : \n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1;
        int v = -1;

        /* Find minimum edge */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] != 0 && adj[i][j] < min) {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int a = find(u);
        int b = find(v);

        if (a != b) {
            printf("%d - %d : %d\n", u, v, min);
            total_cost += min;
            unionSet(a, b);
            edges++;
        }

        /* Remove used edge */
        adj[u][v] = adj[v][u] = INF;
    }

    printf("total cost = %d\n", total_cost);
}

int main() {
    int n, e, u, v, cost;

    printf("enter the no of vertices : ");
    scanf("%d", &n);

    /* Initialize adjacency matrix */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    /* Initialize parent array */
    for (int i = 0; i < n; i++)
        parent[i] = i;
        

    printf("enter the no of edges : ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("enter the edge from u to v and cost (u v cost) : ");
        scanf("%d %d %d", &u, &v, &cost);
        adj[u][v] = cost;
        adj[v][u] = cost;
    }

    Kruskals(n);

    return 0;
}

// Question 5: Write a program to perform BFS and DFS traversal on a graph represented using adjacency matrix.

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1) return -1;
    int v = queue[front++];
    if (front > rear) front = rear = -1;
    return v;
}

// BFS function
void BFS(int start) {
    int v;
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS: ");
    while (front != -1) {
        v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS function
void DFS_util(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            DFS_util(i);
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    DFS_util(start);
    printf("\n");
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);
    DFS(start);

    return 0;
}

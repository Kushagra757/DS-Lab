
  //9a) C Program to Traverse a Graph Using BFS

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n;

/* Insert into queue */
void enqueue(int v)
{
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

/* Delete from queue */
int dequeue()
{
    return queue[front++];
}

/* BFS Traversal */
void bfs(int start)
{
    int i, v;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
  


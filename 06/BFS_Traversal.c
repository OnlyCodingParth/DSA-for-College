#include <stdio.h>

#define MAX 20

int main()
{
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int queue[MAX];

    int vertices, edges;
    int source, destination;
    int front = 0, rear = -1;
    int start, current;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0)
    {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter edges (source destination):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &source, &destination);

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices)
        {
            printf("Invalid edge. Enter the edge again.\n");
            i--;
            continue;
        }

        adj[source][destination] = 1;
        adj[destination][source] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= vertices)
    {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    visited[start] = 1;
    queue[++rear] = start;

    printf("\nBFS Traversal: ");

    while (front <= rear)
    {
        current = queue[front++];

        printf("%d ", current);

        for (j = 0; j < vertices; j++)
        {
            if (adj[current][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    }

    printf("\n");

    return 0;
}

/*
Algorithm:
1. Start the program.
2. Read the number of vertices and edges.
3. Create and initialize the adjacency matrix.
4. Read all edges and construct the undirected graph.
5. Read the starting vertex.
6. Mark the starting vertex as visited.
7. Insert the starting vertex into the queue.
8. Repeat while the queue is not empty:
   a. Remove a vertex from the front of the queue.
   b. Display the removed vertex.
   c. Check all its adjacent vertices.
   d. If an adjacent vertex is unvisited:
      - Mark it as visited.
      - Insert it into the queue.
9. Stop when the queue becomes empty.

Time Complexity: O(V^2)
Space Complexity: O(V^2)

Where:
V = Number of vertices
E = Number of edges

Note:
- The adjacency matrix requires O(V^2) space.
- The queue and visited array require O(V) auxiliary space.
- This program visits only vertices reachable from the starting vertex.

Sample Output:
Enter number of vertices: 5
Enter number of edges: 5
Enter edges (source destination):
0 1
0 2
1 3
1 4
2 4
Enter starting vertex: 0

BFS Traversal: 0 1 2 3 4

*/
#include <stdio.h>

#define MAX 20

int main()
{
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int stack[MAX];

    int vertices, edges;
    int source, destination;
    int top = -1;
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
    stack[++top] = start;

    printf("\nDFS Traversal: ");

    while (top != -1)
    {
        current = stack[top];

        printf("%d ", current);

        for (j = 0; j < vertices; j++)
        {
            if (adj[current][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                stack[++top] = j;
                break;
            }
        }

        if (j == vertices)
        {
            top--;
        }
    }

    printf("\n");

    return 0;
}

/*
Algorithm:
1. Start the program.
2. Read the number of vertices and edges.
3. Initialize the adjacency matrix and visited array.
4. Read all edges and construct the undirected graph.
5. Read the starting vertex.
6. Mark the starting vertex as visited.
7. Push the starting vertex onto the stack.
8. Repeat while the stack is not empty:
   a. Read the vertex at the top of the stack.
   b. Find its first unvisited adjacent vertex.
   c. If found:
      - Mark it as visited.
      - Push it onto the stack.
   d. If no unvisited adjacent vertex exists:
      - Pop the top vertex.
9. Stop when the stack becomes empty.

Time Complexity: O(V^2)
Space Complexity: O(V^2)

Where:
V = Number of vertices
E = Number of edges

Note:
- The adjacency matrix requires O(V^2) space.
- The stack and visited array require O(V) auxiliary space.
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

DFS Traversal: 0 1 3 4 2

*/
#include <stdio.h>

#define MAX 20

int main()
{
    int adj[MAX][MAX] = {0};
    int vertices, edges;
    int directed;
    int u, v;
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

    printf("Enter 1 for Directed Graph\n");
    printf("Enter 0 for Undirected Graph\n");
    printf("Enter your choice: ");
    scanf("%d", &directed);

    if (edges < 0 || (directed != 0 && directed != 1))
    {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
        {
            printf("Invalid vertex. Enter the edge again.\n");
            i--;
            continue;
        }

        adj[u][v] = 1;

        if (directed == 0)
        {
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }

    return 0;
}

/*
Algorithm:
1. Start the program.
2. Read the number of vertices and edges.
3. Read whether the graph is directed or undirected.
4. Initialize all adjacency matrix elements to 0.
5. Read each edge (u, v).
6. Set adj[u][v] = 1.
7. If the graph is undirected, also set adj[v][u] = 1.
8. Display the adjacency matrix.
9. Stop the program.

Time Complexity:
- Graph initialization: O(V^2)
- Edge insertion: O(E)
- Matrix display: O(V^2)
- Overall: O(V^2 + E)

Space Complexity: O(V^2)

Where:
V = Number of vertices
E = Number of edges

Sample Output:
Enter number of vertices: 4
Enter number of edges: 4
Enter 1 for Directed Graph
Enter 0 for Undirected Graph
Enter your choice: 0
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 2
Enter edge (source destination): 2 3
Adjacency Matrix:
0 1 1 0
1 0 1 0
0 1 0 1
0 0 1 0

*/
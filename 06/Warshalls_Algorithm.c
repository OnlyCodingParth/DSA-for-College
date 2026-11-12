#include <stdio.h>

#define MAX 20

int main()
{
    int adj[MAX][MAX];
    int vertices;
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (0 or 1):\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] != 0 && adj[i][j] != 1)
            {
                printf("Invalid matrix value.\n");
                return 1;
            }
        }
    }

    for (k = 0; k < vertices; k++)
    {
        for (i = 0; i < vertices; i++)
        {
            for (j = 0; j < vertices; j++)
            {
                adj[i][j] = adj[i][j] ||
                            (adj[i][k] && adj[k][j]);
            }
        }
    }

    printf("\nTransitive Closure Matrix:\n");

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

What is the Warshall's Algorithm?
Warshall's Algorithm is a graph algorithm used to compute the transitive closure of a directed graph represented by an adjacency matrix. The transitive closure of a graph indicates whether there is a path between every pair of vertices. The algorithm iteratively updates the adjacency matrix to reflect the reachability of vertices through intermediate vertices.

Algorithm:
1. Start the program.
2. Read the number of vertices.
3. Read the adjacency matrix of the directed graph.
4. Consider each vertex k as an intermediate vertex.
5. Check every pair of vertices (i, j).
6. Update the matrix using:
   adj[i][j] = adj[i][j] OR
               (adj[i][k] AND adj[k][j]).
7. Repeat until all intermediate vertices are considered.
8. Display the transitive closure matrix.
9. Stop the program.

Time Complexity: O(V^3)
Space Complexity: O(V^2)

Where:
V = Number of vertices

Note:
- The algorithm determines whether a path exists between
  every pair of vertices.
- The diagonal is not automatically set to 1.
- A diagonal element becomes 1 if a non-empty cycle exists
  from that vertex back to itself.

Sample Output:
Enter number of vertices: 4
Enter the adjacency matrix (0 or 1):
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0

Transitive Closure Matrix:
0 1 1 1
0 0 1 1
0 0 0 1
0 0 0 0

*/
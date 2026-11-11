#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Node *head[MAX] = {NULL};

void insertEdge(int source, int destination, int weight)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->vertex = destination;
    newNode->weight = weight;
    newNode->next = head[source];

    head[source] = newNode;
}

void displayGraph(int vertices)
{
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n");

    for (i = 0; i < vertices; i++)
    {
        printf("%d -> ", i);

        temp = head[i];

        while (temp != NULL)
        {
            printf("(%d, Weight: %d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void freeGraph(int vertices)
{
    int i;
    struct Node *temp;

    for (i = 0; i < vertices; i++)
    {
        while (head[i] != NULL)
        {
            temp = head[i];
            head[i] = head[i]->next;
            free(temp);
        }
    }
}

int main()
{
    int vertices, edges;
    int source, destination, weight;
    int i;

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

    for (i = 0; i < edges; i++)
    {
        printf("Enter source, destination and weight: ");
        scanf("%d %d %d", &source, &destination, &weight);

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices)
        {
            printf("Invalid vertex. Enter the edge again.\n");
            i--;
            continue;
        }

        insertEdge(source, destination, weight);
    }

    displayGraph(vertices);

    freeGraph(vertices);

    return 0;
}

/*
Algorithm:
1. Start the program.
2. Read the number of vertices and edges.
3. Initialize all adjacency list heads to NULL.
4. Read source, destination and weight for each edge.
5. Create a new node for every edge.
6. Store the destination and weight in the node.
7. Insert the node at the beginning of the source vertex's linked list.
8. Display the adjacency list of every vertex.
9. Free the allocated memory.
10. Stop the program.

Time Complexity:
- Graph initialization: O(V)
- Edge insertion: O(1) per edge
- Displaying the graph: O(V + E)
- Overall: O(V + E)

Space Complexity: O(V + E)

Where:
V = Number of vertices
E = Number of edges

Sample Output:
Enter number of vertices: 4
Enter number of edges: 4
Enter source, destination and weight: 0 1 10
Enter source, destination and weight: 0 2 20
Enter source, destination and weight: 1 2 30
Enter source, destination and weight: 2 3 40

Adjacency List:
0 -> (2, Weight: 20) -> (1, Weight: 10) -> NULL
1 -> (2, Weight: 30) -> NULL
2 -> (3, Weight: 40) -> NULL
3 -> NULL
*/
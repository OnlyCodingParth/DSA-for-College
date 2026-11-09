#include <stdio.h>
#include <stdlib.h>

// Structure defines one node of the linked queue.
struct Node
{
    int data;              // Stores the queue element.
    struct Node *next;     // Stores the address of the next node.
};

// front points to the first node.
// rear points to the last node.
// Initially, the queue is empty.
struct Node *front = NULL;
struct Node *rear = NULL;


// ENQUEUE: Insert an element at the rear of the queue.
void enqueue(int value)
{
    struct Node *newNode;

    // Dynamically allocate memory for a new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Queue Overflow! Memory not available.\n");
        return;
    }

    // Store the given value in the new node.
    newNode->data = value;

    // Since this node will initially be the last node,
    // its next pointer must be NULL.
    newNode->next = NULL;

    // If the queue is empty, the new node becomes both front and rear.
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        // Connect the current last node to the new node.
        rear->next = newNode;

        // Update rear to point to the newly inserted node.
        rear = newNode;
    }

    printf("%d inserted into the queue.\n", value);
}


// DEQUEUE: Remove an element from the front of the queue.
void dequeue()
{
    struct Node *temp;

    // Check whether the queue is empty.
    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    // Store the address of the front node temporarily.
    temp = front;

    // Display the element that is being removed.
    printf("Deleted element: %d\n", front->data);

    // Move front to the next node.
    front = front->next;

    // If the queue becomes empty, rear must also become NULL.
    if (front == NULL)
    {
        rear = NULL;
    }

    // Release the memory occupied by the removed node.
    free(temp);
}


// PEEK: Display the front element without removing it.
void peek()
{
    // Check whether the queue is empty.
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    // Display the element at the front.
    printf("Front element: %d\n", front->data);
}


// DISPLAY: Display all elements of the queue.
void display()
{
    struct Node *temp;

    // Check whether the queue is empty.
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    // Start traversal from the front node.
    temp = front;

    printf("Queue elements (Front to Rear):\n");

    // Traverse the queue until NULL is reached.
    while (temp != NULL)
    {
        printf("%d ", temp->data);

        // Move to the next node.
        temp = temp->next;
    }

    printf("\n");
}


// MAIN FUNCTION: Program execution starts here.
int main()
{
    int choice, value;

    // Continue displaying the menu until the user selects Exit.
    while (1)
    {
        printf("\n----- LINKED QUEUE OPERATIONS -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Select the queue operation using the user's choice.
        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:

                // Release all remaining nodes before terminating.
                while (front != NULL)
                {
                    dequeue();
                }

                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/*
ALGORITHM:

1. Define a node containing data and a next pointer.
2. Initialize front and rear to NULL.

3. ENQUEUE:
   a. Create a new node using malloc().
   b. Store the value in the new node.
   c. Set its next pointer to NULL.
   d. If the queue is empty, update both front and rear.
   e. Otherwise, connect the new node after rear.
   f. Update rear to the new node.

4. DEQUEUE:
   a. Check whether front is NULL.
   b. Store the front node temporarily.
   c. Move front to the next node.
   d. If front becomes NULL, update rear to NULL.
   e. Free the removed node.

5. PEEK:
   a. Check whether the queue is empty.
   b. Display the front element.

6. DISPLAY:
   a. Start traversal from front.
   b. Display each node until NULL is reached.

7. Free all remaining nodes before termination.


TIME COMPLEXITY:

Enqueue    : O(1)
Dequeue    : O(1)
Peek       : O(1)
Display    : O(n)


SPACE COMPLEXITY:

O(n) for storing n queue elements.


SAMPLE OUTPUT:

----- LINKED QUEUE OPERATIONS -----
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit

Enter your choice: 1
Enter value to insert: 10
10 inserted into the queue.

Enter your choice: 1
Enter value to insert: 20
20 inserted into the queue.

Enter your choice: 4
Queue elements (Front to Rear):
10 20

Enter your choice: 2
Deleted element: 10

Enter your choice: 3
Front element: 20
*/


/*

New concepts in this program:
- front and rear pointers: Point to the first and last nodes of the queue.
- enqueue(): Inserts a new node at the rear.
- dequeue(): Removes the node from the front.
- Queue Overflow: Occurs when memory allocation fails.
- Queue Underflow: Occurs when attempting to dequeue from an empty queue.

*/
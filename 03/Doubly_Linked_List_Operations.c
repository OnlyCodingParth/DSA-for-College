#include <stdio.h>

// Structure defines one node of a doubly linked list.
struct Node
{
    int data;              // Stores the actual value.
    struct Node *prev;     // Stores the address of the previous node.
    struct Node *next;     // Stores the address of the next node.
};

// head points to the first node of the list.
struct Node *head = NULL;


// Create a new node and initialize its members.
struct Node *createNode(int value)
{
    struct Node *newNode;

    // Allocate memory dynamically for a new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;

    // Initially, the new node is not connected to any other node.
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


// Insert a node at the beginning.
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = createNode(value);

    // Stop if memory allocation fails.
    if (newNode == NULL)
        return;

    // Connect the new node to the current first node.
    newNode->next = head;

    // If the list is not empty, update the previous pointer of old head.
    if (head != NULL)
    {
        head->prev = newNode;
    }

    // Update head to point to the new first node.
    head = newNode;

    printf("Node inserted successfully.\n");
}


// Insert a node at the end.
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // If the list is empty, the new node becomes the first node.
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Start traversal from the first node.
        temp = head;

        // Move until the last node is reached.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Connect the new node after the current last node.
        temp->next = newNode;

        // Connect the new node back to the previous last node.
        newNode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}


// Insert a node at a specific position (1-based indexing).
void insertPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Position 1 means insertion at the beginning.
    if (position == 1)
    {
        insertBeginning(value);
        return;
    }

    temp = head;

    // Traverse to the node immediately before the required position.
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // Connect the new node to the next node.
    newNode->next = temp->next;

    // Connect the new node to the previous node.
    newNode->prev = temp;

    // If a next node exists, update its previous pointer.
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    // Connect the previous node to the new node.
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


// Delete the first node.
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    // Store the first node temporarily.
    temp = head;

    // Move head to the second node.
    head = head->next;

    // If another node exists, make its previous pointer NULL.
    if (head != NULL)
    {
        head->prev = NULL;
    }

    // Release the memory of the deleted node.
    free(temp);

    printf("Node deleted successfully.\n");
}


// Delete the last node.
void deleteEnd()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    // If only one node exists, delete it and make the list empty.
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Traverse until the last node is reached.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Disconnect the last node from the previous node.
        temp->prev->next = NULL;

        // Release the memory of the last node.
        free(temp);
    }

    printf("Node deleted successfully.\n");
}


// Delete a node from a specific position (1-based indexing).
void deletePosition(int position)
{
    struct Node *temp;
    int i;

    if (head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Position 1 means deletion from the beginning.
    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    // Traverse until the required position is reached.
    for (i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Connect the previous node to the next node.
    temp->prev->next = temp->next;

    // If a next node exists, update its previous pointer.
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Release the memory of the deleted node.
    free(temp);

    printf("Node deleted successfully.\n");
}


// Display the list from beginning to end.
void displayForward()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    temp = head;

    printf("Forward Traversal: NULL <-> ");

    // Traverse using the next pointer.
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


// Display the list from end to beginning.
void displayBackward()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    temp = head;

    // First reach the last node.
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward Traversal: NULL <-> ");

    // Traverse backward using the prev pointer.
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}


// Main function: Program execution starts here.
int main()
{
    int choice, value, position;

    // Keep displaying the menu until Exit is selected.
    while (1)
    {
        printf("\n----- DOUBLY LINKED LIST OPERATIONS -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Select the operation according to the user's choice.
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(value, position);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deletePosition(position);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:

                // Delete every remaining node before termination.
                while (head != NULL)
                {
                    deleteBeginning();
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

1. Define a node containing data, prev and next pointers.
2. Initialize head to NULL.
3. INSERTION:
   a. Create a new node using malloc().
   b. Update the next pointer of the previous node.
   c. Update the prev pointer of the next node.
   d. Update head when inserting at the beginning.
4. DELETION:
   a. Check whether the list is empty.
   b. Locate the node to be deleted.
   c. Update the previous and next node links.
   d. Free the deleted node.
5. FORWARD TRAVERSAL:
   a. Start from head.
   b. Follow next pointers until NULL.
6. BACKWARD TRAVERSAL:
   a. Reach the last node.
   b. Follow prev pointers until NULL.
7. Free all remaining nodes before termination.


TIME COMPLEXITY:

Insert at Beginning       : O(1)
Insert at End             : O(n)
Insert at Position        : O(n)
Delete from Beginning     : O(1)
Delete from End           : O(n)
Delete from Position      : O(n)
Forward Display           : O(n)
Backward Display          : O(n)


SPACE COMPLEXITY:

O(n) for storing n nodes.


SAMPLE OUTPUT:

----- DOUBLY LINKED LIST OPERATIONS -----
1. Insert at Beginning
2. Insert at End
3. Insert at Specific Position
4. Delete from Beginning
5. Delete from End
6. Delete from Specific Position
7. Display Forward
8. Display Backward
9. Exit

Enter your choice: 1
Enter value: 10
Node inserted successfully.

Enter your choice: 2
Enter value: 20
Node inserted successfully.

Enter your choice: 7
Forward Traversal: NULL <-> 10 <-> 20 <-> NULL

Enter your choice: 8
Backward Traversal: NULL <-> 20 <-> 10 <-> NULL
*/

/*

New concepts in this program:
- prev pointer: Points to the previous node in the list.
- next pointer: Points to the next node in the list.
- Forward traversal: Traversing the list from head to tail.
- Backward traversal: Traversing the list from tail to head.

*/
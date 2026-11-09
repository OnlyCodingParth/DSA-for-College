#include <stdio.h>

// Structure defines the data and link part of each node.
struct Node
{
    int data;              // Stores the actual value.
    struct Node *next;     // Stores the address of the next node.
};

// Global head pointer stores the address of the first node.
// NULL means the linked list is initially empty.
struct Node *head = NULL;


// Insert a new node at the beginning.
void insertBeginning(int value)
{
    struct Node *newNode;

    // malloc() dynamically allocates memory for a new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    // Connect the new node to the current first node.
    newNode->next = head;

    // Update head so that it points to the new first node.
    head = newNode;

    printf("Node inserted successfully.\n");
}


// Insert a new node at the end.
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    // Allocate memory for the new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    // Since this node will be the last node, its next is NULL.
    newNode->next = NULL;

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

        // Connect the previous last node to the new node.
        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}


// Insert a node at a specific position (1-based indexing).
void insertPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    // Position must start from 1.
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // If position is 1, use the beginning insertion operation.
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

    // If temp becomes NULL, the requested position is invalid.
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Allocate memory for the new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    // First connect the new node to the next node.
    newNode->next = temp->next;

    // Then connect the previous node to the new node.
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


// Delete the first node.
void deleteBeginning()
{
    struct Node *temp;

    // Check whether the list is empty.
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    // Store the address of the first node temporarily.
    temp = head;

    // Move head to the second node.
    head = head->next;

    // Release the memory occupied by the deleted node.
    free(temp);

    printf("Node deleted successfully.\n");
}


// Delete the last node.
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    // Special case: if only one node exists.
    if (head->next == NULL)
    {
        // Release the only node.
        free(head);

        // Make the list empty.
        head = NULL;
    }
    else
    {
        temp = head;

        // Traverse until the last node is reached.
        while (temp->next != NULL)
        {
            // Keep track of the previous node.
            prev = temp;

            temp = temp->next;
        }

        // Disconnect the last node from the list.
        prev->next = NULL;

        // Release the memory of the last node.
        free(temp);
    }

    printf("Node deleted successfully.\n");
}


// Delete a node from a specific position (1-based indexing).
void deletePosition(int position)
{
    struct Node *temp, *prev;
    int i;

    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // If position is 1, delete the first node.
    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    // Traverse until the node at the required position is reached.
    for (i = 1; i < position && temp != NULL; i++)
    {
        // Store the previous node's address.
        prev = temp;

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Skip the node that needs to be deleted.
    prev->next = temp->next;

    // Release the deleted node's memory.
    free(temp);

    printf("Node deleted successfully.\n");
}


// Search for a particular element.
void search(int value)
{
    struct Node *temp = head;
    int position = 1;

    // Traverse the linked list from the first node.
    while (temp != NULL)
    {
        // Compare the current node's data with the search value.
        if (temp->data == value)
        {
            printf("Element found at position %d.\n", position);
            return;
        }

        // Move to the next node.
        temp = temp->next;

        position++;
    }

    printf("Element not found!\n");
}


// Display all nodes of the linked list.
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked List: ");

    // Continue traversal until NULL is reached.
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);

        // Move to the next node.
        temp = temp->next;
    }

    printf("NULL\n");
}


// Main function: program execution starts here.
int main()
{
    int choice, value, position;

    // Infinite loop keeps displaying the menu until Exit is selected.
    while (1)
    {
        printf("\n----- SINGLY LINKED LIST -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Search Element\n");
        printf("8. Display Linked List\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // switch selects the operation according to the user's choice.
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
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:

                // Release all dynamically allocated nodes before termination.
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
1. Define a node containing data and a next pointer.
2. Initialize head to NULL.
3. Allocate memory dynamically whenever a new node is created.
4. Perform insertion by updating node links.
5. Perform deletion by changing links and freeing memory.
6. Search by comparing each node's data.
7. Display by traversing until NULL is reached.
8. Free all remaining nodes before terminating.

TIME COMPLEXITY:
Insert at Beginning       : O(1)
Insert at End             : O(n)
Insert at Position        : O(n)
Delete from Beginning     : O(1)
Delete from End           : O(n)
Delete from Position      : O(n)
Search                    : O(n)
Display                   : O(n)

SPACE COMPLEXITY:
O(n) for storing n nodes.

SAMPLE OUTPUT:

----- SINGLY LINKED LIST -----
1. Insert at Beginning
2. Insert at End
3. Insert at Specific Position
4. Delete from Beginning
5. Delete from End
6. Delete from Specific Position
7. Search Element
8. Display Linked List
9. Exit

Enter your choice: 1
Enter value: 10
Node inserted successfully.

Enter your choice: 2
Enter value: 20
Node inserted successfully.

Enter your choice: 8
Linked List: 10 -> 20 -> NULL
*/


/*

Important new concepts covered in this program:
- struct Node *next – self-referential structure and pointer.
- malloc() – dynamic memory allocation.
- free() – releasing dynamically allocated memory.
- -> – accessing structure members through a pointer.
- NULL – represents a null pointer.
- temp and prev – temporary pointers used during traversal and deletion.

*/
#include <stdio.h>
#include <stdlib.h>

// Structure defines one node of a circular linked list.
struct Node
{
    int data;              // Stores the actual value.
    struct Node *next;     // Stores the address of the next node.
};

// head points to the first node of the circular linked list.
struct Node *head = NULL;


// Create a new node and initialize its members.
struct Node *createNode(int value)
{
    struct Node *newNode;

    // Dynamically allocate memory for a new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;

    // Initially, the node points to itself.
    // This is necessary when it becomes the only node.
    newNode->next = newNode;

    return newNode;
}


// Insert a node at the beginning.
void insertBeginning(int value)
{
    struct Node *newNode, *temp;

    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // If the circular linked list is empty.
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Find the last node of the circular linked list.
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        // Connect the new node to the current first node.
        newNode->next = head;

        // Connect the last node to the new first node.
        temp->next = newNode;

        // Update head to the newly inserted node.
        head = newNode;
    }

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
        // Find the last node.
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        // Connect the current last node to the new node.
        temp->next = newNode;

        // Connect the new last node back to head.
        newNode->next = head;
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

    if (head == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    // Traverse to the node immediately before the required position.
    for (i = 1; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    // Check whether the requested position is valid.
    if (i != position - 1)
    {
        printf("Invalid position!\n");
        return;
    }

    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // Connect the new node to the next node.
    newNode->next = temp->next;

    // Connect the previous node to the new node.
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


// Delete the first node.
void deleteBeginning()
{
    struct Node *temp, *last;

    if (head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    // Special case: if only one node exists.
    if (head->next == head)
    {
        // Release the only node.
        free(head);

        // Make the list empty.
        head = NULL;
    }
    else
    {
        // Find the last node.
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        // Store the current first node temporarily.
        temp = head;

        // Move head to the second node.
        head = head->next;

        // Connect the last node to the new first node.
        last->next = head;

        // Release the deleted node's memory.
        free(temp);
    }

    printf("Node deleted successfully.\n");
}


// Delete the last node.
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    // Special case: if only one node exists.
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Traverse until the last node is reached.
        while (temp->next != head)
        {
            // Store the previous node's address.
            prev = temp;

            temp = temp->next;
        }

        // Connect the previous node back to head.
        prev->next = head;

        // Release the last node's memory.
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
        printf("Circular linked list is empty!\n");
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

    // Traverse to the required position.
    for (i = 1; i < position && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the requested position does not exist.
    if (i != position)
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
    struct Node *temp;
    int position = 1;

    if (head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    temp = head;

    // A do-while loop processes the first node before checking the condition.
    do
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

    } while (temp != head); // Stop when traversal returns to the first node.

    printf("Element not found!\n");
}


// Display all nodes of the circular linked list.
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    // Use do-while because the first node must be displayed before checking.
    do
    {
        printf("%d -> ", temp->data);

        // Move to the next node.
        temp = temp->next;

    } while (temp != head); // Stop after completing one full circle.

    printf("(Back to Head)\n");
}


// Main function: Program execution starts here.
int main()
{
    int choice, value, position;

    // Keep displaying the menu until the user selects Exit.
    while (1)
    {
        printf("\n----- CIRCULAR LINKED LIST OPERATIONS -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Search Element\n");
        printf("8. Display Circular Linked List\n");
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
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:

                // Release all remaining nodes before terminating.
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
3. In a circular linked list, the last node points back to head.

4. INSERTION:
   a. Create a new node using malloc().
   b. Find the required insertion position.
   c. Update the next pointers.
   d. Maintain the circular connection.

5. DELETION:
   a. Check whether the list is empty.
   b. Handle the single-node condition separately.
   c. Locate the node to be deleted.
   d. Update the links.
   e. Free the deleted node.

6. SEARCH:
   a. Start from head.
   b. Compare each node's data with the search value.
   c. Stop when the element is found or traversal returns to head.

7. DISPLAY:
   a. Start from head.
   b. Display each node.
   c. Stop when traversal returns to head.

8. Free all remaining nodes before termination.


TIME COMPLEXITY:

Insert at Beginning       : O(n)
Insert at End             : O(n)
Insert at Position        : O(n)
Delete from Beginning     : O(n)
Delete from End           : O(n)
Delete from Position      : O(n)
Search                    : O(n)
Display                   : O(n)


SPACE COMPLEXITY:

O(n) for storing n nodes.


SAMPLE OUTPUT:

----- CIRCULAR LINKED LIST OPERATIONS -----
1. Insert at Beginning
2. Insert at End
3. Insert at Specific Position
4. Delete from Beginning
5. Delete from End
6. Delete from Specific Position
7. Search Element
8. Display Circular Linked List
9. Exit

Enter your choice: 1
Enter value: 10
Node inserted successfully.

Enter your choice: 2
Enter value: 20
Node inserted successfully.

Enter your choice: 8
Circular Linked List: 10 -> 20 -> (Back to Head)

Enter your choice: 7
Enter element to search: 20
Element found at position 2.
*/

/*

New concepts in this program:
- Circular linked list: A linked list where the last node points back to the first node.
- Insertion at beginning: Adding a new node at the start of the list.
- Insertion at end: Adding a new node at the end of the list.
- Insertion at specific position: Adding a new node at a given position in the list.
- Deletion from beginning: Removing the first node from the list.
- Deletion from end: Removing the last node from the list.
- Deletion from specific position: Removing a node at a given position in the list.
- Search element: Finding a specific element in the list.
- Display circular linked list: Showing all elements of the circular linked list.

*/
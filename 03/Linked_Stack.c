#include <stdio.h>
#include <stdlib.h>

// Structure defines one node of the linked stack.
struct Node
{
    int data;              // Stores the stack element.
    struct Node *next;     // Stores the address of the next node.
};

// top points to the topmost node of the stack.
// Initially, the stack is empty.
struct Node *top = NULL;


// PUSH: Insert an element at the top of the stack.
void push(int value)
{
    struct Node *newNode;

    // Dynamically allocate memory for a new node.
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }

    // Store the given value in the new node.
    newNode->data = value;

    // Connect the new node to the current top node.
    newNode->next = top;

    // Update top to point to the newly inserted node.
    top = newNode;

    printf("%d pushed into the stack.\n", value);
}


// POP: Remove the top element from the stack.
void pop()
{
    struct Node *temp;

    // Check whether the stack is empty.
    if (top == NULL)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    // Store the address of the top node temporarily.
    temp = top;

    // Display the element that is being removed.
    printf("Popped element: %d\n", top->data);

    // Move top to the next node.
    top = top->next;

    // Release the memory occupied by the removed node.
    free(temp);
}


// PEEK: Display the top element without removing it.
void peek()
{
    // Check whether the stack is empty.
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    // Display the data stored in the topmost node.
    printf("Top element: %d\n", top->data);
}


// DISPLAY: Display all elements of the stack.
void display()
{
    struct Node *temp;

    // Check whether the stack is empty.
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    // Start traversal from the top node.
    temp = top;

    printf("Stack elements (Top to Bottom):\n");

    // Traverse the stack until the last node is reached.
    while (temp != NULL)
    {
        printf("%d\n", temp->data);

        // Move to the next node.
        temp = temp->next;
    }
}


// MAIN FUNCTION: Execution of the program starts here.
int main()
{
    int choice, value;

    // Continue displaying the menu until the user selects Exit.
    while (1)
    {
        printf("\n----- LINKED STACK OPERATIONS -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Select the stack operation using the user's choice.
        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);

                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:

                // Release all remaining nodes before terminating.
                while (top != NULL)
                {
                    pop();
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
2. Initialize top to NULL.
3. PUSH:
   a. Create a new node using malloc().
   b. Store the value in the new node.
   c. Connect the new node to the current top.
   d. Update top to the new node.
4. POP:
   a. Check whether top is NULL.
   b. Store the top node temporarily.
   c. Move top to the next node.
   d. Free the removed node.
5. PEEK:
   a. Check whether the stack is empty.
   b. Display the top element.
6. DISPLAY:
   a. Traverse from top to NULL.
   b. Display each node's data.
7. Free all remaining nodes before termination.

TIME COMPLEXITY:

Push       : O(1)
Pop        : O(1)
Peek       : O(1)
Display    : O(n)

SPACE COMPLEXITY:

O(n) for storing n stack elements.

SAMPLE OUTPUT:

----- LINKED STACK OPERATIONS -----
1. Push
2. Pop
3. Peek
4. Display
5. Exit

Enter your choice: 1
Enter value to push: 10
10 pushed into the stack.

Enter your choice: 1
Enter value to push: 20
20 pushed into the stack.

Enter your choice: 4
Stack elements (Top to Bottom):
20
10

Enter your choice: 2
Popped element: 20

Enter your choice: 3
Top element: 10
*/

/*

New concepts in this program
Concept	Explanation
top pointer	Points to the topmost stack node.
push()	Inserts a new node at the beginning.
pop()	Removes the first node and updates top.
peek()	Reads the top element without deleting it.
Stack Overflow	Occurs when memory allocation fails.
Stack Underflow	Occurs when attempting to pop from an empty stack.

*/
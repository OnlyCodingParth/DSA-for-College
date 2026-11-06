#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to insert an element into the stack
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d inserted into the stack.\n", value);
    }
}

// Function to delete an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

/*
ALGORITHM: STACK USING ARRAY

1. Start.
2. Initialize top = -1.
3. Display the menu:
      1. PUSH
      2. POP
      3. DISPLAY
      4. EXIT

4. If PUSH is selected:
      a. Check if top == MAX - 1.
      b. If true, display Stack Overflow.
      c. Otherwise, read an element.
      d. Increment top and insert the element.

5. If POP is selected:
      a. Check if top == -1.
      b. If true, display Stack Underflow.
      c. Otherwise, delete the top element.
      d. Decrement top.

6. If DISPLAY is selected:
      a. Check if the stack is empty.
      b. Otherwise, display elements from top to bottom.

7. If EXIT is selected, stop the program.
8. Repeat until EXIT is selected.

TIME COMPLEXITY:
- PUSH    : O(1)
- POP     : O(1)
- DISPLAY : O(n)

SPACE COMPLEXITY:
- O(n), where n is the maximum stack capacity.

SAMPLE OUTPUT:

--- STACK OPERATIONS ---
1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter the value: 10
10 inserted into the stack.

Enter your choice: 1
Enter the value: 20
20 inserted into the stack.

Enter your choice: 1
Enter the value: 30
30 inserted into the stack.

Enter your choice: 3
Stack elements are:
30
20
10

Enter your choice: 2
Deleted element: 30

Enter your choice: 3
Stack elements are:
20
10

Enter your choice: 4
Exiting Program...
*/
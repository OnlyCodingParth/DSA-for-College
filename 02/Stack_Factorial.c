#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element
void push(int value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
    }
}

// Function to pop an element
int pop()
{
    if (top == -1)
    {
        return -1;
    }

    return stack[top--];
}

// Function to calculate factorial using stack
int factorial(int n)
{
    int result = 1;

    // Push numbers onto the stack
    for (int i = n; i >= 1; i--)
    {
        push(i);
    }

    // Pop numbers and multiply
    while (top != -1)
    {
        result = result * pop();
    }

    return result;
}

// Main function
int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0 || n > 12)
    {
        printf("Please enter a number between 0 and 12.\n");
    }
    else
    {
        result = factorial(n);
        printf("Factorial of %d = %d\n", n, result);
    }

    return 0;
}

/*
ALGORITHM: FACTORIAL USING STACK

1. Start.
2. Read a number n.
3. Initialize result = 1 and top = -1.
4. Push numbers from n to 1 onto the stack.
5. Pop each element from the stack.
6. Multiply each popped element with result.
7. Display the factorial.
8. Stop.

TIME COMPLEXITY:
- O(n), for pushing and popping n elements.

SPACE COMPLEXITY:
- O(n), for storing n elements in the stack.

SAMPLE OUTPUT:

Enter a number: 5
Factorial of 5 = 120
*/
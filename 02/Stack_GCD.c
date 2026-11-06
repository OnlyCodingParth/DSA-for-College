#include <stdio.h>
#include <stdlib.h>

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
    return stack[top--];
}

// Function to calculate GCD using stack
int gcd(int a, int b)
{
    int result;

    // Push the two numbers onto the stack
    push(a);
    push(b);

    // Pop the numbers
    b = pop();
    a = pop();

    // Apply Euclid's algorithm iteratively
    while (b != 0)
    {
        result = a % b;
        a = b;
        b = result;
    }

    return a;
}

// Main function
int main()
{
    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0)
    {
        printf("GCD of 0 and 0 is undefined.\n");
    }
    else
    {
        result = gcd(a, b);
        printf("GCD = %d\n", result);
    }

    return 0;
}

/*
ALGORITHM: GCD USING STACK

1. Start.
2. Read two numbers a and b.
3. Convert both numbers into positive values.
4. Push a and b onto the stack.
5. Pop the numbers from the stack.
6. Repeat while b is not zero:
      a. Calculate remainder = a % b.
      b. Assign a = b.
      c. Assign b = remainder.
7. Display a as the GCD.
8. Stop.

TIME COMPLEXITY:
- O(log(min(a, b))) for Euclid's algorithm.

SPACE COMPLEXITY:
- O(1) auxiliary space; only two stack elements are used.

SAMPLE OUTPUT:

Enter two numbers: 24 36
GCD = 12
*/
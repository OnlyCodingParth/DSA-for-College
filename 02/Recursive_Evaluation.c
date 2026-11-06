#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
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
ALGORITHM: RECURSIVE FACTORIAL

1. Start.
2. Read a number n.
3. If n is negative, display an error.
4. If n is 0 or 1, return 1.
5. Otherwise, calculate factorial(n) = n * factorial(n-1).
6. Repeat the function until the base condition is reached.
7. Display the factorial.
8. Stop.

TIME COMPLEXITY:
- O(n), because the function is called n times.

SPACE COMPLEXITY:
- O(n), because recursive calls are stored in the call stack.


## SAMPLE OUTPUT:

Enter a number: 5
Factorial of 5 = 120


factorial(5)
   = 5 * factorial(4)
   = 5 * 4 * factorial(3)
   = 5 * 4 * 3 * factorial(2)
   = 5 * 4 * 3 * 2 * factorial(1)
   = 5 * 4 * 3 * 2 * 1
   = 120
*/
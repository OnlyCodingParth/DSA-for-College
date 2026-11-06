#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Main function
int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1 || n > 40)
    {
        printf("Please enter terms between 1 and 40.\n");
    }
    else
    {
        printf("Fibonacci Series:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", fibonacci(i));
        }

        printf("\n");
    }

    return 0;
}

/*
ALGORITHM: RECURSIVE FIBONACCI

1. Start.
2. Read the number of terms n.
3. If n is invalid, display an error.
4. Define fibonacci(n):
      a. If n = 0, return 0.
      b. If n = 1, return 1.
      c. Otherwise, return fibonacci(n-1) + fibonacci(n-2).
5. Use a loop to call fibonacci(i) from 0 to n-1.
6. Display the Fibonacci series.
7. Stop.

TIME COMPLEXITY:
- O(2^n) for the recursive Fibonacci calculation.

SPACE COMPLEXITY:
- O(n) maximum recursion stack space.

SAMPLE OUTPUT:

Enter the number of terms: 7
Fibonacci Series:
0 1 1 2 3 5 8
*/
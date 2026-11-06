#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate GCD
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
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
ALGORITHM: RECURSIVE GCD

1. Start.
2. Read two numbers a and b.
3. If both numbers are zero, display that GCD is undefined.
4. If b = 0, return a.
5. Otherwise, call gcd(b, a % b).
6. Repeat until b becomes zero.
7. Display the GCD.
8. Stop.

TIME COMPLEXITY:
- O(log(min(a, b))) using Euclid's algorithm.

SPACE COMPLEXITY:
- O(log(min(a, b))) due to recursive function calls.

SAMPLE OUTPUT:

Enter two numbers: 24 36
GCD = 12
*/
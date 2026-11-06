#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the largest disk to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Main function
int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Please enter disks between 1 and 20.\n");
    }
    else
    {
        printf("Steps to solve Tower of Hanoi:\n");
        towerOfHanoi(n, 'A', 'B', 'C');
    }

    return 0;
}

/*
ALGORITHM: TOWER OF HANOI

1. Start.
2. Read the number of disks n.
3. If n = 1, move the disk from source to destination.
4. Otherwise:
      a. Move n-1 disks from source to auxiliary.
      b. Move the largest disk from source to destination.
      c. Move n-1 disks from auxiliary to destination.
5. Repeat until all disks reach the destination.
6. Stop.

TIME COMPLEXITY:
- O(2^n), where n is the number of disks.

SPACE COMPLEXITY:
- O(n), due to recursive function calls.

SAMPLE OUTPUT:

Enter the number of disks: 3
Steps to solve Tower of Hanoi:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/
#include <stdio.h>

int main()
{
    int arr[100], n, key, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}

/*

SAMPLE OUTPUT:
Enter the number of elements: 5
Enter 5 elements:
1
2
3
4
5
Enter the element to search: 3
Element found at position 3

algorithm:
1. Start
2. Declare an array of size 100, and variables n, key, and found.
3. Prompt the user to enter the number of elements (n) and read it.
4. Prompt the user to enter n elements and read them into the array.
5. Prompt the user to enter the element to search (key) and read it.
6. Loop through the array from index 0 to n-1:
   a. If the current element is equal to key, print the position (i + 1), set found to 1, and break the loop.
7. After the loop, check if found is still 0:
    a. If found is 0, print "Element not found in the array."
    b. Otherwise, the element was found, so no further action is needed.
    c. End.

Time Complexity: O(n), where n is the number of elements in the array. In the worst case, we may have to check all elements in the array to find the key or determine that it is not present.
Space Complexity: O(1), as we are using a fixed amount of extra space regardless of the input size.

*/
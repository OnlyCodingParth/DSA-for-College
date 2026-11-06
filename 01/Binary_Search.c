#include <stdio.h>

int main()
{
    int arr[100], n, key;
    int low, high, mid, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
Enter 5 elements in sorted order:
1
2
3
4
5
Enter the element to search: 3
Element found at position 3

algorithm:
1. Start
2. Declare an array of size 100, and variables n, key, low, high, mid, and found.
3. Prompt the user to enter the number of elements (n) and read it.
4. Prompt the user to enter n elements in sorted order and read them into the array.
5. Prompt the user to enter the element to search (key) and read it.
6. Initialize low to 0 and high to n - 1.
7. While low is less than or equal to high:
    a. Calculate mid as low + (high - low) / 2.
    b. If the element at mid is equal to key, print the position (mid + 1), set found to 1, and break the loop.
    c. If the element at mid is less than key, set low to mid + 1.
    d. If the element at mid is greater than key, set high to mid - 1.
8. After the loop, check if found is still 0:
    a. If found is 0, print "Element not found in the array."
    b. Otherwise, the element was found, so no further action is needed.
9. End.

TIME COMPLEXITY:
The time complexity of the binary search algorithm is O(log n), where n is the number of elements in the array. This is because the search space is halved with each iteration of the loop, leading to a logarithmic number of comparisons in relation to the size of the input array.

SPACE COMPLEXITY:
The space complexity of the binary search algorithm is O(1), which means it uses a constant amount of space regardless of the input size. This is because the algorithm only requires a fixed number of variables (low, high, mid, found) to perform the search, and it does not use any additional data structures that grow with the input size.

*/

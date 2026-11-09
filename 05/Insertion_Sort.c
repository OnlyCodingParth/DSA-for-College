#include <stdio.h>

int main()
{
    int arr[100], n, i, j, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Insertion Sort:
1. Accept the number of elements and array elements.
2. Start from the second element of the array.
3. Store the current element in key.
4. Compare key with the elements before it.
5. Shift greater elements one position to the right.
6. Insert key into its correct position.
7. Repeat until the array is sorted.
8. Display the sorted array.

Time Complexity:
Best Case:    O(n)
Average Case: O(n²)
Worst Case:   O(n²)

Space Complexity: O(1)

Stable: Yes
In-place: Yes


Sample Output
Enter the number of elements: 5
Enter 5 elements: 45 12 30 8 20
Sorted array in ascending order: 8 12 20 30 45
*/
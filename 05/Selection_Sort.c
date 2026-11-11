#include <stdio.h>

int main()
{
    int arr[100], n, i, j, min, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Selection Sort:
1. Accept the number of elements and array elements.
2. Assume the first unsorted element is the minimum.
3. Find the smallest element in the remaining unsorted array.
4. Swap the smallest element with the first unsorted element.
5. Repeat until the array is sorted.
6. Display the sorted array.

Time Complexity:
Best Case:    O(n²)
Average Case: O(n²)
Worst Case:   O(n²)

Space Complexity: O(1)

Stable: No
In-place: Yes

Sample Output
Enter the number of elements: 5
Enter 5 elements: 45 12 30 8 20
Sorted array in ascending order: 8 12 20 30 45
*/
#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
Bubble Sort:
1. Accept the number of elements and array elements.
2. Compare adjacent elements in each pass.
3. Swap elements if they are in the wrong order.
4. Repeat until the array is sorted.
5. Display the sorted array.

Time Complexity:
Best Case:    O(n²)
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
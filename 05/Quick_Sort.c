#include <stdio.h>

// Function to partition the array using the last element as pivot.
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Function to perform Quick Sort recursively.
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Quick Sort:
1. Accept the number of elements and array elements.
2. Select the last element as the pivot.
3. Partition the array so smaller elements come before the pivot.
4. Place the pivot in its correct position.
5. Recursively sort the left and right subarrays.
6. Display the sorted array.

Time Complexity:
Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n²)

Space Complexity:
Average Case: O(log n) recursion stack
Worst Case:   O(n) recursion stack

Stable: No
In-place: Yes (apart from recursion stack)

Sample Output
Enter the number of elements: 5
Enter 5 elements: 45 12 30 8 20
Sorted array in ascending order: 8 12 20 30 45
*/
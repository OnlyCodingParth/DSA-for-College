#include <stdio.h>

// Function to merge two sorted subarrays.
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    // Compare elements from both subarrays and copy the smaller element.
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left subarray.
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right subarray.
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy merged elements back into the original array.
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

// Function to divide the array and recursively sort both halves.
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Merge Sort:
1. Accept the number of elements and array elements.
2. Divide the array into two halves.
3. Recursively divide both halves until single elements remain.
4. Merge the smaller sorted subarrays.
5. Continue merging until the complete array is sorted.
6. Display the sorted array.

Time Complexity:
Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n log n)

Space Complexity: O(n)

Stable: Yes
In-place: No


Sample Output
Enter the number of elements: 5
Enter 5 elements: 45 12 30 8 20
Sorted array in ascending order: 8 12 20 30 45
*/
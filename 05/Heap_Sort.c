#include <stdio.h>

// Function to maintain the Max Heap property.
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    // Check whether the left child is greater than the root.
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check whether the right child is greater than the largest element.
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Swap the root with the largest child if required.
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively maintain the Max Heap property.
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort.
void heapSort(int arr[], int n)
{
    int i, temp;

    // Build a Max Heap from the given array.
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Move the largest element to the end of the array.
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Restore the Max Heap property for the remaining elements.
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[100], n, i;

    // Accept the number of elements.
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Accept array elements.
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call Heap Sort to sort the array.
    heapSort(arr, n);

    // Display the sorted array.
    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Heap Sort:
1. Accept the number of elements and array elements.
2. Build a Max Heap from the given array.
3. Swap the root element with the last element.
4. Reduce the heap size by one.
5. Apply heapify to restore the Max Heap property.
6. Repeat until the array is sorted.
7. Display the sorted array.

Time Complexity:
Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n log n)

Space Complexity: O(log n) for recursive heapify stack.

Stable: No
In-place: Yes (apart from recursion stack)

Sample Output
Enter the number of elements: 5
Enter 5 elements: 45 12 30 8 20
Sorted array in ascending order: 8 12 20 30 45
*/
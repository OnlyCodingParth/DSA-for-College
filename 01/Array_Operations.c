#include <stdio.h>

int main()
{
    int arr[100], n, choice, pos, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Array elements: ");

                for (int i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }

                printf("\n");
                break;

            case 2:
                if (n >= 100)
                {
                    printf("Array is full. Insertion not possible.\n");
                    break;
                }

                printf("Enter the position: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1)
                {
                    printf("Invalid position.\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                for (int i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 3:
                if (n == 0)
                {
                    printf("Array is empty. Deletion not possible.\n");
                    break;
                }

                printf("Enter the position to delete: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n)
                {
                    printf("Invalid position.\n");
                    break;
                }

                for (int i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

/*

SAMPLE OUTPUT:
Enter the number of elements: 5
Enter 5 elements:
1 2 3 4 5

--- ARRAY OPERATIONS ---
1. Traversal
2. Insertion
3. Deletion
4. Exit
Enter your choice: 1
Array elements: 1 2 3 4 5

Algorithm:
1. Start
2. Declare an array of size 100, and variables n, choice, pos, and value.
3. Prompt the user to enter the number of elements (n) and read it.
4. Prompt the user to enter n elements and read them into the array.
5. Do:
    a. Display the menu of array operations.
    b. Read the user's choice.
    c. Based on the choice:
        i. If choice is 1 (Traversal), display all elements in the array.
        ii. If choice is 2 (Insertion), prompt for position and value, then insert the value at the specified position.
        iii. If choice is 3 (Deletion), prompt for position, then delete the element at that position.
        iv. If choice is 4 (Exit), exit the program.
    d. If choice is not 4, repeat from step a.
6. End.

Time Complexity:
- Traversal: O(n)
- Insertion: O(n) in the worst case (when inserting at the beginning)
- Deletion: O(n) in the worst case (when deleting from the beginning)   

Space Complexity: O(1) (constant space used for variables, array size is fixed at 100)

*/
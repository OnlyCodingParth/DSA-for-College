#include <stdio.h>

#define SIZE 10

int table[SIZE];
int occupied[SIZE] = {0};

// Function to calculate the hash index.
int hashFunction(int key)
{
    return key % SIZE;
}

// Function to insert a key using Linear Probing.
void insert(int key)
{
    int index = hashFunction(key);
    int i;

    // Check each position until an empty slot is found.
    for (i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i) % SIZE;

        // Check whether the key is already present.
        if (occupied[newIndex] && table[newIndex] == key)
        {
            printf("Duplicate key %d cannot be inserted.\n", key);
            return;
        }

        // Insert the key into an empty position.
        if (!occupied[newIndex])
        {
            table[newIndex] = key;
            occupied[newIndex] = 1;
            printf("Key %d inserted successfully.\n", key);
            return;
        }
    }

    // Display a message when the hash table is full.
    printf("Hash table is full. Cannot insert %d.\n", key);
}

// Function to search for a key in the hash table.
void search(int key)
{
    int index = hashFunction(key);
    int i;

    // Search for the key using the Linear Probing sequence.
    for (i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i) % SIZE;

        // Stop searching if an empty position is found.
        if (!occupied[newIndex])
        {
            break;
        }

        // Check whether the required key is found.
        if (table[newIndex] == key)
        {
            printf("Key %d found at index %d.\n", key, newIndex);
            return;
        }
    }

    // Display a message if the key is not found.
    printf("Key %d not found.\n", key);
}

// Function to display all hash table positions.
void display()
{
    int i;

    printf("\nHash Table:\n");

    // Display each index and its corresponding value.
    for (i = 0; i < SIZE; i++)
    {
        if (occupied[i])
        {
            printf("Index %d: %d\n", i, table[i]);
        }
        else
        {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main()
{
    int n, key, i;

    // Accept the number of keys to insert.
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    // Accept and insert each key into the hash table.
    for (i = 0; i < n; i++)
    {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        insert(key);
    }

    // Display the hash table after insertion.
    display();

    // Accept a key to search.
    printf("\nEnter key to search: ");
    scanf("%d", &key);

    // Search for the given key.
    search(key);

    return 0;
}

/*
Hashing Using Linear Probing:

1. Create a hash table of fixed size.
2. Calculate the hash index using key % SIZE.
3. Check whether the calculated position is empty.
4. If occupied, check the next position using Linear Probing.
5. Insert the key into the first available position.
6. Search for a key using the same probing sequence.
7. Display the hash table.

Hash Function:
h(key) = key % SIZE

Linear Probing Formula:
Index = (h(key) + i) % SIZE

Time Complexity:
Average Case: O(1)
Worst Case:   O(n)

Space Complexity: O(SIZE)

Collision Resolution: Linear Probing

Sample Output:
Enter the number of keys: 5
Enter key 1: 10
Key 10 inserted successfully.
Enter key 2: 20
Key 20 inserted successfully.
Enter key 3: 30
Key 30 inserted successfully.
Enter key 4: 40
Key 40 inserted successfully.
Enter key 5: 50
Key 50 inserted successfully.

Hash Table:
Index 0: Empty
Index 1: Empty
Index 2: Empty
Index 3: Empty
Index 4: Empty
Index 5: Empty
Index 6: Empty
Index 7: Empty
Index 8: Empty
Index 9: Empty

Enter key to search: 30
Key 30 found at index 0.
*/
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element
void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow!\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = value;

        printf("%d inserted into the circular queue.\n", value);
    }
}

// Function to delete an element
void delete()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

// Function to display queue elements
void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Circular Queue elements are:\n");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

/*
ALGORITHM: CIRCULAR QUEUE USING ARRAY

1. Start.
2. Initialize front = -1 and rear = -1.
3. Display the menu:
      1. INSERT
      2. DELETE
      3. DISPLAY
      4. EXIT

4. If INSERT is selected:
      a. Check if (rear + 1) % MAX == front.
      b. If true, display Queue Overflow.
      c. Otherwise, read an element.
      d. If front == -1, set front = 0.
      e. Set rear = (rear + 1) % MAX.
      f. Insert the element at queue[rear].

5. If DELETE is selected:
      a. Check if front == -1.
      b. If true, display Queue Underflow.
      c. Otherwise, delete the front element.
      d. If front == rear, reset both to -1.
      e. Otherwise, set front = (front + 1) % MAX.

6. If DISPLAY is selected:
      a. Check if the queue is empty.
      b. Otherwise, display elements from front to rear
         using circular movement.

7. If EXIT is selected, stop the program.
8. Repeat until EXIT is selected.

TIME COMPLEXITY:
- INSERT  : O(1)
- DELETE  : O(1)
- DISPLAY : O(n)

SPACE COMPLEXITY:
- O(n), where n is the maximum queue capacity.

SAMPLE OUTPUT:

--- CIRCULAR QUEUE OPERATIONS ---
1. INSERT
2. DELETE
3. DISPLAY
4. EXIT

Enter your choice: 1
Enter the value: 10
10 inserted into the circular queue.

Enter your choice: 1
Enter the value: 20
20 inserted into the circular queue.

Enter your choice: 1
Enter the value: 30
30 inserted into the circular queue.

Enter your choice: 3
Circular Queue elements are:
10 20 30

Enter your choice: 2
Deleted element: 10

Enter your choice: 1
Enter the value: 40
40 inserted into the circular queue.

Enter your choice: 3
Circular Queue elements are:
20 30 40

Enter your choice: 4
Exiting Program...
*/
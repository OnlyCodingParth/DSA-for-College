#include <stdio.h>
#include <stdlib.h>

// A structure represents one node of the Binary Search Tree.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node dynamically.
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check whether memory allocation was successful.
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a new value while maintaining the BST property.
struct Node *insert(struct Node *root, int value)
{
    // If the current position is empty, create a new node.
    if (root == NULL)
    {
        return createNode(value);
    }

    // Smaller values are inserted into the left subtree.
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }

    // Greater values are inserted into the right subtree.
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    // Duplicate values are not allowed in this program.
    else
    {
        printf("Duplicate values are not allowed!\n");
    }

    return root;
}

// Search for a particular value in the BST.
struct Node *search(struct Node *root, int key)
{
    // If the tree is empty or the key is found, return the current node.
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // Search the left subtree if the key is smaller.
    if (key < root->data)
    {
        return search(root->left, key);
    }

    // Otherwise, search the right subtree.
    return search(root->right, key);
}

// Display nodes using Inorder Traversal (Left, Root, Right).
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Display nodes using Preorder Traversal (Root, Left, Right).
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Display nodes using Postorder Traversal (Left, Right, Root).
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find the node containing the minimum value in a subtree.
// In a BST, the minimum value is present at the leftmost node.
struct Node *findMinimum(struct Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node while maintaining the BST property.
struct Node *deleteNode(struct Node *root, int key)
{
    // If the key is not found, return the current subtree.
    if (root == NULL)
    {
        return root;
    }

    // Search for the node in the left subtree.
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // Search for the node in the right subtree.
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // The node to be deleted has been found.
    else
    {
        // Case 1: Node has no left child.
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Node has no right child.
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children.
        else
        {
            // Find the inorder successor from the right subtree.
            struct Node *temp = findMinimum(root->right);

            // Copy the successor's value into the current node.
            root->data = temp->data;

            // Delete the inorder successor from the right subtree.
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Release all dynamically allocated nodes before program termination.
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function: execution starts here.
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n\n===== BINARY SEARCH TREE OPERATIONS =====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);

            if (search(root, value) != NULL)
            {
                printf("%d found in the BST.\n", value);
            }
            else
            {
                printf("%d not found in the BST.\n", value);
            }
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            break;

        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            break;

        case 5:
            printf("Postorder Traversal: ");
            postorder(root);
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);

            if (search(root, value) != NULL)
            {
                root = deleteNode(root, value);
                printf("%d deleted successfully.\n", value);
            }
            else
            {
                printf("%d not found in the BST.\n", value);
            }
            break;

        case 7:
            freeTree(root);
            printf("Program terminated.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

/*

Algorithm (Exam Writing)
1. Start.
2. Create an initially empty Binary Search Tree.
3. Display the menu of BST operations.
4. Accept the user's choice.
5. Perform the selected operation:
   - Insert: Place smaller values in the left subtree and greater values in the right subtree.
   - Search: Compare the key with the current node and move left or right.
   - Inorder: Visit Left → Root → Right.
   - Preorder: Visit Root → Left → Right.
   - Postorder: Visit Left → Right → Root.
   - Delete: Delete the selected node while maintaining the BST property.
6. Repeat until the user selects Exit.
7. Free allocated memory and stop.
Time and Space Complexity
Operation	Average Case	Worst Case
Insertion	O(log n)	O(n)
Searching	O(log n)	O(n)
Deletion	O(log n)	O(n)
Inorder Traversal	O(n)	O(n)
Preorder Traversal	O(n)	O(n)
Postorder Traversal	O(n)	O(n)


Space Complexity: O(n) for storing n nodes. Recursive operations additionally use O(h) stack space, where h is the tree height.
Sample Output
===== BINARY SEARCH TREE OPERATIONS =====
1. Insert
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Delete
7. Exit

Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 40

Enter your choice: 3
Inorder Traversal: 20 30 40 50 70

Enter your choice: 4
Preorder Traversal: 50 30 20 40 70

Enter your choice: 5
Postorder Traversal: 20 40 30 70 50

Enter your choice: 2
Enter value to search: 40
40 found in the BST.

Enter your choice: 6
Enter value to delete: 30
30 deleted successfully.

Enter your choice: 3
Inorder Traversal: 20 40 50 70

Important exam point: In a Binary Search Tree, Inorder Traversal produces values in sorted ascending order when duplicate values are not allowed.

*/
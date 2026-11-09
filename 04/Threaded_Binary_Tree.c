#include <stdio.h>
#include <stdlib.h>

// Structure for creating a Right-Threaded Binary Tree node.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int rightThread;
};

// Create a new node.
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

    // 1 indicates that the right pointer is a thread.
    newNode->rightThread = 1;

    return newNode;
}

// Insert a new node into the Right-Threaded Binary Search Tree.
struct Node *insert(struct Node *root, int value)
{
    struct Node *parent = NULL;
    struct Node *current = root;

    // If the tree is empty, create the root node.
    if (root == NULL)
    {
        return createNode(value);
    }

    // Find the correct position for the new node.
    while (current != NULL)
    {
        if (value == current->data)
        {
            printf("Duplicate values are not allowed!\n");
            return root;
        }

        parent = current;

        // Move to the left subtree for smaller values.
        if (value < current->data)
        {
            if (current->left == NULL)
            {
                break;
            }

            current = current->left;
        }

        // Move to the right subtree for greater values.
        else
        {
            // Stop if the right pointer is a thread.
            if (current->rightThread == 1)
            {
                break;
            }

            current = current->right;
        }
    }

    // Create the new node.
    struct Node *newNode = createNode(value);

    // Insert the new node as the left child.
    if (value < parent->data)
    {
        newNode->left = NULL;

        // The new node's inorder successor is its parent.
        newNode->right = parent;

        parent->left = newNode;
    }

    // Insert the new node as the right child.
    else
    {
        // The new node inherits the parent's inorder successor.
        newNode->right = parent->right;

        // The new node's inorder predecessor is its parent.
        newNode->left = parent;

        parent->right = newNode;

        // The parent's right pointer is now a child link.
        parent->rightThread = 0;
    }

    return root;
}

// Find the leftmost node in a subtree.
struct Node *leftMost(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Continue moving left until the leftmost node is found.
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Perform inorder traversal without recursion or an explicit stack.
void inorder(struct Node *root)
{
    struct Node *current = leftMost(root);

    while (current != NULL)
    {
        printf("%d ", current->data);

        // Follow the thread to the inorder successor.
        if (current->rightThread == 1)
        {
            current = current->right;
        }

        // Otherwise, find the leftmost node in the right subtree.
        else
        {
            current = leftMost(current->right);
        }
    }
}

// Free all allocated nodes without following thread links.
void freeTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);

    // Follow the right pointer only if it is a child link.
    if (root->rightThread == 0)
    {
        freeTree(root->right);
    }

    free(root);
}

// Main function.
int main()
{
    struct Node *root = NULL;

    // Insert values into the Right-Threaded Binary Search Tree.
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("\nRight-Threaded Binary Tree\n");

    printf("\nInorder Traversal: ");
    inorder(root);

    // Release all allocated memory.
    freeTree(root);

    return 0;
}

/*
====================================================
ALGORITHM:
====================================================

1. Start.
2. Create an empty Right-Threaded Binary Search Tree.
3. Insert nodes according to BST properties.
4. For every new node:
   a. Find its correct position.
   b. Set its left and right pointers.
   c. Maintain the inorder successor thread.
   d. Update the rightThread flag.
5. Find the leftmost node of the tree.
6. Perform inorder traversal:
   a. Display the current node.
   b. If the right pointer is a thread,
      move to the inorder successor.
   c. Otherwise, move to the leftmost node
      of the right subtree.
7. Repeat until the current node becomes NULL.
8. Free allocated memory.
9. Stop.

====================================================
TIME COMPLEXITY:
====================================================

Insertion:
O(h) per insertion.

Inorder Traversal:
O(n) overall.

====================================================
SPACE COMPLEXITY:
====================================================

O(n) for storing n tree nodes.

Auxiliary traversal space:
O(1), because no recursion or explicit
stack is used.

====================================================
SAMPLE OUTPUT:
====================================================

Right-Threaded Binary Tree

Inorder Traversal: 5 10 16 20 25 30 35

====================================================
*/
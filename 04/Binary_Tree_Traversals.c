#include <stdio.h>
#include <stdlib.h>

// Structure for creating a binary tree node.
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

// Inorder Traversal: Left -> Root -> Right.
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal: Root -> Left -> Right.
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root.
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free dynamically allocated memory.
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function.
int main()
{
    // Create the root node of the binary tree.
    struct Node *root = createNode(1);

    // Create the left and right child nodes.
    root->left = createNode(2);
    root->right = createNode(3);

    // Create the remaining child nodes.
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("\nBinary Tree Traversals\n");

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    // Release all allocated memory.
    freeTree(root);

    return 0;
}

/*
====================================================
ALGORITHM:
====================================================

1. Start.
2. Create a binary tree with nodes.
3. Perform Inorder Traversal:
   a. Visit the left subtree.
   b. Visit the root node.
   c. Visit the right subtree.
4. Perform Preorder Traversal:
   a. Visit the root node.
   b. Visit the left subtree.
   c. Visit the right subtree.
5. Perform Postorder Traversal:
   a. Visit the left subtree.
   b. Visit the right subtree.
   c. Visit the root node.
6. Free the allocated memory.
7. Stop.

====================================================
TIME COMPLEXITY:
====================================================

Inorder Traversal  : O(n)
Preorder Traversal : O(n)
Postorder Traversal: O(n)

====================================================
SPACE COMPLEXITY:
====================================================

O(h), where h is the height of the tree,
due to recursive function calls.

====================================================
SAMPLE OUTPUT:
====================================================

Binary Tree Traversals

Inorder Traversal: 4 2 5 1 6 3 7
Preorder Traversal: 1 2 4 5 3 6 7
Postorder Traversal: 4 5 2 6 7 3 1

====================================================
*/
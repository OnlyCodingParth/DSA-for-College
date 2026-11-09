#include <stdio.h>
#include <stdlib.h>

// Structure for creating an AVL Tree node.
struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Return the greater of two values.
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Calculate the height of a node.
int getHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

// Calculate the Balance Factor of a node.
int getBalanceFactor(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

// Create a new AVL Tree node.
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Perform Right Rotation (LL Case).
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    // Perform rotation.
    x->right = y;
    y->left = temp;

    // Update the heights after rotation.
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// Perform Left Rotation (RR Case).
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left;

    // Perform rotation.
    y->left = x;
    x->right = temp;

    // Update the heights after rotation.
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Insert a value into the AVL Tree.
struct Node *insert(struct Node *root, int value)
{
    // Perform normal BST insertion.
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Duplicate values are not allowed!\n");
        return root;
    }

    // Update the height of the current node.
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Calculate the Balance Factor.
    int balance = getBalanceFactor(root);

    // LL Case: Left subtree becomes heavier.
    if (balance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    // RR Case: Right subtree becomes heavier.
    if (balance < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    // LR Case: Left subtree's right side becomes heavier.
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case: Right subtree's left side becomes heavier.
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display nodes using Inorder Traversal.
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Display nodes using Preorder Traversal.
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
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
    struct Node *root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Accept values and insert them into the AVL Tree.
    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nAVL Tree Traversals\n");

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nHeight of AVL Tree: %d", getHeight(root));

    printf("\n\nBalance Factor of Root: %d",
           getBalanceFactor(root));

    // Release all allocated memory.
    freeTree(root);

    return 0;
}

/*
====================================================
ALGORITHM:
====================================================

1. Start.
2. Create an empty AVL Tree.
3. Accept the number of nodes.
4. Insert each value using normal BST insertion.
5. Update the height of each node.
6. Calculate the Balance Factor:
   BF = Height of Left Subtree - Height of Right Subtree.
7. Check whether the node is unbalanced.
8. Perform the required rotation:
   a. LL Case: Right Rotation.
   b. RR Case: Left Rotation.
   c. LR Case: Left Rotation followed by Right Rotation.
   d. RL Case: Right Rotation followed by Left Rotation.
9. Display Inorder and Preorder Traversals.
10. Display the height and Balance Factor.
11. Free allocated memory.
12. Stop.

====================================================
TIME COMPLEXITY:
====================================================

Insertion: O(log n)
Height Retrieval: O(1)
Balance Factor Calculation: O(1)
Inorder Traversal: O(n)
Preorder Traversal: O(n)
Each Rotation: O(1)

====================================================
SPACE COMPLEXITY:
====================================================

O(n) for storing n AVL Tree nodes.

Recursive insertion and traversal:
O(log n) auxiliary stack space
for a balanced AVL Tree.

====================================================
SAMPLE INPUT:
====================================================

Enter the number of nodes: 6
Enter value: 10
Enter value: 20
Enter value: 30
Enter value: 40
Enter value: 50
Enter value: 25

====================================================
SAMPLE OUTPUT:
====================================================

AVL Tree Traversals

Inorder Traversal: 10 20 25 30 40 50
Preorder Traversal: 30 20 10 25 40 50
Height of AVL Tree: 3

Balance Factor of Root: 0

====================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for creating an Expression Tree node.
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

// Stack structure for storing tree node pointers.
struct Stack
{
    struct Node *items[100];
    int top;
};

// Create a new expression tree node.
struct Node *createNode(char value)
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

// Initialize the stack.
void initializeStack(struct Stack *s)
{
    s->top = -1;
}

// Push a tree node onto the stack.
void push(struct Stack *s, struct Node *node)
{
    if (s->top == 99)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }

    s->items[++s->top] = node;
}

// Pop a tree node from the stack.
struct Node *pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Invalid Postfix Expression!\n");
        exit(1);
    }

    return s->items[s->top--];
}

// Check whether a character is an operator.
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

// Construct an Expression Tree from a postfix expression.
struct Node *constructTree(char postfix[])
{
    struct Stack s;
    initializeStack(&s);

    // Read the postfix expression character by character.
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // Ignore spaces.
        if (ch == ' ')
        {
            continue;
        }

        // If the character is an operand, create a leaf node.
        if (isalnum((unsigned char)ch))
        {
            push(&s, createNode(ch));
        }

        // If the character is an operator, create an internal node.
        else if (isOperator(ch))
        {
            struct Node *newNode = createNode(ch);

            // First popped node becomes the right child.
            newNode->right = pop(&s);

            // Second popped node becomes the left child.
            newNode->left = pop(&s);

            push(&s, newNode);
        }
        else
        {
            printf("Invalid character in expression!\n");
            exit(1);
        }
    }

    // A valid postfix expression must leave exactly one tree.
    if (s.top != 0)
    {
        printf("Invalid Postfix Expression!\n");
        exit(1);
    }

    return pop(&s);
}

// Display the expression using Inorder Traversal.
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        if (isOperator(root->data))
        {
            printf("(");
        }

        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);

        if (isOperator(root->data))
        {
            printf(")");
        }
    }
}

// Display the expression using Preorder Traversal.
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Display the expression using Postorder Traversal.
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// Evaluate the expression tree.
int evaluate(struct Node *root)
{
    // If the node is an operand, return its numeric value.
    if (!isOperator(root->data))
    {
        if (isdigit((unsigned char)root->data))
        {
            return root->data - '0';
        }

        printf("Evaluation supports only single-digit operands!\n");
        exit(1);
    }

    // Evaluate the left and right subtrees.
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Perform the operation stored in the current node.
    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;

    case '-':
        return leftValue - rightValue;

    case '*':
        return leftValue * rightValue;

    case '/':
        if (rightValue == 0)
        {
            printf("Division by zero is not allowed!\n");
            exit(1);
        }
        return leftValue / rightValue;

    case '^':
    {
        int result = 1;

        // Calculate power using repeated multiplication.
        if (rightValue < 0)
        {
            printf("Negative exponents are not supported!\n");
            exit(1);
        }

        for (int i = 0; i < rightValue; i++)
        {
            result *= leftValue;
        }

        return result;
    }
    }

    return 0;
}

// Free all dynamically allocated tree nodes.
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
    char postfix[100];

    struct Node *root = NULL;

    printf("Enter a postfix expression: ");
    scanf("%99s", postfix);

    // Construct the expression tree.
    root = constructTree(postfix);

    printf("\nExpression Tree Traversals\n");

    printf("\nInorder (Infix): ");
    inorder(root);

    printf("\nPreorder (Prefix): ");
    preorder(root);

    printf("\nPostorder (Postfix): ");
    postorder(root);

    printf("\n\nExpression Evaluation: %d", evaluate(root));

    // Release allocated memory.
    freeTree(root);

    return 0;
}

/*
====================================================
ALGORITHM:
====================================================

1. Start.
2. Accept a postfix expression.
3. Initialize an empty stack.
4. Read the expression from left to right.
5. If the symbol is an operand:
   a. Create a new tree node.
   b. Push the node onto the stack.
6. If the symbol is an operator:
   a. Create a new operator node.
   b. Pop the first node as the right child.
   c. Pop the second node as the left child.
   d. Push the operator node onto the stack.
7. The remaining stack node becomes the root.
8. Perform Inorder, Preorder and Postorder Traversals.
9. Evaluate the expression tree recursively.
10. Free allocated memory.
11. Stop.

====================================================
TIME COMPLEXITY:
====================================================

Tree Construction: O(n)
Inorder Traversal: O(n)
Preorder Traversal: O(n)
Postorder Traversal: O(n)
Expression Evaluation: O(n)

Overall: O(n), excluding the additional
cost of exponentiation.

====================================================
SPACE COMPLEXITY:
====================================================

O(n) for storing the expression tree
and the stack.

Recursive traversal and evaluation:
O(h) auxiliary stack space,
where h is the tree height.

====================================================
SAMPLE INPUT:
====================================================

Enter a postfix expression: 23+5*

====================================================
SAMPLE OUTPUT:
====================================================

Expression Tree Traversals

Inorder (Infix): ((2+3)*5)
Preorder (Prefix): *+235
Postorder (Postfix): 23+5*

Expression Evaluation: 25

====================================================
*/
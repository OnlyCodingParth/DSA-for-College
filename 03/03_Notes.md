# Chapter 03 – Linked List

## 1. Introduction

A **Linked List** is a fundamental linear data structure consisting of a collection of elements called **nodes**. Unlike contiguous memory structures such as arrays, a linked list maintains the linear logical order of elements using pointers or references. Each node in a linked list contains two essential components:
1. **Data Field**: Stores the actual value, content, or record.
2. **Link / Pointer Field**: Stores the memory address of the next subsequent element in the list.

```
Logical Node Representation:
+-------------------+-------------------+
|    data Field     |  next / link Field|
| (Value stored)    | (Memory Address)  |
+-------------------+-------------------+
```

In a linked list, elements do not need to occupy adjacent or contiguous memory locations. Memory for each individual node is allocated dynamically at runtime wherever memory space is available in the heap. Adjacency between logical elements is established and maintained entirely through these link pointers.

```
Conceptual Representation of a Linked List:
[start] ---> [ Data 1 | Next ] ---> [ Data 2 | Next ] ---> [ Data 3 | NULL ]
               Address 501            Address 601            Address 602
```

---

## 2. Structure and Memory Representation

### 2.1 Array Storage vs. Dynamic Pointer Allocation

To understand linked lists, it is crucial to contrast their memory allocation mechanism with that of static 1D arrays:

* **Static Arrays**: Occupy a fixed, contiguous block of memory allocated at compile time. Array elements are located adjacent to each other at calculated memory offsets ($Address(A[i]) = BaseAddress + i \times sizeof(type)$). While this permits fast direct access ($O(1)$), it suffers from fixed size restrictions and costly insertion/deletion operations that require shifting elements.
* **Linked Lists**: Allocate memory dynamically for each node individually at runtime. Nodes can be situated anywhere in available heap memory. Because physical memory locations are non-contiguous, sequential traversal is performed by following the address stored in each node's link pointer.

```
Array (Contiguous Memory Allocation):
Address: 1000   1004   1008   1012   1016
Element: [ 10 |  20 |  30 |  40 |  50 ]

Linked List (Non-Contiguous Dynamic Allocation):
Address 501: [ 10 | 601 ]  ---> Address 601: [ 20 | 750 ] ---> Address 750: [ 30 | NULL ]
```

### 2.2 C Programming Fundamentals for Linked Lists

Implementing linked lists in C requires mastering four core programming building blocks:

#### 1. Self-Referential Structures (`struct`)
A structure in C is a user-defined data type that groups related variables. A **self-referential structure** is a structure that includes a member pointer pointing to a structure of the same type.

```c
// Declaration of a Singly Linked List Node
struct node {
    int data;               // Data element
    struct node *next;      // Self-referential pointer to next node
};
struct node *start = NULL;  // Head pointer initialized to NULL (empty list)
```

#### 2. Pointers and Address Operations
* Pointer variable (`struct node *p`): Stores the memory address of a `struct node`.
* Member selection operator (`->`): Used with structure pointers to access node members (`p->data` and `p->next`).
* Null pointer (`NULL`): A special pointer value indicating that the pointer does not reference any valid memory address. In linked lists, `NULL` marks the end of the list.

#### 3. Dynamic Memory Allocation (`malloc` and `free`)
* **`malloc()`**: Allocates a specified block of bytes in heap memory at runtime and returns a `void*` pointer to the allocated memory.
  ```c
  temp = (struct node *)malloc(sizeof(struct node));
  ```
  * `sizeof(struct node)` calculates the exact memory required for the structure.
  * Typecasting `(struct node *)` converts the generic void pointer to a node pointer.
* **`free()`**: Releases memory previously allocated on the heap back to the operating system, preventing memory leaks.
  ```c
  free(temp);
  ```

---

## 3. Singly Linked List (SLL)

### 3.1 Concept and Node Structure
A **Singly Linked List** is a linear data structure where each node contains a data field and a single reference (`next`) to the subsequent node in the sequence. Traversal in a singly linked list is unidirectional—moving strictly from the first node (`start` / `head`) forward toward the last node. The last node's `next` pointer is set to `NULL` to signify the termination of the list.

```
Singly Linked List Node Structure:
+---------------+---------------+
|     data      |     next      |
+---------------+---------------+

Singly Linked List Diagram:
[start] ---> [ 10 | 601 ] ---> [ 15 | 602 ] ---> [ 20 | NULL ]
              (Node at 501)    (Node at 601)    (Node at 602)
```

### 3.2 Basic Operations on Singly Linked List

#### 1. Traversal and Display
Traversal involves visiting every node sequentially from `start` to display or process its content.
* **Logic**: Initialize a temporary pointer `q = start`. Loop while `q != NULL`. Print `q->data` and advance `q = q->next`.

```
Algorithm: Traversal / Display
Input: Head pointer 'start'
1. If start == NULL then
2.     Print "List is empty" and Return
3. Set q = start
4. While q != NULL do
5.     Print q->data
6.     Set q = q->next
7. End While
```

#### 2. Insertion Operations

##### A. Insertion at the Beginning
Adds a new node as the new head of the list ($O(1)$ time complexity).

```
Step-by-step Visual Trace:
Before:  [start] ---> [ 10 | * ] ---> [ 15 | NULL ]
New Node: [temp: 05 | * ]
After:   [start] ---> [ 05 | * ] ---> [ 10 | * ] ---> [ 15 | NULL ]
```

* **Procedure**:
  1. Allocate memory for new node: `temp = (struct node *)malloc(sizeof(struct node))`.
  2. Assign value to data field: `temp->data = n`.
  3. Point new node's next field to current first node: `temp->next = start`.
  4. Update `start` pointer to point to new node: `start = temp`.

##### B. Insertion at the End
Appends a new node after the current last node ($O(n)$ time complexity without tail pointer).

```
Step-by-step Visual Trace:
Before:  [start] ---> [ 10 | * ] ---> [ 15 | NULL ]
New Node: [temp: 30 | NULL ]
After:   [start] ---> [ 10 | * ] ---> [ 15 | * ] ---> [ 30 | NULL ]
```

* **Procedure**:
  1. Allocate memory and store data: `temp->data = n`, `temp->next = NULL`.
  2. If `start == NULL`, set `start = temp`.
  3. Otherwise, traverse to last node (`q->next == NULL`).
  4. Update last node's link: `q->next = temp`.

##### C. Insertion in Between / At Specific Position (`addafter`)
Inserts a new node after a designated position or node in the list.

```
Step-by-step Visual Trace:
Inserting 25 at position 3 (after 20):
Before:  ... ---> [ 20 | * ] ---------------> [ 30 | NULL ]
New Node:          [temp: 25 | * ]
After:   ... ---> [ 20 | * ] ---> [ 25 | * ] ---> [ 30 | NULL ]
```

* **Procedure**:
  1. Allocate memory for new node and set data: `temp->data = n`.
  2. Traverse `pos - 1` steps to locate node `q` prior to position.
  3. If `q == NULL`, position is out of bounds.
  4. Link new node to next: `temp->next = q->next`.
  5. Link previous node to new node: `q->next = temp`.

#### 3. Searching Operations
Searching checks whether a specified `key` exists in the list and determines its node location index.

```
Algorithm: Searching a Key
Input: Head pointer 'start', search target 'key'
1. Set q = start, pos = 1, flag = 0
2. If start == NULL then Print "List is empty" and Return
3. While q != NULL do
4.     If q->data == key then
5.         Set flag = 1, Break
6.     Set pos = pos + 1, q = q->next
7. End While
8. If flag == 1 then Print "Element found at position", pos
9. Else Print "Element not found"
```

#### 4. Deletion Operations

##### A. Deletion from the Beginning
Removes the first node from the list ($O(1)$ time complexity).

```
Step-by-step Visual Trace:
Before:  [start] ---> [ 10 | * ] ---> [ 20 | * ] ---> [ 30 | NULL ]
Action:  Set q = start, start = start->next, free(q)
After:   [start] ---> [ 20 | * ] ---> [ 30 | NULL ]
```

* **Procedure**:
  1. Check if empty (`start == NULL`).
  2. Set temporary pointer `q = start`.
  3. Advance `start` pointer: `start = start->next`.
  4. Release memory of deleted node: `free(q)`.

##### B. Deletion from the End
Removes the last node from the list ($O(n)$ time complexity).

```
Step-by-step Visual Trace:
Before:  [start] ---> [ 10 | * ] ---> [ 20 | * ] ---> [ 30 | NULL ]
Action:  Traverse to second last node (p), set p->next = NULL, free last node (q)
After:   [start] ---> [ 10 | * ] ---> [ 20 | NULL ]
```

* **Procedure**:
  1. Check if empty (`start == NULL`).
  2. If only one node (`start->next == NULL`), set `start = NULL` and `free(start)`.
  3. Otherwise, traverse with two pointers (`q` and `p`) until `q->next == NULL` and `p->next == q`.
  4. Set `p->next = NULL`.
  5. Release memory: `free(q)`.

---

## 4. Linked Representation of Stack and Queue

Stacks and Queues are abstract data types that can be dynamically represented using linked lists, eliminating static array size limitations and stack overflow risks.

### 4.1 Linked List Representation of Stack
A **Linked Stack** maintains a single pointer named `top` which points to the head node of the linked list.
* **LIFO Principle**: Insertions (PUSH) and deletions (POP) both occur exclusively at the `top` (head of the list), ensuring $O(1)$ constant time complexity.
* **Empty Condition**: `top == NULL`.

```
Linked Stack Execution Trace:

1. Empty Stack:
   top ---> NULL

2. After PUSH 10:
   top ---> [ 10 | NULL ]

3. After PUSH 20:
   top ---> [ 20 | * ] ---> [ 10 | NULL ]

4. After PUSH 30:
   top ---> [ 30 | * ] ---> [ 20 | * ] ---> [ 10 | NULL ]

5. After POP Operation (removes 30):
   top ---> [ 20 | * ] ---> [ 10 | NULL ]
```

* **PUSH Operation**: Allocate node `temp`, set `temp->data = val`, set `temp->next = top`, and set `top = temp`.
* **POP Operation**: Check underflow (`top == NULL`), set `temp = top`, advance `top = top->next`, retrieve data, and execute `free(temp)`.

### 4.2 Linked List Representation of Queue
A **Linked Queue** maintains two pointers: `front` (pointing to the head for deletion) and `rear` (pointing to the tail for insertion).
* **FIFO Principle**: Insertions (ENQUEUE) occur at `rear`, while deletions (DEQUEUE) occur at `front`.
* **Empty Condition**: `front == NULL && rear == NULL`.

```
Linked Queue Execution Trace:

1. Empty Queue:
   front ---> NULL, rear ---> NULL

2. After ENQUEUE 10:
   front, rear ---> [ 10 | NULL ]

3. After ENQUEUE 20, 30, 40:
   front ---> [ 10 | * ] ---> [ 20 | * ] ---> [ 30 | * ] ---> [ 40 | NULL ] <--- rear

4. After DEQUEUE Operation (removes 10):
   front ---> [ 20 | * ] ---> [ 30 | * ] ---> [ 40 | NULL ] <--- rear
```

* **ENQUEUE Operation**: Allocate node `temp` with `temp->next = NULL`. If empty (`rear == NULL`), set `front = rear = temp`. Otherwise, set `rear->next = temp` and update `rear = temp`.
* **DEQUEUE Operation**: Check underflow (`front == NULL`), set `temp = front`, advance `front = front->next`. If `front == NULL`, set `rear = NULL`. Execute `free(temp)`.

---

## 5. Doubly Linked List (DLL)

### 5.1 Concept and Node Structure
A **Doubly Linked List** (also called a two-way linked list) is a linear data structure where each node contains three fields:
1. `prev`: A pointer to the previous node in the sequence.
2. `data`: The element value.
3. `next`: A pointer to the next node in the sequence.

```
Doubly Linked List Node Structure:
+---------------+---------------+---------------+
|     prev      |     data      |     next      |
+---------------+---------------+---------------+

Doubly Linked List Logical Representation:
NULL <--- [ NULL | 10 | * ] <===> [ * | 20 | * ] <===> [ * | 30 | NULL ] ---> NULL
           (First Node)              (Middle Node)          (Last Node)
```

**Key Advantage**: A doubly linked list allows bidirectional traversal (both forward and backward), making node deletion and reverse navigation significantly more efficient than in a singly linked list.

### 5.2 Operations on Doubly Linked List

#### 1. Insertion Operations

##### A. Insertion at Beginning
* **Logic**: Create `temp`. Set `temp->prev = NULL`, `temp->data = n`, `temp->next = start`. If `start != NULL`, set `start->prev = temp`. Update `start = temp`.

```
Visual Diagram - Insertion at Beginning:
         +-------------------+
         | NULL | 06 | start |
         +-------------------+
                   |
                   v
start ---> [ NULL | 01 | next ] <===> [ prev | 02 | next ]
```

##### B. Insertion In Between Two Nodes
* **Logic**: Create `temp`. Locate target insertion point. Update `temp->next = q->next`, `temp->prev = q`. If `q->next != NULL`, set `q->next->prev = temp`. Update `q->next = temp`.

##### C. Insertion at End
* **Logic**: Create `temp` with `temp->next = NULL`. If `start == NULL`, set `temp->prev = NULL`, `start = temp`. Otherwise, traverse to last node `q`. Set `q->next = temp` and `temp->prev = q`.

#### 2. Deletion Operations

##### A. Deletion from Beginning
* **Logic**: Set `q = start`. Advance `start = start->next`. If `start != NULL`, update `start->prev = NULL`. Execute `free(q)`.

##### B. Deletion from End
* **Logic**: Traverse to last node `q` tracking previous node `p`. Set `p->next = NULL`. Execute `free(q)`.

#### 3. Display / Traversal Operations
* **Forward Display**: Start from `start` and traverse following `q = q->next` until `q == NULL`.
* **Backward Display**: Traverse to the last node using `next` pointers, then traverse backward using `q = q->prev` until `q == NULL`.

---

## 6. Circular Linked List (CLL)

### 6.1 Concept and Node Structure
A **Circular Linked List** is a variation of a linked list in which the last node's link pointer does not contain `NULL`. Instead, it points back to the first node (`start`), forming a continuous closed loop or circle.

```
Circular Linked List Logical Diagram:
start ---> [ 05 | * ] ---> [ 10 | * ] ---> [ 15 | * ]
             ^                                   |
             +-----------------------------------+
```

### 6.2 Key Characteristics
1. **Absence of NULL**: No node in the list contains a `NULL` pointer.
2. **Infinite Traversal Loop**: Traversal can begin at any arbitrary node and visit all nodes by looping until returning to the starting node.
3. **Circular Boundary**: The tail node directly links to `start`.

### 6.3 Basic Operations on Circular Linked List

#### 1. Traversal Operation
* **Logic**: Set `q = start`. Process node data. Advance `q = q->next`. Continue loop `while(q != start)`.

#### 2. Insertion Operations
* **At Beginning**: Create new node `temp`. Traverse to last node `q` (`q->next == start`). Set `temp->next = start`, `q->next = temp`, and update `start = temp`.
* **At End**: Create new node `temp`. Traverse to last node `q`. Set `q->next = temp` and `temp->next = start`.

#### 3. Deletion Operations
* **From Beginning**: Locate last node `q`. Set `start = start->next`, update `q->next = start`, and free original head node.
* **From End**: Traverse to second-last node `p` and last node `q`. Set `p->next = start` and execute `free(q)`.

---

## 7. Applications, Advantages, and Disadvantages

### 7.1 Real-World Applications of Linked Lists
1. **Dynamic Memory Management**: Operating system heap management allocates and tracks free/allocated memory blocks using linked lists.
2. **Polynomial Arithmetic**: Representing and adding/multiplying sparse polynomials with variable terms ($a_x X^e$).
3. **Undo/Redo Functionality**: Software applications (text editors, graphic tools) maintain undo history using doubly linked lists.
4. **Browser History Navigation**: Web browsers use doubly linked lists to implement Forward and Back button navigation.
5. **OS Process Scheduling**: Round-robin CPU task scheduling utilizes circular linked lists to continuously cycle through active processes.

### 7.2 Advantages and Disadvantages

| Feature Dimensions | Advantages of Linked Lists | Disadvantages of Linked Lists |
| :--- | :--- | :--- |
| **Memory Flexibility** | Dynamic sizing; grows and shrinks at runtime without pre-allocation. | Extra memory overhead per node to store pointer addresses. |
| **Insertion / Deletion** | Highly efficient $O(1)$ node insertion and deletion without shifting elements. | Sequential access only; no random or direct element index access ($O(n)$ search). |
| **Memory Utilization** | No memory wastage or pre-allocated unused buffer space. | Memory fragmentation across heap locations can reduce cache locality. |
| **Traversal Direction** | Doubly linked lists support seamless two-way navigation. | Singly linked lists cannot be traversed in reverse direction. |

---

## 8. Comparative Analysis: Array vs. Linked List

| Comparison Parameter | Static Array | Linked List |
| :--- | :--- | :--- |
| **Memory Allocation** | Static contiguous allocation at compile time. | Dynamic non-contiguous allocation at runtime. |
| **Size Flexibility** | Fixed capacity; cannot resize dynamically. | Dynamic capacity; expands and contracts as needed. |
| **Element Access** | Direct / Random access via index in $O(1)$ time. | Sequential access by traversing pointers in $O(n)$ time. |
| **Insertion / Deletion** | Slow $O(n)$ time due to shifting adjacent elements. | Fast $O(1)$ time at known positions (re-linking pointers). |
| **Memory Overhead** | Zero pointer overhead (stores data elements only). | Higher overhead (requires storing 1 or 2 pointers per node). |
| **Cache Locality** | Excellent cache locality due to contiguous addresses. | Poor cache locality due to scattered heap addresses. |
| **Search Operations** | Supports $O(\log n)$ Binary Search on sorted arrays. | Restricted to $O(n)$ Linear Search only. |

---

## 9. Algorithms and Complexity Analysis

### 9.1 Time Complexity Matrix across Linked List Operations

| Data Structure / Operation | Best Case Time | Average Case Time | Worst Case Time | Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **SLL Traversal / Display** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **SLL Insertion at Beginning** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **SLL Insertion at End** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **SLL Insertion at Position** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **SLL Deletion from Beginning** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **SLL Deletion from End** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **SLL Search Key** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **DLL Insertion at Beginning** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **DLL Deletion from Beginning** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **CLL Traversal / Display** | $O(n)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Linked Stack Push / Pop** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ auxiliary |
| **Linked Queue Enqueue / Dequeue** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ auxiliary |

---

## 10. Programming Questions

To master practical implementations, study the programming logic for each task and write complete C programs in separate `.c` files as assigned below:

### Programming Question 1: Singly Linked List Operations
**Question**: Write a menu-driven C program to implement a Singly Linked List supporting insertion (at beginning, at end, at position), deletion (from beginning, from end), searching a key element, and displaying all nodes.
* **Logic**: Define `struct node` with `data` and `next`. Implement modular functions `insert_beg()`, `insert_end()`, `addafter()`, `del_beg()`, `del_end()`, `search()`, and `display()` controlled by a `switch-case` menu loop.
* **Separate C File**: `Singly_Linked_List_Operations.c`

### Programming Question 2: Linked Implementation of Stack
**Question**: Write a C program to implement a Stack using a Singly Linked List. Support `push()`, `pop()`, and `display()` operations.
* **Logic**: Maintain a global pointer `top` initialized to `NULL`. `push()` prepends a node to `top`. `pop()` removes the node referenced by `top` and advances `top = top->next`.
* **Separate C File**: `Linked_Stack.c`

### Programming Question 3: Linked Implementation of Queue
**Question**: Write a C program to implement a Linear Queue using a Singly Linked List. Support `enqueue()`, `dequeue()`, and `display()` operations.
* **Logic**: Maintain two pointers `front` and `rear`. `enqueue()` appends nodes at `rear`. `dequeue()` removes nodes from `front` and advances `front = front->next`.
* **Separate C File**: `Linked_Queue.c`

### Programming Question 4: Doubly Linked List Operations
**Question**: Write a menu-driven C program to implement a Doubly Linked List supporting insertion (beginning, middle, end), deletion (beginning, end), and forward/backward display.
* **Logic**: Define `struct node` with `prev`, `data`, and `next`. Maintain node linking carefully during insertion and deletion to preserve `prev` pointers.
* **Separate C File**: `Doubly_Linked_List_Operations.c`

### Programming Question 5: Circular Linked List Operations
**Question**: Write a C program to implement a Circular Linked List with operations for insertion at beginning/end, deletion from beginning/end, and circular traversal.
* **Logic**: Ensure the last node's `next` pointer continuously references `start`. Terminate loops when the loop pointer returns to `start`.
* **Separate C File**: `Circular_Linked_List.c`

---

## 11. Important Definitions

1. **Linked List**: A linear data structure composed of self-referential nodes connected by pointer addresses rather than contiguous memory placement.
2. **Node**: An individual element of a linked list containing a data field and one or more pointer/link fields.
3. **Self-Referential Structure**: A structure definition in C containing a member variable that is a pointer to a structure of the same type.
4. **Head / Start Pointer**: A pointer variable holding the memory address of the first node in a linked list.
5. **NULL Pointer**: A standard pointer value (`0`) signifying that a pointer does not reference any valid memory address.
6. **Singly Linked List**: A linked list structure where each node points only to the next node in forward order.
7. **Doubly Linked List**: A linked list structure where each node contains pointers to both its preceding (`prev`) and succeeding (`next`) nodes.
8. **Circular Linked List**: A linked list variation where the final node's link pointer references the first node, forming a closed loop.
9. **Dynamic Memory Allocation**: The process of allocating memory from the heap during program execution using functions like `malloc()`.
10. **`free()` Function**: A standard C library function used to deallocate dynamically allocated heap memory and prevent memory leaks.

---

## 12. Important Short-Answer Questions (2 Marks)

### Q1. What is a self-referential structure? Give an example in C.
**Answer**: A self-referential structure is a structure in C that contains a pointer member pointing to a structure variable of the exact same type. It forms the structural backbone of linked lists.
*Example*:
```c
struct node {
    int data;
    struct node *next; // Self-referential pointer
};
```

### Q2. Why is memory allocated dynamically for linked list nodes?
**Answer**: Linked lists need to grow and shrink dynamically during program execution without fixing a static capacity at compile time. Functions like `malloc()` allocate memory from the heap for each node as needed.

### Q3. Differentiate between `malloc()` and `free()`.
**Answer**: `malloc()` allocates a specified block of bytes on the heap at runtime and returns a pointer to it. `free()` deallocates previously allocated heap memory, returning it to the system to prevent memory leaks.

### Q4. What is the significance of `NULL` in a singly linked list?
**Answer**: `NULL` in the `next` field of a node marks the end/termination of the singly linked list. It serves as the stopping condition for list traversal loops (`while(q != NULL)`).

### Q5. What is the time complexity of inserting a node at the beginning of a singly linked list?
**Answer**: The time complexity is $O(1)$ (constant time) because it only requires updating pointer links (`temp->next = start; start = temp;`) without traversing or shifting elements.

---

## 13. Important 4-Mark Questions with Detailed Answers

### Q1. Explain the node structure and memory representation of a Singly Linked List with a neat diagram.
**Answer**:
A Singly Linked List node consists of two parts:
1. `data`: Holds the data element (e.g., integer, character, or structure).
2. `next`: Pointer variable storing the memory address of the next node.

```
Node Structure Diagram:
+-------------------+-------------------+
|    data Field     |    next Field     |
+-------------------+-------------------+
```

In C, it is declared using a self-referential structure:
```c
struct node {
    int data;
    struct node *next;
};
```
Memory is allocated dynamically on the heap. Individual nodes reside at non-contiguous physical addresses connected by pointers:

```
Memory Allocation Diagram:
[start: 501]
Address 501: [ 10 | 601 ] ---> Address 601: [ 20 | 705 ] ---> Address 705: [ 30 | NULL ]
```
The head pointer (`start`) stores the address of the first node ($501$). The last node at address $705$ holds `NULL` in its `next` field, indicating the list boundary.

---

### Q2. Write step-by-step algorithms for inserting a node at the beginning and at the end of a Singly Linked List.
**Answer**:

#### Algorithm 1: Insertion at the Beginning
```
Input: Head pointer 'start', value 'val'
1. Allocate memory for new node 'temp' using malloc.
2. If temp == NULL then Print "Memory Allocation Failed" and Exit.
3. Set temp->data = val
4. Set temp->next = start
5. Set start = temp
6. Stop
```

#### Algorithm 2: Insertion at the End
```
Input: Head pointer 'start', value 'val'
1. Allocate memory for new node 'temp' using malloc.
2. Set temp->data = val, temp->next = NULL
3. If start == NULL then
4.     Set start = temp and Stop
5. Set q = start
6. While q->next != NULL do
7.     Set q = q->next
8. End While
9. Set q->next = temp
10. Stop
```

---

### Q3. Explain how Stack and Queue are implemented using Linked Lists.
**Answer**:

#### 1. Linked Stack Implementation
A stack enforces LIFO access. In a linked stack, all PUSH and POP operations occur at the `start` of the list (referred to as `top`).
* **PUSH(val)**: Create `temp`. Set `temp->data = val`, `temp->next = top`, and update `top = temp`. Complexity: $O(1)$.
* **POP()**: Check underflow (`top == NULL`). Set `temp = top`, update `top = top->next`, retrieve data, and execute `free(temp)`. Complexity: $O(1)$.

```
Linked Stack: top ---> [ 30 | * ] ---> [ 20 | * ] ---> [ 10 | NULL ]
```

#### 2. Linked Queue Implementation
A queue enforces FIFO access using two pointers: `front` (deletion head) and `rear` (insertion tail).
* **ENQUEUE(val)**: Create `temp`. Set `temp->data = val`, `temp->next = NULL`. If `rear == NULL`, set `front = rear = temp`. Otherwise, set `rear->next = temp` and update `rear = temp`. Complexity: $O(1)$.
* **DEQUEUE()**: Check underflow (`front == NULL`). Set `temp = front`, update `front = front->next`. If `front == NULL`, set `rear = NULL`. Execute `free(temp)`. Complexity: $O(1)$.

```
Linked Queue: front ---> [ 10 | * ] ---> [ 20 | * ] ---> [ 30 | NULL ] <--- rear
```

---

### Q4. Describe the structure of a Doubly Linked List node. List its key advantages over a Singly Linked List.
**Answer**:
A Doubly Linked List (DLL) node contains three fields:
1. `prev`: Pointer to the preceding node.
2. `data`: Stored value.
3. `next`: Pointer to the succeeding node.

```c
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
```

```
DLL Node Diagram:
+---------------+---------------+---------------+
|     prev      |     data      |     next      |
+---------------+---------------+---------------+
```

#### Key Advantages over Singly Linked List:
1. **Bidirectional Traversal**: Can be traversed both forward and backward easily.
2. **Efficient Deletion**: Deleting a given node $X$ does not require searching for its predecessor node, as $X \to prev$ directly references it.
3. **Flexible Insertion**: Nodes can be inserted before or after a target node easily.

---

## 14. Important Long-Answer Questions

### Q1. Compare Arrays and Linked Lists comprehensively across memory allocation, access, insertion, deletion, and complexity dimensions.
**Answer**:

#### 1. Detailed Comparative Analysis
* **Memory Architecture**: Arrays allocate a contiguous chunk of memory at compile time (static allocation). Linked lists allocate individual node memory dynamically on the heap at runtime (dynamic allocation).
* **Element Access**: Arrays calculate item locations directly ($BaseAddress + i \times Size$), giving $O(1)$ random access. Linked lists require sequential traversal following pointers ($O(n)$ search time).
* **Insertion and Deletion**: Inserting or deleting array elements requires shifting elements to maintain contiguity ($O(n)$ time). Linked lists insert or delete by modifying pointer references ($O(1)$ time at a known node location).
* **Memory Efficiency**: Arrays may waste allocated space if reserved elements remain unused. Linked lists use exact memory required for active nodes but incur pointer storage overhead (4 to 8 extra bytes per node).

#### 2. Comparison Matrix

| Aspect | Static Array | Linked List |
| :--- | :--- | :--- |
| **Allocation Strategy** | Static contiguous memory | Dynamic non-contiguous memory |
| **Random Access** | Supported ($O(1)$) | Not supported ($O(n)$ sequential) |
| **Insertion / Deletion** | Slow ($O(n)$ shifting required) | Fast ($O(1)$ pointer update) |
| **Size Adjustment** | Fixed size | Dynamic expansion/contraction |
| **Search Performance** | $O(\log n)$ Binary search possible | $O(n)$ Linear search only |
| **Overhead** | Zero extra pointer overhead | Pointer overhead per node |

---

### Q2. Explain Circular Linked List in detail. How do its operations differ from a Singly Linked List? Explain insertion and deletion algorithms for a Circular Linked List.
**Answer**:

#### 1. Concept and Differences
In a Circular Linked List (CLL), the last node's link field points back to the first node (`start`) instead of `NULL`.

```
Circular Linked List Loop:
start ---> [ 10 | * ] ---> [ 20 | * ] ---> [ 30 | * ]
             ^                                   |
             +-----------------------------------+
```

#### Key Operational Differences from SLL:
* **No NULL Boundary**: SLL checks `while(q != NULL)`. CLL checks `while(q != start)`.
* **Last Node Handling**: Inserting or deleting at the beginning of a CLL requires updating the last node's link pointer to preserve the circular loop.

#### 2. Operations and Algorithms

##### A. Insertion at Beginning of Circular Linked List
```
1. Allocate node 'temp', set temp->data = val.
2. If start == NULL then
3.     Set start = temp, temp->next = start, and Stop.
4. Set q = start
5. While q->next != start do
6.     Set q = q->next
7. End While
8. Set temp->next = start
9. Set q->next = temp
10. Set start = temp
```

##### B. Deletion from Beginning of Circular Linked List
```
1. If start == NULL then Print "List Empty" and Exit.
2. If start->next == start then
3.     Free start, set start = NULL, and Stop.
4. Set q = start, ptr = start
5. While q->next != start do
6.     Set q = q->next
7. End While
8. Set start = start->next
9. Set q->next = start
10. Free ptr
```

---

## 15. Chapter Summary and Key Points

* **Linked List Definition**: A dynamic linear structure composed of nodes linked by pointers rather than contiguous memory placement.
* **Node Components**: Consists of a data field and one or more pointer/link fields (`next`, `prev`).
* **Self-Referential Structure**: Declared in C using `struct node { int data; struct node *next; };`.
* **Dynamic Memory Functions**: `malloc()` allocates heap memory dynamically at runtime; `free()` releases memory to prevent leaks.
* **Singly Linked List (SLL)**: Unidirectional list where nodes point to the next node; last node points to `NULL`.
* **Doubly Linked List (DLL)**: Bidirectional list where nodes contain both `prev` and `next` pointers, enabling forward and backward traversal.
* **Circular Linked List (CLL)**: List structure where the last node links back to the first node (`start`), eliminating `NULL` pointers.
* **Linked Stack**: LIFO structure implemented with a `top` pointer pointing to the head node. $O(1)$ push and pop operations.
* **Linked Queue**: FIFO structure implemented with `front` (deletion) and `rear` (insertion) pointers. $O(1)$ enqueue and dequeue operations.
* **Time Complexity Highlights**:
  * Insertion/Deletion at head: $O(1)$ constant time.
  * Search / Traversal / Insertion at tail (without tail pointer): $O(n)$ linear time.

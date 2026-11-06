# Chapter 02 – Stack & Queue

## 1. Introduction

Data structures form the foundational building blocks of efficient software development and computer systems design. While basic linear structures such as arrays allow direct access to elements at any index position, many real-world computational problems require constrained access mechanisms to preserve logical correctness, execution order, or memory integrity. 

Chapter 02 introduces two essential restricted linear non-primitive Abstract Data Types (ADTs): **Stack** and **Queue**. 
* A **Stack** constrains all data insertions and deletions to a single access boundary termed the `top`, operating strictly under the **Last-In-First-Out (LIFO)** access discipline. Stacks play a critical role in system software runtime environments, managing function call frames during recursion, parsing arithmetic expressions, and supporting backtracking routines.
* A **Queue** separates the access boundaries into two distinct operational ends: a `rear` pointer for inserting incoming items and a `front` pointer for removing existing items. This structure enforces the **First-In-First-Out (FIFO)** discipline, making it the primary model for fair resource allocation, operating system CPU scheduling, print spooling, and network packet buffer management.

This document provides complete, exam-oriented study notes for Chapter 02, covering structural definitions, algorithms, complexity bounds, memory representations, mathematical expression parsing, call stack mechanics, queue variants, and implementation logic.

---

## 2. Topic-wise Detailed Explanation

### 2.1 The Stack Data Structure

#### Definition and Fundamental Concept
A **Stack** is a linear, non-primitive data structure in which elements are added and removed strictly from one end, designated as the **top** of the stack. Because the element inserted most recently is always the first one to be removed, the stack is described as following the **Last-In-First-Out (LIFO)** protocol. 

Real-world analogies include a stack of dinner plates or a vertical tray of books: the plate placed on top last is the first plate retrieved. In computing environments, web browsers use a stack to manage back-button navigation history, and text editors rely on stacks to implement undo and redo functionality.

#### Memory Representation of Stack
In C programming, a stack can be represented in memory using two distinct allocation paradigms:

1. **Static Implementation (Using 1D Array)**: Memory is allocated contiguously at compile time with a fixed maximum capacity `size`. An integer variable `top` tracks the index of the uppermost element. When the stack is empty, `top` is initialized to `-1`. While static arrays offer simple pointer-free access, they suffer from fixed size limits.
2. **Dynamic Implementation (Using Singly Linked List)**: Memory for each stack element (node) is allocated dynamically at runtime using `malloc()`. Each node contains a `data` field and a `next` pointer field pointing to the node beneath it. The `top` pointer points directly to the head node. Dynamic linked stacks eliminate fixed capacity constraints and grow or shrink on demand.

#### Abstract Data Type (ADT) Specification
As an Abstract Data Type, a stack defines the following set of primitive operations independent of underlying implementation details:

* `push(x)`: Inserts element `x` onto the top of the stack.
* `pop()`: Removes and returns the element currently at the top of the stack.
* `isEmpty()`: Checks whether the stack contains zero elements. Returns true (1) if empty, false (0) otherwise.
* `isFull()`: Checks whether the stack has reached its maximum capacity. Applicable to array-based implementations.

#### Boundary Conditions: Overflow and Underflow
Correct stack operation requires handling two critical boundary conditions:

* **Stack Overflow**: Occurs when a `push()` operation is executed on a stack that has already reached its maximum storage limit (`top == size - 1` in an array implementation). Attempting to insert an element into a full stack causes memory corruption or execution errors.
* **Stack Underflow**: Occurs when a `pop()` operation is attempted on a stack that contains no elements (`top == -1` in an array implementation). Popping from an empty stack represents an invalid memory read.

---

### 2.2 Applications of Stack – Expression Handling

#### Expression Notations
In computer science, arithmetic expressions consist of **operands** (variables or numbers) and **operators** (symbols indicating mathematical actions). Depending on the relative position of operators to operands, expressions are categorized into three standard notations:

1. **Infix Notation**: The operator appears *between* its operands (e.g., $A + B$, $(A + B) * C$). This notation matches standard human mathematical practice. However, evaluating infix expressions computationally requires complex parsing to interpret parentheses and operator precedence.
2. **Prefix Notation (Polish Notation)**: The operator appears *before* its operands (e.g., $+ A B$, $* + A B C$). Prefix expressions require no parentheses to specify evaluation order.
3. **Postfix Notation (Reverse Polish Notation / RPN)**: The operator appears *after* its operands (e.g., $A B +$, $A B + C *$): Compilers favor postfix notation because expressions can be evaluated in a single left-to-right pass using a stack without inspecting operator precedence or nested parentheses.

#### Operator Precedence and Associativity Rules
When evaluating or converting complex expressions, operators are processed according to a strict priority hierarchy:

* **High Priority**: Exponentiation ($\text{^}$ or $\uparrow$) — Associativity: Right-to-Left.
* **Medium Priority**: Multiplication ($*$) and Division ($/$) — Associativity: Left-to-Right.
* **Low Priority**: Addition ($+$) and Subtraction ($-$) — Associativity: Left-to-Right.

Parentheses $( \ )$ override standard precedence rules, forcing internal sub-expressions to be processed first.

#### Infix to Postfix Conversion Logic
To convert an infix expression to postfix notation, an operator stack is used to temporarily store operators until their operands are available.

**Execution Rule for Operators**: When an incoming operator is processed, it is compared against the operator currently at the top of the stack. If the top operator has equal or higher precedence than the incoming operator, the top operator is popped to the postfix output string. Operators of equal priority cannot remain adjacent on the stack.

##### Worked Step-by-Step Example
Convert Infix Expression: $A + B * C$

| Token Scanned | Operator Stack State | Postfix Output Buffer | Operational Action & Logic |
| :---: | :---: | :---: | :--- |
| `A` | *Empty* | `A` | Operand encountered $\to$ Append directly to postfix output. |
| `+` | `+` | `A` | Operator $+$ scanned $\to$ Push onto empty stack. |
| `B` | `+` | `A B` | Operand encountered $\to$ Append directly to output. |
| `*` | `+, *` | `A B` | Operator $*$ scanned $\to$ Higher precedence than top operator $+$, push onto stack. |
| `C` | `+, *` | `A B C` | Operand encountered $\to$ Append directly to output. |
| *End of Input* | *Empty* | `A B C * +` | Input string exhausted $\to$ Pop remaining stack operators to output. |

Final Postfix Expression: `A B C * +`

#### Evaluation of Postfix Expressions
Evaluating a postfix expression requires an operand stack. The expression is scanned token by token from left to right:
1. If the token is an operand, it is pushed onto the stack.
2. If the token is an operator, the top two operands are popped: the first popped item becomes operand $S_1$, and the second popped item becomes operand $S_2$. The operator is applied to derive $S_2 \text{ operator } S_1$, and the computed result is pushed back onto the stack.

##### Worked Step-by-Step Example
Evaluate Postfix Expression: `4 5 6 * +`

| Token Scanned | Operand Stack State (Bottom $\to$ Top) | Operation Performed | Computed Value & Stack Update |
| :---: | :---: | :---: | :--- |
| `4` | `[4]` | Push operand | Stack: `[4]` |
| `5` | `[4, 5]` | Push operand | Stack: `[4, 5]` |
| `6` | `[4, 5, 6]` | Push operand | Stack: `[4, 5, 6]` |
| `*` | `[4]` | Pop $S_1 = 6$, $S_2 = 5$; Calculate $5 \times 6 = 30$ | Push $30 \to$ Stack: `[4, 30]` |
| `+` | `[]` | Pop $S_1 = 30$, $S_2 = 4$; Calculate $4 + 30 = 34$ | Push $34 \to$ Stack: `[34]` |
| *End* | `[34]` | Pop final stack element | **Result = 34** |

#### Infix to Prefix Conversion Method
Converting an infix expression to prefix notation leverages the standard infix-to-postfix algorithm through a three-step reversal technique:
1. **Reverse the Infix Expression**: Reverse the character sequence of the input infix string. During reversal, swap opening brackets `(` with closing brackets `)` and vice versa.
2. **Convert to Postfix**: Apply the standard infix-to-postfix conversion algorithm to the modified expression.
3. **Reverse the Postfix Result**: Reverse the output generated in step 2 to produce the final prefix expression.

##### Worked Step-by-Step Example
Convert Infix Expression: $(A + B) * C$
1. Reverse and interchange parentheses: $C * (B + A)$
2. Convert $C * (B + A)$ to postfix:
   * Tokens: `C`, `*`, `(`, `B`, `+`, `A`, `)`
   * Output: `C B A + *`
3. Reverse postfix result: `* + A B C`

Final Prefix Expression: `* + A B C`

#### Evaluation of Prefix Expressions
To evaluate a prefix expression, the string is scanned **from right to left**:
1. If the token is an operand, push it onto the stack.
2. If the token is an operator, pop two operands: $S_1$ (first popped) and $S_2$ (second popped). Calculate $S_1 \text{ operator } S_2$ (note the order of operands), and push the result back onto the stack.

---

### 2.3 Applications of Stack – Recursion and Call Stack

#### Recursion Definition and Core Mechanics
**Recursion** is a programming technique in which a function calls itself directly or indirectly to solve a problem by decomposing it into smaller sub-problems of the same type. 

Every valid recursive function must contain two essential components:
1. **Base Case**: A terminating condition that returns a direct value without making further recursive calls, preventing infinite recursion.
2. **Recursive Step**: The operational logic that reduces the problem instance and invokes the function recursively toward the base case.

#### The System Call Stack and Activation Records
The operating system handles recursive function execution using an internal **Call Stack**. Whenever a function is invoked:
1. The system creates an **Activation Record (Stack Frame)** containing:
   * Function parameters passed to the call.
   * Local variables declared inside the function.
   * Return address (the code location to resume after execution completes).
   * Temporary evaluation data.
2. The newly created stack frame is **pushed** onto the call stack.
3. When a function reaches its base case or completes execution, its stack frame is **popped** from the top of the call stack, restoring execution context to the calling function.

#### Mathematical Recursive Algorithms

##### 1. Factorial Function
The factorial of a non-negative integer $n$ ($n!$) is defined recursively as:
$$\text{fact}(n) = \begin{cases} 1 & \text{if } n = 0 \text{ or } n = 1 \quad \text{(Base Case)} \\ n \times \text{fact}(n - 1) & \text{if } n > 1 \quad \text{(Recursive Step)} \end{cases}$$

##### 2. Greatest Common Divisor (Euclid's Algorithm)
Euclid's algorithm calculates the Greatest Common Divisor ($\text{GCD}$) of two positive integers $a$ and $b$ ($a \ge b$):
$$\text{gcd}(a, b) = \begin{cases} a & \text{if } b = 0 \quad \text{(Base Case)} \\ \text{gcd}(b, a \pmod b) & \text{if } b > 0 \quad \text{(Recursive Step)} \end{cases}$$

##### 3. Fibonacci Sequence
The Fibonacci sequence ($0, 1, 1, 2, 3, 5, 8, 13, \dots$) is defined recursively as:
$$\text{fib}(n) = \begin{cases} 0 & \text{if } n = 0 \quad \text{(Base Case 1)} \\ 1 & \text{if } n = 1 \quad \text{(Base Case 2)} \\ \text{fib}(n - 1) + \text{fib}(n - 2) & \text{if } n > 1 \quad \text{(Recursive Step)} \end{cases}$$

##### 4. Tower of Hanoi
The Tower of Hanoi is a classic mathematical puzzle involving three pegs (Source $A$, Auxiliary $B$, Target $C$) and $n$ disks of differing diameters initially stacked on peg $A$ in decreasing order. The goal is to transfer all $n$ disks to peg $C$ adhering to three rules:
1. Move only one disk at a time.
2. Only the top disk of any peg can be moved.
3. No larger disk may be placed on top of a smaller disk.

**Recursive Solution Logic**:
* Move top $n-1$ disks from $A$ to $B$ using $C$ as auxiliary.
* Move the remaining largest disk $n$ directly from $A$ to $C$.
* Move $n-1$ disks from $B$ to $C$ using $A$ as auxiliary.

The minimum total number of disk moves required for $n$ disks is given by $2^n - 1$.

#### Explicit Stack Simulation of Recursion
Recursive functions can be converted into non-recursive iterative implementations using an explicit array stack. For instance, to calculate $n!$ iteratively, an array stack pushes numbers from $1$ up to $n$. A while loop then pops each element sequentially and accumulates the product into a running variable until the stack becomes empty.

---

### 2.4 Queue Data Structure and Linear Queue

#### Definition and FIFO Concept
A **Queue** is a linear non-primitive data structure operating under the **First-In-First-Out (FIFO)** discipline. Elements are added at one boundary, called the **rear**, and deleted from another boundary, called the **front**. 

Real-world examples include customer queues at a ticket counter or cars at a toll booth: the first individual entering the line is served and exits first.

```
       Dequeue (Delete)                         Enqueue (Insert)
         from Front                                 at Rear
             │                                         │
             ▼                                         ▼
      +--------------+--------------+--------------+--------------+
      |  Element 0   |  Element 1   |  Element 2   |  Element 3   |
      +--------------+--------------+--------------+--------------+
             ▲                                         ▲
             │                                         │
           front                                     rear
```

#### Queue ADT Operations
The Queue Abstract Data Type specifies the following primitive operations:

* `enqueue(x)`: Inserts element `x` at the rear of the queue.
* `dequeue()`: Removes and returns the element at the front of the queue.
* `isEmpty()`: Checks whether the queue contains zero elements (`front == -1` or `front > rear`).
* `isFull()`: Checks whether the queue has reached its maximum storage limit (`rear == size - 1` in linear array implementation).
* `display()`: Traversing and printing elements from `front` to `rear`.

#### Array and Linked List Representations of Queue
1. **Linear Array Representation**: Implemented using a 1D array of fixed capacity `size` along with integer index variables `front` and `rear`, both initialized to `-1`.
2. **Singly Linked List Representation**: Implemented using dynamic linked nodes. Pointer `front` points to the head node, and pointer `rear` points to the tail node. Enqueue appends nodes at `rear->next`, while Dequeue removes nodes from `front`.

#### Disadvantage of Linear Queue (Unusable Memory / Dead Space)
The primary limitation of an array-based linear queue is **false overflow / dead space allocation**. As dequeue operations occur, the `front` index increments upward. Once `rear` reaches `size - 1`, the queue signals an overflow condition (`Queue is Full`) upon subsequent enqueue attempts—even if previous dequeue operations have left indices $0$ through $\text{front}-1$ completely empty. This memory wastage makes standard linear array queues inefficient for continuous real-time execution.

---

### 2.5 Circular Queue (Ring Buffer)

#### Concept and Modulo Arithmetic
A **Circular Queue** resolves the dead space limitation of linear queues by logically connecting the last array position (`size - 1`) back to the first array position ($0$), forming a continuous circular memory ring.

Instead of standard linear incrementing (`rear = rear + 1`), pointer transitions in a circular queue utilize **modulo arithmetic**:
$$\text{rear} = (\text{rear} + 1) \pmod{\text{size}}$$
$$\text{front} = (\text{front} + 1) \pmod{\text{size}}$$

#### Operational Boundary Conditions
* **Initial State**: `front = -1`, `rear = -1`.
* **Queue Full Condition**: Occurs when incrementing `rear` circularly matches `front`:
  $$(\text{rear} + 1) \pmod{\text{size}} == \text{front}$$
  Or equivalently: `(front == 0 && rear == size - 1)`.
* **Queue Empty Condition**: `front == -1`.

---

### 2.6 Priority Queue

#### Concept and Priority Rules
A **Priority Queue** is an abstract data structure variant where every inserted element has an associated **priority value**. Unlike standard FIFO queues, element extraction occurs based on relative priority rather than arrival time:
1. Higher priority elements are dequeued before lower priority elements.
2. Elements sharing identical priority values are processed according to standard FIFO ordering.

#### Types of Priority Queues
* **Max-Priority Queue**: The element possessing the **highest numerical priority value** is deleted/extracted first.
* **Min-Priority Queue**: The element possessing the **lowest numerical priority value** is deleted/extracted first.

#### Array Implementation Trade-offs
A priority queue can be implemented using arrays in two primary ways:

1. **Unsorted Array Representation**:
   * Enqueue: Simply append element to end of array $\to$ Time Complexity: $O(1)$.
   * Dequeue: Scan entire array to find max/min priority item, remove it, and shift elements $\to$ Time Complexity: $O(n)$.
2. **Sorted Array Representation**:
   * Enqueue: Search correct position based on priority and shift elements to maintain sorted order $\to$ Time Complexity: $O(n)$.
   * Dequeue: Direct removal of element from the end of array $\to$ Time Complexity: $O(1)$.

---

## 3. Important Definitions

1. **Stack**: A linear, non-primitive data structure operating on the Last-In-First-Out (LIFO) principle, where insertions and deletions occur exclusively at the top boundary.
2. **PUSH Operation**: The process of adding a new element onto the top of a stack.
3. **POP Operation**: The process of removing and returning the top element from a stack.
4. **Stack Overflow**: A boundary error condition raised when a PUSH operation is attempted on a stack that is already at maximum capacity (`top == size - 1`).
5. **Stack Underflow**: A boundary error condition raised when a POP operation is attempted on an empty stack (`top == -1`).
6. **Infix Notation**: Arithmetic expression syntax where operators appear between operands (e.g., $A + B$).
7. **Postfix Notation (RPN)**: Syntax where operators follow their operands (e.g., $A B +$), enabling single-pass computational evaluation without parentheses.
8. **Prefix Notation**: Syntax where operators precede their operands (e.g., $+ A B$).
9. **Recursion**: A programming technique where a function calls itself directly or indirectly to solve smaller instances of a problem.
10. **Activation Record (Stack Frame)**: A memory structure allocated on the system call stack during a function call to store parameters, local variables, and return addresses.
11. **Queue**: A linear non-primitive data structure operating on the First-In-First-Out (FIFO) principle, featuring separate `front` (deletion) and `rear` (insertion) boundaries.
12. **Enqueue**: The operation of adding an element to the rear of a queue.
13. **Dequeue**: The operation of removing an element from the front of a queue.
14. **Circular Queue (Ring Buffer)**: A queue implementation where the end of the storage array wraps around to the beginning using modulo arithmetic, preventing dead space memory wastage.
15. **Priority Queue**: A queue variant where elements are dequeued based on assigned priority values rather than arrival order.

---

## 4. Algorithms and Their Explanations

### 4.1 Stack PUSH Algorithm (Array-Based)
```
Algorithm PUSH(a, size, top, item)
Step 1: [Check Overflow Condition]
        If top >= size - 1 Then
            Print "Stack Overflow: Unable to insert item"
            Return
        EndIf
Step 2: [Increment Stack Pointer]
        Set top = top + 1
Step 3: [Insert New Element]
        Set a[top] = item
Step 4: [Exit]
        Return
```

### 4.2 Stack POP Algorithm (Array-Based)
```
Algorithm POP(a, top)
Step 1: [Check Underflow Condition]
        If top == -1 Then
            Print "Stack Underflow: Stack is empty"
            Return NULL
        EndIf
Step 2: [Retrieve Top Element]
        Set item = a[top]
Step 3: [Decrement Stack Pointer]
        Set top = top - 1
Step 4: [Return Output]
        Return item
```

### 4.3 Infix to Postfix Conversion Algorithm
```
Algorithm InfixToPostfix(infix_str)
Step 1: Initialize an empty operator stack and empty postfix output string.
Step 2: For each token in infix_str scanned from left to right:
        a. If token is an operand (letter/number), append to postfix output.
        b. If token is '(', push onto operator stack.
        c. If token is ')', pop operators from stack to postfix output 
           until '(' is encountered. Pop and discard '('.
        d. If token is an operator op1:
           While stack is not empty AND top of stack != '(' AND 
                 Precedence(top) >= Precedence(op1):
               Pop operator from stack and append to postfix output.
           EndWhile
           Push op1 onto operator stack.
Step 3: While operator stack is not empty:
        Pop top operator and append to postfix output.
Step 4: Return postfix output string.
```

### 4.4 Postfix Expression Evaluation Algorithm
```
Algorithm EvaluatePostfix(postfix_str)
Step 1: Initialize an empty numerical operand stack.
Step 2: For each token in postfix_str scanned from left to right:
        a. If token is a number/operand, push token value onto stack.
        b. If token is an operator op:
           Pop top element from stack and assign to S1.
           Pop next top element from stack and assign to S2.
           Compute result = S2 op S1.
           Push result onto stack.
Step 3: Pop final remaining value from stack and return as expression result.
```

### 4.5 Recursive Factorial Algorithm
```
Algorithm RecursiveFactorial(n)
Step 1: [Base Case]
        If n == 0 OR n == 1 Then
            Return 1
        EndIf
Step 2: [Recursive Step]
        Return n * RecursiveFactorial(n - 1)
```

### 4.6 Linear Queue Enqueue Algorithm
```
Algorithm LinearEnqueue(q, size, front, rear, item)
Step 1: [Check Queue Overflow]
        If rear >= size - 1 Then
            Print "Queue Overflow: Queue is full"
            Return
        EndIf
Step 2: [Set Front Pointer on First Insertion]
        If front == -1 Then
            Set front = 0
        EndIf
Step 3: [Increment Rear and Insert]
        Set rear = rear + 1
        Set q[rear] = item
Step 4: Return
```

### 4.7 Linear Queue Dequeue Algorithm
```
Algorithm LinearDequeue(q, front, rear)
Step 1: [Check Queue Underflow]
        If front == -1 OR front > rear Then
            Print "Queue Underflow: Queue is empty"
            Return NULL
        EndIf
Step 2: [Retrieve Front Element]
        Set item = q[front]
Step 3: [Advance Front Pointer]
        Set front = front + 1
Step 4: [Reset Queue Pointers If Empty]
        If front > rear Then
            Set front = -1
            Set rear = -1
        EndIf
Step 5: Return item
```

### 4.8 Circular Queue Enqueue Algorithm
```
Algorithm CircularEnqueue(q, size, front, rear, item)
Step 1: [Check Circular Overflow]
        If (rear + 1) % size == front Then
            Print "Circular Queue Overflow: Queue is full"
            Return
        EndIf
Step 2: [Set Front Pointer on First Insertion]
        If front == -1 Then
            Set front = 0
        EndIf
Step 3: [Circularly Advance Rear and Insert]
        Set rear = (rear + 1) % size
        Set q[rear] = item
Step 4: Return
```

---

## 5. Complexity Analysis

### Time and Space Complexity Summary Table

The table below summarizes the time and space complexity bounds for all core operations covered in Chapter 02.

| Data Structure / Operation | Best Case Time | Average Case Time | Worst Case Time | Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **Stack Push Operation** | $\Theta(1)$ | $\Theta(1)$ | $O(1)$ | $O(1)$ auxiliary |
| **Stack Pop Operation** | $\Theta(1)$ | $\Theta(1)$ | $O(1)$ | $O(1)$ auxiliary |
| **Infix to Postfix Conversion** | $\Theta(n)$ | $\Theta(n)$ | $O(n)$ | $O(n)$ stack space |
| **Postfix Expression Evaluation** | $\Theta(n)$ | $\Theta(n)$ | $O(n)$ | $O(n)$ stack space |
| **Recursive Factorial** | $\Theta(n)$ | $\Theta(n)$ | $O(n)$ | $O(n)$ call stack |
| **Recursive GCD (Euclid)** | $\Theta(1)$ | $\Theta(\log(\min(a,b)))$ | $O(\log(\min(a,b)))$ | $O(\log(\min(a,b)))$ call stack |
| **Linear Queue Enqueue / Dequeue** | $\Theta(1)$ | $\Theta(1)$ | $O(1)$ | $O(1)$ auxiliary |
| **Circular Queue Enqueue / Dequeue** | $\Theta(1)$ | $\Theta(1)$ | $O(1)$ | $O(1)$ auxiliary |
| **Priority Queue (Unsorted Array)** | Enqueue: $O(1)$ | Enqueue: $O(1)$ | Dequeue: $O(n)$ | $O(n)$ total array space |
| **Priority Queue (Sorted Array)** | Dequeue: $O(1)$ | Enqueue: $O(n)$ | Enqueue: $O(n)$ | $O(n)$ total array space |

#### Explanation of $O(1)$ Time Complexity for Stack Operations
All stack operations (`push`, `pop`, `isEmpty`, `isFull`) execute in constant time $O(1)$ because insertions and deletions occur directly at the single index tracked by `top`. No array element shifting, traversal, or searching is required regardless of total stack size.

---

## 6. Comparisons and Tables

### 6.1 Stack vs Queue
The table below contrasts the fundamental characteristics of Stack and Queue data structures.

| Feature / Attribute | Stack Data Structure | Queue Data Structure |
| :--- | :--- | :--- |
| **Access Principle** | Last-In-First-Out (LIFO) | First-In-First-Out (FIFO) |
| **Operational Boundaries** | Single boundary: `top` | Two boundaries: `front` (deletion) and `rear` (insertion) |
| **Primary Operations** | `push(x)` and `pop()` | `enqueue(x)` and `dequeue()` |
| **Pointer Mechanics** | `top` increments on push, decrements on pop | `rear` increments on enqueue, `front` increments on dequeue |
| **Primary Applications** | Expression parsing, call stack recursion, undo mechanisms | Task scheduling, print spooling, network buffer management |

### 6.2 Linear Queue vs Circular Queue
The table below compares linear queues against circular queues regarding memory utilization and pointer logic.

| Feature / Attribute | Linear Queue | Circular Queue (Ring Buffer) |
| :--- | :--- | :--- |
| **Array Structure** | Sequential straight line | Logical continuous ring |
| **Pointer Increment Logic** | `rear = rear + 1` | `rear = (rear + 1) % size` |
| **Memory Reuse** | Poor: Vacated front slots cannot be reused | Excellent: Vacated slots are reused via wrap-around |
| **Full Condition** | `rear == size - 1` | `(rear + 1) % size == front` |
| **False Overflow Problem** | Suffers from false overflow / dead memory | Completely eliminates false overflow |

---

## 7. Programming Questions

All C programming implementations for Chapter 02 are structured below as examination programming questions along with execution logic breakdowns and exact `.c` filename mappings.

### Question 1: Stack Implementation Using Array
**Programming Question**: Write a menu-driven C program to implement a static Stack using a 1D array supporting `push`, `pop`, and `display` operations.  
**Separate C File**: `Stack_Array.c`  
**Key Logic Breakdown**: Maintain array `stk[MAX]` and integer `top = -1`. The `push()` function checks `top == MAX - 1` before incrementing `top` and assigning `stk[top] = item`. The `pop()` function checks `top == -1` before returning `stk[top--]`.

### Question 2: Infix to Postfix Conversion
**Programming Question**: Write a C program to convert a given infix arithmetic expression string into its equivalent postfix expression using an operator stack.  
**Separate C File**: `Infix_To_Postfix.c`  
**Key Logic Breakdown**: Read expression character by character. Use helper function `precedence(op)` returning integer priorities (Power: 3, `*`/`/`: 2, `+`/`-`: 1). Handle parentheses and operator precedence matching.

### Question 3: Postfix Expression Evaluation
**Programming Question**: Write a C program to evaluate a valid postfix arithmetic expression using an integer operand stack.  
**Separate C File**: `Postfix_Evaluation.c`  
**Key Logic Breakdown**: Scan postfix string. Push numeric digits onto `int stack[]`. When an operator is encountered, pop `val1 = pop()` and `val2 = pop()`, perform `switch(op)` for result `val2 op val1`, and push the outcome.

### Question 4: Infix to Prefix Conversion
**Programming Question**: Write a C program to convert an infix expression into prefix notation using string reversal and postfix logic.  
**Separate C File**: `Infix_To_Prefix.c`  
**Key Logic Breakdown**: Reverse input string while swapping `(` and `)`. Call `infixToPostfix()` on the reversed string. Reverse the resulting postfix string to obtain the prefix output.

### Question 5: Recursive Factorial Calculation
**Programming Question**: Write a C program to compute the factorial of a user-entered integer using a recursive function.  
**Separate C File**: `Recursive_Factorial.c`  
**Key Logic Breakdown**: Define function `long fact(int n)`. Return `1` if `n <= 1` (base case); otherwise return `n * fact(n - 1)`.

### Question 6: Stack-Based Non-Recursive Factorial
**Programming Question**: Write a C program to calculate the factorial of a number non-recursively using an explicit stack array.  
**Separate C File**: `Stack_Factorial.c`  
**Key Logic Breakdown**: Push integers $1, 2, \dots, n$ onto `int stk[]`. Execute `while(top != -1)` loop popping elements and accumulating `fact = fact * pop()`.

### Question 7: Recursive Greatest Common Divisor (GCD)
**Programming Question**: Write a C program to find the Greatest Common Divisor (GCD) of two integers using Euclid's recursive algorithm.  
**Separate C File**: `Recursive_GCD.c`  
**Key Logic Breakdown**: Define `int gcd(int a, int b)`. Return `a` if `b == 0`; otherwise return `gcd(b, a % b)`.

### Question 8: Stack-Based Non-Recursive GCD
**Programming Question**: Write a C program to compute the GCD of two numbers non-recursively by simulating division steps on an explicit stack.  
**Separate C File**: `Stack_GCD.c`  
**Key Logic Breakdown**: Push `a` and `b` onto stack. Pop `b` and `a`, then execute a `while(b != 0)` loop updating `temp = a; b = a % b; a = temp;` until `b` equals zero.

### Question 9: Recursive Fibonacci Series
**Programming Question**: Write a C program to generate the Fibonacci series up to $n$ terms using a recursive function.  
**Separate C File**: `Recursive_Fibonacci.c`  
**Key Logic Breakdown**: Define `int fib(int n)`. Return `0` if `n==0`, `1` if `n==1`; otherwise return `fib(n-1) + fib(n-2)`. Iterate `for(i=0; i<n; i++)` printing `fib(i)`.

### Question 10: Tower of Hanoi Puzzle
**Programming Question**: Write a C program to solve the Tower of Hanoi puzzle for $n$ disks using recursion and display individual disk transfers.  
**Separate C File**: `Tower_Of_Hanoi.c`  
**Key Logic Breakdown**: Function `hanoi(n, src, aux, dest)`. Base case `n==1`: print move from `src` to `dest`. Recursive step: `hanoi(n-1, src, dest, aux)`, print move, then `hanoi(n-1, aux, src, dest)`.

### Question 11: Linear Queue Implementation Using Array
**Programming Question**: Write a menu-driven C program to implement a Linear Queue using a 1D array supporting `enqueue`, `dequeue`, and `display` operations.  
**Separate C File**: `Linear_Queue_Array.c`  
**Key Logic Breakdown**: Array `q[size]`, `front = -1`, `rear = -1`. Enqueue checks `rear >= size - 1`. Dequeue checks `front == -1 || front > rear` and resets pointers to `-1` when empty.

### Question 12: Circular Queue Implementation Using Array
**Programming Question**: Write a menu-driven C program to implement a Circular Queue using a 1D array and modulo arithmetic indexing.  
**Separate C File**: `Circular_Queue_Array.c`  
**Key Logic Breakdown**: Enqueue checks `(rear + 1) % size == front`. Pointer updates use `rear = (rear + 1) % size` and `front = (front + 1) % size`.

---

## 8. Important Short-Answer Questions

### Question 1: What is a Stack? Why is it called a LIFO data structure?
**Answer**: A stack is a linear, non-primitive data structure where element insertion (`push`) and deletion (`pop`) occur strictly at one end called `top`. It is called a Last-In-First-Out (LIFO) structure because the item inserted most recently is always the first one to be removed.

### Question 2: Differentiate between Stack Overflow and Stack Underflow.
**Answer**: Stack Overflow occurs when attempting to push an element onto a stack that has reached its maximum storage capacity (`top == size - 1`). Stack Underflow occurs when attempting to pop an element from an empty stack (`top == -1`).

### Question 3: What is an Activation Record (Stack Frame)?
**Answer**: An Activation Record or Stack Frame is a contiguous block of memory pushed onto the system call stack whenever a function is called. It stores the function's parameters, local variables, temporary variables, and return instruction address.

### Question 4: State the primary disadvantage of a linear queue implemented using an array.
**Answer**: The main disadvantage is memory wastage due to unusable dead space. Once elements are dequeued, `front` advances forward. When `rear` reaches `size - 1`, the queue signals a full overflow condition even if front indices are vacant.

### Question 5: How does a Circular Queue eliminate memory wastage?
**Answer**: A Circular Queue connects the last array index back to the first index using modulo arithmetic indexing: $\text{rear} = (\text{rear} + 1) \pmod{\text{size}}$. This allows vacated front positions to be reused for new element insertions.

---

## 9. Important 4-Mark Questions with Answers

### Question 1: Explain the algorithm for converting an Infix expression to Postfix using a stack.
**Answer**:  
The algorithm converts an infix expression string to postfix notation using an operator stack:
1. Scan the infix string from left to right token by token.
2. If the token is an operand (letter/number), append it directly to the postfix output.
3. If the token is an opening bracket `(`, push it onto the operator stack.
4. If the token is a closing bracket `)`, pop operators from the stack to the output until `(` is encountered; pop and discard `(`.
5. If the token is an operator $op_1$, compare its precedence with the top stack operator $op_2$. While the stack is non-empty and precedence($op_2$) $\ge$ precedence($op_1$), pop $op_2$ to output. Push $op_1$ onto the stack.
6. Once the infix string scan finishes, pop all remaining stack operators to the postfix output.

### Question 2: Explain how the system call stack handles recursive function calls using Factorial as an example.
**Answer**:  
When a recursive function such as `fact(n)` is executed, the runtime environment manages execution using the system call stack:
1. For each function call `fact(k)`, a stack frame containing parameter `k`, local variables, and the return address is created and pushed onto the call stack.
2. For `fact(3)`, call frames are pushed sequentially: `fact(3) -> fact(2) -> fact(1)`.
3. When `fact(1)` is reached, it satisfies the base case ($1 \le 1$) and returns `1` without further recursive calls.
4. The call stack pops frames in reverse order (LIFO): `fact(1)` pops returning `1` to `fact(2)`, which computes $2 \times 1 = 2$ and pops. `fact(3)` computes $3 \times 2 = 6$ and pops the final answer.

### Question 3: Describe the operations of a Circular Queue along with overflow and underflow conditions.
**Answer**:  
A Circular Queue manages data in a ring buffer using modulo arithmetic:
* **Enqueue Operation**: Adds an item at `rear = (rear + 1) % size`.
* **Dequeue Operation**: Removes an item from `front = (front + 1) % size`.
* **Overflow Condition**: Occurs when the next circular rear index matches front:
  $$(\text{rear} + 1) \pmod{\text{size}} == \text{front}$$
* **Underflow Condition**: Occurs when `front == -1`, indicating the queue contains zero elements.

### Question 4: Compare Max-Priority Queue and Min-Priority Queue with examples.
**Answer**:  
A Priority Queue extracts elements based on assigned priority values:
* **Max-Priority Queue**: Dequeues the element possessing the highest numerical priority first. For example, given data-priority pairs `(A, 2), (B, 5), (C, 1)`, deletion extracts `(B, 5)` first because priority $5$ is maximum.
* **Min-Priority Queue**: Dequeues the element possessing the lowest numerical priority first. Given the same pairs `(A, 2), (B, 5), (C, 1)`, deletion extracts `(C, 1)` first because priority $1$ is minimum.

---

## 10. Important Long-Answer Questions

### Question 1: Describe the Stack ADT. Explain its memory representations using arrays and linked lists, and derive the time complexity of PUSH and POP operations.
**Answer Overview**:
1. Define Stack ADT and LIFO principle.
2. Detail Array Representation: Static allocation, `top` index variable, PUSH (`top++`), POP (`top--`), overflow (`top == size - 1`), underflow (`top == -1`).
3. Detail Linked List Representation: Dynamic allocation, `struct node { int data; struct node *next; }`, `top` pointer pointing to head. PUSH creates node and updates head; POP removes head node.
4. Derive Complexity: PUSH and POP perform constant primitive pointer/index assignments without loops. Hence, Time Complexity = $\Theta(1)$, Space Complexity = $O(1)$ auxiliary.

### Question 2: Explain Infix, Prefix, and Postfix notations. Convert the infix expression $(A + B) * (C - D) / E$ into postfix and prefix forms showing complete step-by-step stack status tables.
**Answer Overview**:
1. Define Infix, Prefix, and Postfix notations with operator placement rules.
2. Postfix Conversion Trace for $(A + B) * (C - D) / E$:
   * Step-by-step trace table showing scanned tokens, stack contents, and postfix buffer output.
   * Resulting Postfix: `A B + C D - * E /`
3. Prefix Conversion Trace (Reverse $\to$ Postfix $\to$ Reverse):
   * Reversed Infix: $E / (D - C) * (B + A)$
   * Intermediate Postfix: `E D C - / B A + *`
   * Final Reversed Prefix: `* / E - D C + B A`

### Question 3: What is Recursion? Explain Euclid's GCD algorithm and Tower of Hanoi puzzle with mathematical formulations, recursive algorithms, and step-by-step traces for $n=3$ disks.
**Answer Overview**:
1. Define Recursion, Base Case, and Recursive Step.
2. Explain Euclid's GCD: Formula $\text{gcd}(a,b) = \text{gcd}(b, a \pmod b)$, base case $b=0$.
3. Explain Tower of Hanoi: 3 pegs ($A, B, C$), rules, minimum steps $2^n - 1$.
4. Step Trace for $n=3$ disks ($2^3 - 1 = 7$ moves):
   * Move Disk 1 from A to C
   * Move Disk 2 from A to B
   * Move Disk 1 from C to B
   * Move Disk 3 from A to C
   * Move Disk 1 from B to A
   * Move Disk 2 from B to C
   * Move Disk 1 from A to C

### Question 4: Explain Linear Queue, Circular Queue, and Priority Queue. Compare their array representations, algorithms, boundary conditions, and real-world system applications.
**Answer Overview**:
1. Define Linear Queue, FIFO discipline, `front` and `rear` pointers, enqueue/dequeue algorithms.
2. Analyze Linear Queue Dead Space problem.
3. Explain Circular Queue ring buffer model, modulo indexing `(rear+1)%size`, full/empty conditions.
4. Explain Priority Queue max/min ordering and compare Unsorted Array ($O(1)$ Enqueue / $O(n)$ Dequeue) vs Sorted Array ($O(n)$ Enqueue / $O(1)$ Dequeue).
5. Highlight real-world applications: CPU scheduling, print spooling, network routers, hospital emergency triage.

---

## 11. Chapter Summary and Key Points

* **Stack ADT**: A linear data structure governed by the **Last-In-First-Out (LIFO)** access principle. All operations occur at the `top` boundary in $O(1)$ constant time.
* **Stack Boundary Conditions**: Overflow occurs when inserting into a full stack (`top == size - 1`). Underflow occurs when popping from an empty stack (`top == -1`).
* **Expression Parsing**: Postfix notation (RPN) is ideal for computer evaluation because it eliminates parentheses and operator precedence ambiguities.
* **Recursion Mechanics**: Recursive function execution relies on the system **Call Stack**, which allocates a **Stack Frame** for every function call containing parameters, local variables, and return addresses.
* **Queue ADT**: A linear structure operating under the **First-In-First-Out (FIFO)** access principle using separate `front` (deletion) and `rear` (insertion) boundaries.
* **Linear Queue Limitation**: Linear array queues suffer from dead memory allocation; vacated front indices cannot be reused once `rear` reaches capacity.
* **Circular Queue**: Eliminates dead memory space by linking array endpoints into a logical ring via modulo arithmetic indexing: $\text{rear} = (\text{rear} + 1) \pmod{\text{size}}$.
* **Priority Queue**: Processes elements based on assigned priority values (Max-Priority or Min-Priority) rather than arrival sequence.

# Chapter 01 -- Introduction to Data Structure

> **Subject:** Data Structures Using C\
> **Chapter:** 01 -- Introduction to Data Structure\
> **Purpose:** Concept learning, university examination preparation, and
> practical programming

------------------------------------------------------------------------

## 1. Introduction

Data Structures and Algorithms (DSA) are fundamental to computer
science. A **data structure** organizes data so that it can be stored,
accessed, and modified efficiently. An **algorithm** is a finite
sequence of well-defined steps used to solve a problem.

Together, data structures and algorithms help developers build efficient
software. They are used in operating systems, databases, compilers, web
browsers, navigation systems, and communication networks.

This chapter covers data and information, the need and classification of
data structures, common operations, algorithms, performance analysis,
asymptotic notation, time-space trade-offs, searching algorithms, and
basic array operations.

## 2. Topic-Wise Detailed Explanation

### 2.1 Data and Information

**Data** consists of raw facts, values, observations, or symbols. By
themselves, these values may not provide enough context to support a
decision.

Examples: - Student marks: `70, 80, 90` - Temperature readings:
`32°C, 34°C` - Roll numbers: `101, 102, 103`

**Information** is data that has been processed or organized to provide
meaning and context.

**Example:** - Raw data: `70, 80, 90` - Processing:
`(70 + 80 + 90) / 3 = 80` - Information: `The average mark is 80.`

  Attribute      Data                      Information
  -------------- ------------------------- -----------------------------------
  Meaning        Raw facts and values      Processed data with context
  Organization   May be unorganized        Organized for a purpose
  Role           Often used as input       Often produced as output
  Use            Requires interpretation   Helps understanding and decisions

### 2.2 Concept and Need of a Data Structure

A **data structure** is a way of organizing and storing data in computer
memory so that it can be accessed, updated, and processed efficiently.
It also describes relationships among data elements.

#### Why are data structures needed?

1.  **Efficient operations:** The right structure can make searching,
    insertion, deletion, and other operations faster.
2.  **Effective memory use:** Different structures use memory in
    different ways. Choosing appropriately can reduce unnecessary memory
    use.
3.  **Organizing relationships:** Structures represent different
    relationships, such as sequences, hierarchies, and networks.
4.  **Managing large data:** Well-chosen structures help applications
    handle growing amounts of data.
5.  **Simplifying program design:** A suitable structure makes data
    handling easier to understand and maintain.

### 2.3 Real-World Applications

1.  **Operating systems:** Queues are used in scheduling and buffering.
    Linked structures can help manage collections of processes or memory
    blocks.
2.  **Database systems:** B-trees and related balanced tree structures
    are commonly used in indexes. Hash tables can support key-based
    lookup.
3.  **Web browsers:** The Document Object Model (DOM) represents a web
    page as a hierarchy of nodes, which is tree-like.
4.  **Navigation systems:** Graphs model locations or intersections as
    vertices and roads or connections as edges. Graph algorithms can
    find routes.
5.  **Communication systems:** Queues buffer packets while they wait to
    be processed or transmitted. The exact structures depend on the
    system design.

### 2.4 Classification of Data Structures

A common introductory classification is:

``` text
                         Data Structures
                         /              \
                 Primitive          Non-Primitive
                                      /       \
                                   Linear   Non-Linear
```

#### A. Primitive Data Types

Primitive types are the basic types provided by a programming language.

Common C examples: - `char` -- stores a character. - `int` -- stores an
integer. - `float` -- stores a floating-point value. - `double` --
stores a floating-point value with greater precision than `float`. -
`_Bool` -- C's built-in Boolean integer type. The header `<stdbool.h>`
provides the name `bool` in C versions that support it.

> **C language note:** `boolean` is not a built-in C keyword. Use
> `_Bool` or, where available, `bool` from `<stdbool.h>`.

#### B. Non-Primitive Data Structures

These are structures built using basic data types to organize
collections of data.

**1. Linear data structures**

Elements are arranged in a sequence. Except at the ends, an element
generally has a predecessor and a successor in that sequence.

-   **Array:** Stores elements of the same type in contiguous memory
    locations. A conventional C array has a fixed size after it is
    created.
-   **Linked list:** Stores elements in nodes connected through links
    (pointers).
-   **Stack:** Follows Last-In, First-Out (LIFO).
-   **Queue:** Follows First-In, First-Out (FIFO).

**2. Non-linear data structures**

Elements are not arranged as one simple sequence. They may form
hierarchical or network relationships.

-   **Tree:** A hierarchical structure made of nodes connected by
    parent-child relationships.
-   **Graph:** A structure containing vertices connected by edges.

> **Classification note:** Hash tables are often taught as a separate
> associative or key-value structure. Some introductory syllabi place
> tables under non-linear structures, but a hash table is not inherently
> a tree or graph. Follow the classification used by your prescribed
> textbook or lecturer for examination wording.

### 2.5 Basic Data Structure Operations

1.  **Traversal:** Visiting elements to read or process them.
2.  **Searching:** Finding whether a target value exists and, if so,
    locating it.
3.  **Insertion:** Adding a new element.
4.  **Deletion:** Removing an existing element.
5.  **Sorting:** Arranging elements in a required order, such as
    ascending or descending.
6.  **Merging:** Combining two collections into one. In some contexts,
    merging specifically means combining two sorted sequences while
    preserving sorted order.

### 2.6 Algorithms and Their Characteristics

An **algorithm** is a finite sequence of clear, ordered steps that
solves a problem or performs a computation.

Common categories of operations supported by algorithms include
searching, sorting, insertion, updating, and deletion.

#### Characteristics of an Algorithm

1.  **Input:** It accepts zero or more clearly specified inputs.
2.  **Output:** It produces at least one clearly specified result.
3.  **Definiteness:** Every instruction is precise and unambiguous.
4.  **Finiteness:** It terminates after a finite number of steps.
5.  **Effectiveness:** Each step is basic enough to be carried out in
    practice.
6.  **Language independence:** The problem-solving logic can be
    expressed independently of a particular programming language.

### 2.7 Algorithm Analysis and Performance Evaluation

Algorithm analysis estimates the resources an algorithm needs as the
input size grows. It helps compare different solutions to the same
problem.

The two main resources are **time** and **space**.

#### A. Time Complexity

**Time complexity** describes how the number of basic operations
performed by an algorithm grows with input size, usually represented by
`n`.

It is generally expressed using asymptotic notation, rather than by
measuring a particular computer's clock time.

> **Important correction:** Time complexity is not calculated as
> `compile time + execution time`. Complexity analysis normally studies
> the algorithm's running operations as a function of input size;
> compilation time is not included in the algorithm's time complexity.

#### B. Space Complexity

**Space complexity** describes the memory required during execution as a
function of input size.

A commonly used conceptual expression is:

`S(P) = C + Sp(I)`

Where: - `S(P)` is the total space required by program `P`. - `C` is the
fixed space, such as fixed program instructions and fixed-size
variables. - `Sp(I)` is the variable space that depends on the input
instance `I`, such as input-dependent arrays, dynamic allocations, or
recursive call frames.

**Auxiliary space** is the extra working memory used by an algorithm,
excluding the memory occupied by the input itself. When comparing
algorithms, check whether a stated space complexity means total space or
auxiliary space.

**Example:** An iterative algorithm that scans an existing array and
uses only a fixed number of index and temporary variables has `O(1)`
auxiliary space. The input array itself occupies `O(n)` storage, but it
is not counted as auxiliary space.

### 2.8 Best, Average, and Worst Cases

An algorithm may perform differently for different inputs of the same
size.

1.  **Best case:** The input arrangement that causes the fewest
    operations.
    -   Linear search: the key is at the first position, so only one
        comparison is needed.
2.  **Average case:** The expected number of operations over an assumed
    distribution of inputs.
    -   For a successful linear search where the key is equally likely
        to be at any of the `n` positions, the average number of
        comparisons is `(n + 1) / 2`.
3.  **Worst case:** The input arrangement that causes the most
    operations.
    -   Linear search: the key is at the last position or is absent, so
        `n` comparisons may be required.

### 2.9 Asymptotic Notations

Asymptotic notation describes how an algorithm's resource requirements
grow as input size `n` becomes large. It ignores constant factors and
lower-order terms.

#### A. Big O -- Upper Bound

`T(n) = O(g(n))` means that, for sufficiently large `n`, the function
`T(n)` is bounded above by a constant multiple of `g(n)`.

Formally, there are positive constants `c` and `n₀` such that:

`0 ≤ T(n) ≤ c × g(n)` for all `n ≥ n₀`.

Example: `T(n) = 3n + 5` is `O(n)`.

#### B. Big Omega -- Lower Bound

`T(n) = Ω(g(n))` means that, for sufficiently large `n`, `T(n)` is
bounded below by a positive constant multiple of `g(n)`.

There are positive constants `c` and `n₀` such that:

`0 ≤ c × g(n) ≤ T(n)` for all `n ≥ n₀`.

Example: `3n + 5` is `Ω(n)`.

#### C. Big Theta -- Tight Bound

`T(n) = Θ(g(n))` means that, for sufficiently large `n`, `T(n)` is
bounded both above and below by positive constant multiples of `g(n)`.

There are positive constants `c₁`, `c₂`, and `n₀` such that:

`0 ≤ c₁ × g(n) ≤ T(n) ≤ c₂ × g(n)` for all `n ≥ n₀`.

Example: `5n² + 4n + 2` is `Θ(n²)`.

  -----------------------------------------------------------------------
  Notation                Meaning                 What it tells us
  ----------------------- ----------------------- -----------------------
  `O(g(n))`               Asymptotic upper bound  Growth does not exceed
                                                  this order, up to a
                                                  constant factor

  `Ω(g(n))`               Asymptotic lower bound  Growth is at least this
                                                  order, up to a constant
                                                  factor

  `Θ(g(n))`               Asymptotically tight    Both upper and lower
                          bound                   bounds have the same
                                                  order
  -----------------------------------------------------------------------

> **Important exam clarification:** Big O is often used when reporting
> worst-case complexity, and Omega is often used for best-case
> complexity. However, the notations themselves mean upper bound, lower
> bound, and tight bound. They do not automatically mean worst, best,
> and average case. Theta does not automatically mean average case.

#### Common Growth Rates

  Function         Complexity class
  ---------------- ------------------
  `7`              `O(1)`
  `3n + 2`         `O(n)`
  `4n² + 3n + 1`   `O(n²)`
  `n³ + 2n`        `O(n³)`
  `log₂ n`         `O(log n)`

### 2.10 Time-Space Trade-Off

A **time-space trade-off** occurs when an algorithm uses more memory to
reduce execution work, or uses less memory at the cost of additional
computation.

Examples: - A lookup table stores precomputed results, using extra
memory to make later lookups faster. - A hash table uses additional
storage to support fast average-case key lookup. - An algorithm that
repeatedly recalculates values may save memory but take more time.

**Linear search example:** - Time complexity: `O(n)` in the worst
case. - Auxiliary space: `O(1)`.

**Hash table example:** - Search is typically `O(1)` on average with a
suitable hash function and controlled load factor. - Worst-case search
can be `O(n)` if many keys collide. - Storage is generally proportional
to the number of stored entries, or `O(n)`.

Therefore, it is inaccurate to describe hash-table search as guaranteed
`O(1)` in every case.

### 2.11 Searching Algorithms

Searching is the process of locating a target value in a collection.

#### A. Linear Search (Sequential Search)

Linear search checks elements one by one until the target is found or
all elements have been checked.

**Example:** Search for `30` in `[10, 20, 30, 40, 50]`.

  Comparison     Value checked Result
  ------------ --------------- -------------
  1                         10 Not a match
  2                         20 Not a match
  3                         30 Match found

The key is found at zero-based index `2`, which is position `3` when
positions are counted from `1`.

**Algorithm: `LINEAR_SEARCH(A, N, KEY)`**

``` text
Input: Array A of N elements and target KEY
Output: Index of KEY if found; otherwise NOT FOUND

1. Set i = 0.
2. While i < N:
      If A[i] equals KEY:
          Return i.
      Set i = i + 1.
3. Return NOT FOUND.
```

**Complexity:** - Best case: `Θ(1)` -- key is the first element. -
Average case: `Θ(n)` under the usual uniform-position assumption for a
successful search. - Worst case: `Θ(n)` -- key is last or absent. -
Auxiliary space: `Θ(1)`.

**Advantages:** - Simple to understand and implement. - Works on sorted
and unsorted collections. - Requires no extra array or sorting step.

**Disadvantages:** - May examine every element. - Becomes inefficient
for very large collections compared with suitable faster search methods.

#### B. Binary Search

Binary search repeatedly halves the search interval. It requires the
array to be **sorted**.

**Working steps:** 1. Set `low = 0` and `high = n - 1`. 2. Calculate the
middle index: `mid = low + (high - low) / 2`. 3. If `A[mid]` equals the
key, return `mid`. 4. If the key is smaller, continue in the left half
by setting `high = mid - 1`. 5. If the key is larger, continue in the
right half by setting `low = mid + 1`. 6. If `low > high`, the key is
not present.

**Worked example:** Search for `18` in `[10, 6, 16, 18, 80, 75]`.

First, sort the array:

`[6, 10, 16, 18, 75, 80]`

  Iteration     `low`   `high`   `mid`   `A[mid]` Action
  ----------- ------- -------- ------- ---------- ------------------------------
  1                 0        5       2         16 `18 > 16`, search right half
  2                 3        5       4         75 `18 < 75`, search left half
  3                 3        3       3         18 Match found

The key is found at index `3` (position `4`) after three iterations.

**Algorithm: `BINARY_SEARCH(A, N, KEY)`**

``` text
Input: Sorted array A of N elements and target KEY
Output: Index of KEY if found; otherwise NOT FOUND

1. Set low = 0 and high = N - 1.
2. While low <= high:
      mid = low + (high - low) / 2.
      If A[mid] equals KEY:
          Return mid.
      Else if KEY < A[mid]:
          Set high = mid - 1.
      Else:
          Set low = mid + 1.
3. Return NOT FOUND.
```

**Complexity:** - Best case: `Θ(1)` -- key is at the first midpoint. -
Average case: `Θ(log n)`. - Worst case: `Θ(log n)`. - Auxiliary space
for the iterative version: `Θ(1)`.

**Advantages:** - Efficient for large, sorted arrays. - Reduces the
search interval by approximately half at each iteration.

**Disadvantages:** - Requires sorted data. - Maintaining sorted order
can add cost when data changes frequently. - The iterative
implementation requires careful boundary handling.

### 2.12 Array and Its Operations

An **array** is a collection of elements of the same data type stored in
contiguous memory locations. In C, array indexing starts at `0`.

For an array with `n` elements, valid indices are `0` through `n - 1`.

#### A. Traversal

Traversal means visiting each element, usually from index `0` to
`n - 1`.

``` text
For i = 0 to n - 1:
    Visit or display A[i].
```

Time complexity: `Θ(n)`\
Auxiliary space: `Θ(1)`.

#### B. Insertion at a Given Position

Assume: - `n` is the current number of elements. - The array has enough
capacity for one more element. - `pos` is a one-based position, from `1`
to `n + 1`.

Steps: 1. Check that `1 ≤ pos ≤ n + 1` and that capacity is available.
2. Starting from the last element, shift elements one position to the
right. 3. Store the new element at index `pos - 1`. 4. Increase `n` by
one.

``` text
For i = n down to pos:
    A[i] = A[i - 1]
A[pos - 1] = ELEMENT
n = n + 1
```

#### C. Deletion at a Given Position

Assume `pos` is a one-based position from `1` to `n`.

Steps: 1. Check that `1 ≤ pos ≤ n`. 2. Shift elements after the deleted
element one position to the left. 3. Decrease `n` by one.

``` text
For i = pos - 1 to n - 2:
    A[i] = A[i + 1]
n = n - 1
```

#### Array Operation Complexity

  -----------------------------------------------------------------------
  Operation               Time complexity         Explanation
  ----------------------- ----------------------- -----------------------
  Access by index         `O(1)`                  Direct index
                                                  calculation

  Traversal               `O(n)`                  Visits all elements

  Search (unsorted array) `O(n)`                  May inspect every
                                                  element

  Insertion at beginning  `O(n)`                  Existing elements must
                                                  shift

  Insertion at end        `O(1)`                  If capacity is
                                                  available

  Insertion at an         `O(n)`                  May require shifting
  arbitrary position                              

  Deletion at beginning   `O(n)`                  Remaining elements
                                                  shift left

  Deletion at end         `O(1)`                  Only the logical size
                                                  changes

  Deletion at an          `O(n)`                  Following elements may
  arbitrary position                              shift
  -----------------------------------------------------------------------

> **Array capacity note:** Insertion at the end is `O(1)` only when
> there is already free capacity. If a new larger array must be
> allocated and elements copied, that insertion takes `O(n)` time.

## 3. Important Definitions

-   **Data:** Raw facts, values, or observations that may need
    processing to become meaningful.
-   **Information:** Processed or organized data that provides meaning
    and context.
-   **Data structure:** A method of organizing and storing data for
    efficient access and modification.
-   **Primitive data type:** A basic type provided by a programming
    language, such as `int` or `char` in C.
-   **Linear data structure:** A structure whose elements are organized
    in a sequence.
-   **Non-linear data structure:** A structure whose elements form
    hierarchical or network relationships.
-   **Algorithm:** A finite sequence of precise steps for solving a
    problem.
-   **Traversal:** Visiting elements of a data structure for processing.
-   **Searching:** Finding the location of a target value.
-   **Insertion:** Adding an element to a data structure.
-   **Deletion:** Removing an element from a data structure.
-   **Time complexity:** The growth rate of an algorithm's operation
    count with input size.
-   **Space complexity:** The growth rate of memory required by an
    algorithm.
-   **Asymptotic notation:** Mathematical notation used to describe
    growth rates, such as `O`, `Ω`, and `Θ`.
-   **Time-space trade-off:** The exchange between memory use and
    execution work.
-   **Linear search:** A search method that checks elements
    sequentially.
-   **Binary search:** A search method that repeatedly halves a sorted
    search interval.
-   **Array:** A collection of same-type elements stored in contiguous
    memory locations.

## 4. Algorithms -- Quick Reference

The full explanations are in Section 2. The key algorithms in this
chapter are:

1.  `LINEAR_SEARCH(A, N, KEY)` -- scans elements sequentially.
2.  `BINARY_SEARCH(A, N, KEY)` -- searches a sorted array by halving the
    interval.
3.  `ARRAY_TRAVERSE(A, N)` -- visits each valid array element.
4.  `ARRAY_INSERT(A, N, POS, ELEMENT)` -- shifts elements right and
    inserts an element.
5.  `ARRAY_DELETE(A, N, POS)` -- shifts following elements left and
    reduces the logical size.

## 5. Complexity Analysis -- Revision Table

  ------------------------------------------------------------------------
  Algorithm /       Best case   Average case     Worst case      Auxiliary
  Operation                                                          space
  ------------ -------------- -------------- -------------- --------------
  Linear               `O(1)`         `O(n)`         `O(n)`         `O(1)`
  search                                                    

  Iterative            `O(1)`     `O(log n)`     `O(log n)`         `O(1)`
  binary                                                    
  search                                                    

  Array                `O(n)`         `O(n)`         `O(n)`         `O(1)`
  traversal                                                 

  Array                `O(n)`         `O(n)`         `O(n)`         `O(1)`
  insertion at                                              
  beginning                                                 

  Array                `O(1)`         `O(1)`         `O(1)`         `O(1)`
  insertion at                                              
  end                                                       
  (capacity                                                 
  available)                                                

  Array                `O(n)`         `O(n)`         `O(n)`         `O(1)`
  deletion at                                               
  beginning                                                 

  Array                `O(1)`         `O(1)`         `O(1)`         `O(1)`
  deletion at                                               
  end                                                       
  ------------------------------------------------------------------------

## 6. Comparisons

### 6.1 Primitive vs Non-Primitive Data Types

  -----------------------------------------------------------------------
  Feature                 Primitive               Non-Primitive
  ----------------------- ----------------------- -----------------------
  Meaning                 Basic language-provided Structures formed to
                          types                   organize collections of
                                                  values

  Examples                `int`, `char`, `float`, Array, linked list,
                          `double`                stack, queue, tree,
                                                  graph

  Purpose                 Represent individual    Organize related values
                          values                  and relationships
  -----------------------------------------------------------------------

### 6.2 Linear vs Non-Linear Data Structures

  -----------------------------------------------------------------------
  Feature                 Linear                  Non-linear
  ----------------------- ----------------------- -----------------------
  Arrangement             Sequential              Hierarchical or
                                                  network-based

  Relationships           Usually                 Parent-child or
                          predecessor/successor   many-to-many
                          relationships           relationships

  Traversal               Often follows a         May have multiple
                          sequence                traversal paths

  Examples                Array, linked list,     Tree, graph
                          stack, queue            
  -----------------------------------------------------------------------

### 6.3 Linear Search vs Binary Search

  Feature                       Linear search                   Binary search
  ----------------------------- ------------------------------- --------------------------------
  Data requirement              Sorted or unsorted              Must be sorted
  Method                        Sequential checking             Repeatedly halves the interval
  Worst-case time               `O(n)`                          `O(log n)`
  Best-case time                `O(1)`                          `O(1)`
  Auxiliary space (iterative)   `O(1)`                          `O(1)`
  Suitable use                  Small or unsorted collections   Large, sorted arrays

## 7. Programming Questions -- Separate C Files

**Important project rule:** This Markdown file contains theory,
algorithms, explanations, and programming questions only. Complete
executable C programs must be written in separate `.c` files.

### Program 1 -- Linear Search

**Question:** Write a C program to read `n` integer elements into an
array, accept a search key from the user, and use Linear Search to find
and display the position of the key. If the key is absent, display an
appropriate message.

-   **File:** `Linear_Search.c`
-   **Concepts:** One-dimensional arrays, `for` loop, `if` statement,
    `printf()`, `scanf()`, and a found/not-found flag or loop
    termination.

### Program 2 -- Binary Search

**Question:** Write a C program to perform Binary Search on an array of
integers that is already sorted in ascending order. Read the array and
search key from the user, then display the position if the key is found
or an appropriate message if it is absent.

-   **File:** `Binary_Search.c`
-   **Concepts:** Sorted arrays, `while` loop, `low`, `high`, `mid`, and
    conditional statements.
-   **Precondition:** The input array must be sorted.

### Program 3 -- Array Operations

**Question:** Write a menu-driven C program to perform the following
operations on an integer array: (1) traverse/display all elements, (2)
insert an element at a specified one-based position, and (3) delete an
element from a specified one-based position. Validate positions and
ensure that insertion does not exceed the array's capacity.

-   **File:** `Array_Operations.c`
-   **Concepts:** Arrays, loops, `switch` statement, shifting elements,
    position validation, and updating the logical size.

## 8. Important Short-Answer Questions

1.  **Differentiate between data and information.**\
    Data is a collection of raw facts or values. Information is data
    that has been processed or organized to provide meaning and context.

2.  **Define a data structure.**\
    A data structure is a method of organizing and storing data in
    memory so that it can be accessed and modified efficiently.

3.  **What are primitive data types? Give C examples.**\
    Primitive data types are basic types provided by C, such as `int`,
    `char`, `float`, and `double`.

4.  **Differentiate between linear and non-linear data structures.**\
    Linear structures arrange elements sequentially, whereas non-linear
    structures arrange elements hierarchically or as networks.

5.  **State the characteristics of an algorithm.**\
    An algorithm has well-defined input and output, unambiguous steps,
    finiteness, and effective instructions. Its logic is independent of
    a particular programming language.

6.  **Define time complexity.**\
    Time complexity describes how the number of operations performed by
    an algorithm grows with input size.

7.  **Define space complexity.**\
    Space complexity describes how the memory required by an algorithm
    grows with input size.

8.  **What is Big O notation?**\
    Big O notation expresses an asymptotic upper bound on a function's
    growth rate.

9.  **What is the time-space trade-off?**\
    It is the principle of using more memory to reduce computation time,
    or reducing memory use at the cost of more computation.

10. **State the precondition for binary search.**\
    The elements must be sorted in the order in which binary search is
    performed.

11. **What is array traversal?**\
    Array traversal is the process of visiting each valid array element,
    usually once, to read or process it.

12. **What is the difference between an array index and position?**\
    In C, an array index starts at `0`; a human-readable position is
    commonly counted from `1`. Thus, position = index + 1.

## 9. Important 4-Mark Questions with Answers

### Question 1: Explain the classification of data structures with a neat diagram.

**Answer:**

Data structures are commonly classified into primitive and non-primitive
categories. Non-primitive structures are further discussed as linear and
non-linear structures.

``` text
                         Data Structures
                         /              \
                 Primitive          Non-Primitive
                                      /       \
                                   Linear   Non-Linear
```

1.  **Primitive:** Basic language-provided types such as `int`, `char`,
    `float`, and `double`.
2.  **Linear:** Elements are arranged sequentially. Examples include
    arrays, linked lists, stacks, and queues.
3.  **Non-linear:** Elements form hierarchical or network relationships.
    Examples include trees and graphs.

### Question 2: Explain Big O, Omega, and Theta notations.

**Answer:**

Asymptotic notations describe the growth rate of an algorithm as input
size becomes large.

1.  **Big O -- Upper bound:** `T(n) = O(g(n))` when `T(n)` does not grow
    faster than a constant multiple of `g(n)` for sufficiently large
    `n`.
2.  **Omega -- Lower bound:** `T(n) = Ω(g(n))` when `T(n)` grows at
    least as fast as a positive constant multiple of `g(n)` for
    sufficiently large `n`.
3.  **Theta -- Tight bound:** `T(n) = Θ(g(n))` when both upper and lower
    bounds are of the same order.

  Notation    Bound
  ----------- -------
  `O(g(n))`   Upper
  `Ω(g(n))`   Lower
  `Θ(g(n))`   Tight

### Question 3: Trace Binary Search for key `18` in `[10, 6, 16, 18, 80, 75]`.

**Answer:**

Binary Search requires sorted data. First sort the array:

`[6, 10, 16, 18, 75, 80]`

  Iteration     Low   High   Mid   Middle value Action
  ----------- ----- ------ ----- -------------- -------------------
  1               0      5     2             16 Search right half
  2               3      5     4             75 Search left half
  3               3      3     3             18 Key found

Therefore, `18` is found at index `3`, which is position `4`, after
three iterations.

### Question 4: Explain the components of space complexity.

**Answer:**

A common conceptual expression is:

`S(P) = C + Sp(I)`

-   **Fixed part (`C`):** Memory that does not depend on the particular
    input size, such as fixed-size variables and program instructions.
-   **Variable part (`Sp(I)`):** Memory that depends on the input, such
    as input-dependent arrays, dynamic allocations, and recursive call
    frames.

For algorithm comparisons, auxiliary space should be distinguished from
memory used to store the input itself.

## 10. Important Long-Answer Questions

1.  Define a data structure. Explain its need, classification, and basic
    operations with examples.
2.  Explain Linear Search and Binary Search with algorithms, worked
    examples, advantages, disadvantages, and complexity analysis.
3.  Define algorithm analysis. Explain time complexity, space
    complexity, best case, average case, worst case, and asymptotic
    notations.
4.  Explain array traversal, insertion, and deletion with suitable
    algorithms and their time complexities.
5.  Explain the time-space trade-off with suitable examples.

## 11. Chapter Summary and Key Points

-   **Data** means raw facts; **information** means processed data with
    meaning.
-   A **data structure** organizes data for efficient access and
    modification.
-   Common introductory categories are **primitive** and
    **non-primitive**; non-primitive structures include linear and
    non-linear forms.
-   Basic operations include traversal, searching, insertion, deletion,
    sorting, and merging.
-   An algorithm must have clear steps, defined input/output, and must
    terminate.
-   **Time complexity** describes operation growth; **space complexity**
    describes memory growth.
-   `O` is an upper bound, `Ω` is a lower bound, and `Θ` is a tight
    bound.
-   Linear search works on sorted or unsorted data and has `O(n)`
    worst-case time.
-   Binary search requires sorted data and has `O(log n)` worst-case
    time.
-   Arrays store same-type elements contiguously and use zero-based
    indexing in C.
-   Array insertion and deletion may require shifting elements.
-   Complete C implementations are maintained separately in
    `Linear_Search.c`, `Binary_Search.c`, and `Array_Operations.c`.

------------------------------------------------------------------------

## 12. Separate C Program Checklist

Create these files in the chapter's `C-Programs` folder:

``` text
01-Introduction-to-Data-Structure/
├── Notes/
│   └── Chapter_01_Introduction_to_Data_Structure.md
└── C-Programs/
    ├── Linear_Search.c
    ├── Binary_Search.c
    └── Array_Operations.c
```

Do not paste complete C programs into this Markdown notes file.

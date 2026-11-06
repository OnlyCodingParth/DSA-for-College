# Chapter 04 – Tree

## 1. Introduction to Tree Data Structure

In computer science, data structures are categorized as either **linear** or **non-linear**:
* **Linear Data Structures**: Elements are arranged sequentially in a single line (e.g., Arrays, Stacks, Queues, Linked Lists). Every element (except the first and last) has a unique predecessor and successor.
* **Non-Linear Data Structures**: Elements are arranged hierarchically or as a network, where an element can connect to multiple elements (e.g., Trees, Graphs).

A **Tree** is a non-linear, hierarchical data structure used to represent data containing a parent-child relationship between elements. Unlike linear structures, trees allow data to be organized in levels, enabling efficient search, insertion, and deletion operations.

### Definition of a Tree
Formally, a **Tree** is defined as a finite set of one or more nodes such that:
1. There is a specially designated node called the **root**.
2. The remaining nodes are partitioned into $n \ge 0$ disjoint sets $T_1, T_2, \dots, T_n$, where each of these sets is itself a tree. These sets $T_1, T_2, \dots, T_n$ are called the **subtrees** of the root.

```
       [ A ]          <-- Root Node
      /     \
    [ B ]   [ C ]     <-- Subtrees / Child Nodes
   /   \       \
 [ D ] [ E ]   [ F ]
```

### Real-World Applications of Tree Structures
* **File System Directories**: Operating system folders and subfolders follow a root directory structure (e.g., `/root/home/user/documents`).
* **Organization Charts**: Corporate management structures showing CEO, Vice Presidents, Directors, and Employees.
* **Family Trees**: Genealogical structures showing ancestors and descendants.
* **Table of Contents**: Books organized into Units, Chapters, Sections, and Subsections.
* **DOM (Document Object Model) in Web Browsers**: HTML document structures represented as a tree of tags (`<html>`, `<body>`, `<div>`, `<p>`).

---

## 2. Detailed Topic-Wise Explanations

### 2.1 Basic Tree Terminologies

To understand tree operations, it is necessary to master the fundamental terminology used to describe nodes, edges, levels, and structural properties.

```
            [ A ]               <-- Level 0 (Root)
           /     \
        [ B ]   [ C ]           <-- Level 1
       /     \       \
    [ D ]   [ E ]   [ F ]       <-- Level 2
   /         /
 [ G ]     [ H ]                <-- Level 3
```

#### 1. NULL Tree (Empty Tree)
A tree that contains no nodes (number of nodes = 0) is called a **NULL Tree** or Empty Tree.

#### 2. Root Node
The **Root** is a unique, topmost node in the tree from which all subtrees stem. It is the entry point of the tree data structure and has **no parent node**.
* *Example from Diagram*: Node **A** is the root node.

#### 3. Node
A **Node** is an individual element or data container within a tree structure. It contains data/information along with branch pointers (links) to other nodes.
* *Example from Diagram*: Nodes present are **A, B, C, D, E, F, G, H**.

#### 4. Parent Node
A node that has one or more outgoing branches pointing to lower-level nodes is called a **Parent Node**.
* *Example from Diagram*: Node **A** is the parent of **B** and **C**; Node **B** is the parent of **D** and **E**.

#### 5. Child Node
A node connected directly below a parent node via an incoming branch is called a **Child Node**.
* *Example from Diagram*: Nodes **B** and **C** are children of **A**; Nodes **D** and **E** are children of **B**.

#### 6. Leaf Node (Terminal Node)
A node that has no subtrees or children connected to it is called a **Leaf Node** or **Terminal Node**.
* *Example from Diagram*: Nodes **G, H, F** (and **C** if it had no right child, but here **F** is C's child, so **F** is a leaf). Specifically, nodes with zero children (**G, H, F**) are leaf nodes.

#### 7. Non-Leaf Node (Internal Node)
All nodes in a tree except the leaf nodes are called **Non-Leaf Nodes** or **Internal Nodes**. They have at least one child node.
* *Example from Diagram*: Nodes **A, B, C, D, E** are internal/non-leaf nodes.

#### 8. Degree of a Node
The total number of subtrees or child nodes attached directly to a node is called the **Degree of that Node**.
* *Example from Diagram*:
  * Degree of Node **A** = 2 (children B, C)
  * Degree of Node **B** = 2 (children D, E)
  * Degree of Node **D** = 1 (child G)
  * Degree of Node **G** = 0 (leaf node)

#### 9. Degree of a Tree
The **Degree of a Tree** is defined as the maximum degree among all the nodes present in that tree.
* *Example from Diagram*: Maximum degree of any node is 2, so the degree of the tree is 2.

#### 10. Level of a Node
The distance of a node from the root node measured in steps/edges.
* The **Root** of the tree is defined at **Level 0**.
* The children of the root are at **Level 1**.
* The level of any node in the tree is one more than the level of its parent node ($\text{Level}(\text{child}) = \text{Level}(\text{parent}) + 1$).

| Level | Nodes Present |
| :---: | :--- |
| **0** | A |
| **1** | B, C |
| **2** | D, E, F |
| **3** | G, H |

#### 11. Depth or Height of a Tree
The **Height** or **Depth** of a tree is defined as the maximum level of any node present in the tree (or the number of edges on the longest path from the root node to a leaf node).
* *Example from Diagram*: The maximum level reached is 3 (nodes G and H), so the height/depth of the tree is **3**.

#### 12. Path
A **Path** is an ordered sequence of consecutive nodes in which each node is adjacent to the next node connected by edges.
* *Example from Diagram*: Sequence **A $\to$ B $\to$ D $\to$ G** represents a valid path from root node A to leaf node G.

#### 13. Ancestor Node
An **Ancestor** of a node is any node that lies along the path from the root node to that specific node (including the root).
* *Example from Diagram*: For Node **D**, its ancestors are **B** and **A**.

#### 14. Descendant Node
A **Descendant** of a node is any node that is reachable along paths originating down from that node.
* *Example from Diagram*: For Node **B**, its descendants are **D, E, G, H**.

#### 15. Siblings
Children of the **same parent node** are called **Siblings**.
* *Example from Diagram*:
  * **B** and **C** are siblings (parent A).
  * **D** and **E** are siblings (parent B).

#### 16. Directed Edge, In-Degree, and Out-Degree
* **Directed Edge**: A directed line/link from a parent node to a child node that indicates structural hierarchy.
* **In-Degree**: The number of edges arriving at a specific node.
  * In-degree of the **Root** node is always **0**.
  * In-degree of every other node in a tree is **1**.
* **Out-Degree**: The number of edges leaving a specific node (equivalent to the degree of the node).

| Node | Out-Degree | In-Degree |
| :---: | :---: | :---: |
| **A (Root)** | 2 | 0 |
| **B** | 2 | 1 |
| **C** | 1 | 1 |
| **D** | 1 | 1 |
| **G, H, F (Leaves)** | 0 | 1 |

---

### 2.2 Types of Trees

Trees are classified based on branching rules, child constraints, and structural balance properties.

```
                  Types of Trees
                        │
         ┌──────────────┴──────────────┐
   General Tree                   Binary Tree
 (0 to n children)             (Max 2 children)
                                       │
                      ┌────────────────┼────────────────┐
               Standard BT      Threaded BT (TBT)     BST / AVL
```

#### 1. General Tree
A **General Tree** is an unordered tree data structure where each node can have an arbitrary number of subtrees ($0$ to $n$ children). There is no constraint on the hierarchy or maximum child count per node.
* *Characteristics*: The root acts as the superset of all other subtrees. Nodes can store varying array pointers to accommodate arbitrary children.

#### 2. Binary Tree
A **Binary Tree** is a specialized non-linear tree data structure in which **every node can have at most two children**, referred to as the **Left Child** and the **Right Child**.

$$\text{Child count per node} \in \{0, 1, 2\}$$

* **Left Child**: The node connected to the left branch of a parent node.
* **Right Child**: The node connected to the right branch of a parent node.

```
       [ A ]          <-- Parent
      /     \
  [ B ]     [ C ]     <-- Left Child (B), Right Child (C)
  /   \
[D]   [E]
```

#### Primary Operations on Binary Trees
1. **Creation**: Initializing an empty binary tree where `root` points to `NULL`.
2. **Traversal**: Visiting each node in the binary tree systematically exactly once.
3. **Insertion**: Adding a new node into an existing binary tree at an appropriate position.
4. **Deletion**: Removing a specific node from a non-empty binary tree while preserving tree properties.
5. **Merge**: Combining two separate binary trees into a single unified binary tree.
6. **Copy**: Creating a duplicate copy of an existing binary tree.
7. **Compare**: Comparing two binary trees to verify if they are structurally identical and store identical data.

---

### 2.3 Binary Tree Memory Representations

A binary tree can be represented in memory using two primary approaches: **Linked Node Representation** (dynamic pointers) and **Array Representation** (sequential contiguous storage).

#### 1. Linked Node Representation (Pointer-Based)
This is the most common and flexible method for representing binary trees. Each node is dynamically allocated in memory as a C `struct` containing three fields:
* `data`: Stores the actual value/information.
* `left`: A pointer pointing to the left child node (or `NULL` if none exists).
* `right`: A pointer pointing to the right child node (or `NULL` if none exists).

```
   ┌──────────┬──────────┬──────────┐
   │   left   │   data   │  right   │
   └──────────┴──────────┴──────────┘
```

```
                     ┌──────┬───┬──────┐
                     │ NULL │ A │ NULL │  <-- Root Node Pointer
                     └──┬───┴───┴──┬───┘
                        │          │
         ┌──────────────┘          └──────────────┐
         ▼                                        ▼
┌──────┬───┬──────┐                      ┌──────┬───┬──────┐
│ NULL │ B │ NULL │                      │ NULL │ C │ NULL │
└──────┴───┴──────┘                      └──────┴───┴──────┘
  (Left Child)                             (Right Child)
```

#### 2. Sequential Array Representation
In sequential representation, binary tree nodes are stored in a 1D array. This method is particularly efficient for **Complete Binary Trees** (where all levels are completely filled except possibly the last level, which is filled from left to right).

##### Indexing Formulae (for zero-based indexing):
* The **Root Node** is stored at index **0**.
* For any node stored at index $i$:
  * **Left Child Index**: $2i + 1$
  * **Right Child Index**: $2i + 2$
  * **Parent Index**: $\lfloor (i - 1) / 2 \rfloor$

##### Step-by-Step Example:
Consider the following Complete Binary Tree:
```
           [ 10 ]            (Index 0)
          /      \
      [ 9 ]      [ 5 ]       (Indices 1, 2)
     /     \    /     \
   [8]     [4] [2]    [3]    (Indices 3, 4, 5, 6)
```

**Array Storage Mapping**:

| Array Index ($i$) | `0` | `1` | `2` | `3` | `4` | `5` | `6` |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Stored Value** | **10** | **9** | **5** | **8** | **4** | **2** | **3** |

* *Validation*:
  * For Node at index $i = 1$ (value `9`):
    * Left Child $= 2(1) + 1 = 3$ (value `8` $\checkmark$)
    * Right Child $= 2(1) + 2 = 4$ (value `4` $\checkmark$)

---

### 2.4 Threaded Binary Tree (TBT)

#### Why Threaded Binary Trees Are Needed
In a standard linked binary tree with $n$ nodes, there are $2n$ total pointers (`left` and `right` for each node). Exactly $n + 1$ of these pointers contain `NULL` values. This represents significant wasted memory space.

Furthermore, traversing a standard binary tree requires an explicit stack or recursion call stack to back-track through parent nodes.

A **Threaded Binary Tree (TBT)** is a specialized binary tree structure where **`NULL` pointers are replaced by links called "threads"** that point to the node's **In-order Predecessor** or **In-order Successor**.

```
Standard Binary Tree NULL Pointers ──► Replaced with Direct Threads ──► Traversal without Stack/Recursion
```

#### Concept of In-order Predecessor and Successor
Consider a binary tree with the In-order Traversal sequence:
$$\text{In-order Sequence}: \quad D \to B \to E \to A \to C \to F$$

For Node **E**:
* **In-order Predecessor**: The node that comes immediately before **E** in the in-order traversal sequence $\implies$ Node **B**.
* **In-order Successor**: The node that comes immediately after **E** in the in-order traversal sequence $\implies$ Node **A**.

```
            [ A ]
           /     \
       [ B ]     [ C ]
      /     \       \
    [ D ]   [ E ]   [ F ]

In-order Traversal: D -> B -> E -> A -> C -> F

For Node E:
- Left NULL Pointer replaced by Thread to Predecessor (B)
- Right NULL Pointer replaced by Thread to Successor (A)
```

#### Classifications of Threaded Binary Trees

##### 1. Left Threaded Binary Tree
Only `NULL` left pointers are replaced by threads pointing to the node's **In-order Predecessor**. Right pointers behave normally.
* *Rule*:
  * If a node has a left child $\implies$ normal child pointer.
  * If a node has no left child $\implies$ left thread points to in-order predecessor.

```
In-order Sequence: D -> B -> A -> C

Node D has no left child & is first in sequence ──► left pointer = NULL
Node B has left child D                        ──► normal left pointer to D
Node A has left child B                        ──► normal left pointer to B
Node C has no left child                       ──► left thread points to A (Predecessor)
```

##### 2. Right Threaded Binary Tree
Only `NULL` right pointers are replaced by threads pointing to the node's **In-order Successor**. Left pointers behave normally.
* *Rule*:
  * If a node has a right child $\implies$ normal child pointer.
  * If a node has no right child $\implies$ right thread points to in-order successor.

```
In-order Sequence: B -> D -> A -> C

Node B has right child D                        ──► normal right pointer to D
Node D has no right child                      ──► right thread points to A (Successor)
Node A has right child C                        ──► normal right pointer to C
Node C has no right child & is last in sequence ──► right pointer = NULL
```

##### 3. Double Threaded Binary Tree
Both `NULL` left and `NULL` right pointers are replaced by threads:
* Left `NULL` pointer $\to$ Thread pointing to **In-order Predecessor**.
* Right `NULL` pointer $\to$ Thread pointing to **In-order Successor**.

```
In-order Sequence: D -> B -> E -> A -> C

Node D: left thread = NULL (first node), right thread = B (successor)
Node E: left thread = B (predecessor),   right thread = A (successor)
Node C: left thread = A (predecessor),   right thread = NULL (last node)
```

---

### 2.5 Binary Tree Traversals

**Tree Traversal** is the process of visiting or accessing every node in a binary tree exactly once in a systematic, defined order.

Unlike linear data structures (like arrays or linked lists) which have a single obvious linear traversal path, binary trees can be traversed in multiple ways depending on when the root node is visited relative to its left and right subtrees.

```
                       Root (V)
                      /        \
             Left (L)            Right (R)

  In-Order (L-V-R)    Pre-Order (V-L-R)    Post-Order (L-R-V)
```

#### 1. In-Order Traversal (L $\to$ V $\to$ R)
In an **In-Order Traversal**, the left subtree is traversed first, then the root (visited node) is processed, and finally the right subtree is traversed.

##### Algorithm / Steps:
1. Traverse the left subtree recursively (`Inorder(left_subtree)`).
2. Visit the root node (`visit(root)`).
3. Traverse the right subtree recursively (`Inorder(right_subtree)`).

##### Example:
```
           [ A ]
          /     \
      [ B ]     [ C ]
     /     \
   [ D ]   [ E ]
```
* **Step-by-step trace**:
  1. Start at root **A**, go left to **B**, go left to **D**.
  2. Node **D** has no left child $\implies$ Visit **D**.
  3. Return to **B** $\implies$ Visit **B**.
  4. Move to right child **E** $\implies$ Visit **E**.
  5. Return to root **A** $\implies$ Visit **A**.
  6. Move to right child **C** $\implies$ Visit **C**.
* **In-Order Traversal Result**: $\mathbf{D \to B \to E \to A \to C}$

#### 2. Pre-Order Traversal (V $\to$ L $\to$ R)
In a **Pre-Order Traversal**, the root (visited node) is processed first, followed by the left subtree, and then the right subtree.

##### Algorithm / Steps:
1. Visit the root node (`visit(root)`).
2. Traverse the left subtree recursively (`Preorder(left_subtree)`).
3. Traverse the right subtree recursively (`Preorder(right_subtree)`).

##### Example (using same tree):
* **Step-by-step trace**:
  1. Visit root **A**.
  2. Go to left child **B** $\implies$ Visit **B**.
  3. Go to left child **D** $\implies$ Visit **D**.
  4. Go to right child of B $\to$ **E** $\implies$ Visit **E**.
  5. Go to right child of A $\to$ **C** $\implies$ Visit **C**.
* **Pre-Order Traversal Result**: $\mathbf{A \to B \to D \to E \to C}$

#### 3. Post-Order Traversal (L $\to$ R $\to$ V)
In a **Post-Order Traversal**, the left subtree is traversed first, followed by the right subtree, and finally the root (visited node) is processed.

##### Algorithm / Steps:
1. Traverse the left subtree recursively (`Postorder(left_subtree)`).
2. Traverse the right subtree recursively (`Postorder(right_subtree)`).
3. Visit the root node (`visit(root)`).

##### Example (using same tree):
* **Step-by-step trace**:
  1. Traverse left subtree of **A** $\to$ left subtree of **B** $\to$ Visit **D**.
  2. Visit right child of **B** $\to$ Visit **E**.
  3. Visit parent **B**.
  4. Traverse right subtree of **A** $\to$ Visit **C**.
  5. Finally visit root **A**.
* **Post-Order Traversal Result**: $\mathbf{D \to E \to B \to C \to A}$

---

### 2.6 Binary Search Tree (BST)

#### Definition and Ordering Invariant
A **Binary Search Tree (BST)** is a binary tree in which nodes are arranged according to their key values following a strict ordering rule:
1. The **Left Subtree** of a node contains only nodes with key values **less than** the parent node's key value.
2. The **Right Subtree** of a node contains only nodes with key values **greater than or equal to** the parent node's key value.
3. Every left and right subtree must itself be a Binary Search Tree.

$$\forall x \in \text{LeftSubtree}(Node), \quad \text{key}(x) < \text{key}(Node)$$
$$\forall y \in \text{RightSubtree}(Node), \quad \text{key}(y) \ge \text{key}(Node)$$

```
           [ 50 ]              <-- Root
          /      \
      [ 30 ]    [ 70 ]         <-- 30 < 50 < 70
     /     \    /     \
  [20]    [40] [60]   [80]     <-- Subtrees satisfy BST invariant
```

#### Fundamental Properties of a BST
* **Sorted In-Order Property**: An **In-Order Traversal** of a Binary Search Tree always produces a strictly **ascending sorted sequence** of key values.
  * *Example from diagram*: In-order sequence $= 20 \to 30 \to 40 \to 50 \to 60 \to 70 \to 80$.
* **Fast Lookup**: Searching in a balanced BST takes $O(\log_2 n)$ time compared to $O(n)$ in linear lists.

#### Operations on Binary Search Trees

##### 1. Search Operation
To search for a key $X$ in a BST:
1. Start at the root node.
2. If `root == NULL`, the element is not present (Search Unsuccessful).
3. If $X == \text{root}\to\text{data}$, the search is successful.
4. If $X < \text{root}\to\text{data}$, recurse into the **left subtree**.
5. If $X > \text{root}\to\text{data}$, recurse into the **right subtree**.

##### 2. Insertion Operation
To insert a new key $X$ into a BST:
1. Compare $X$ with the current node starting at the root.
2. If $X < \text{current}\to\text{data}$, move to the left child.
3. If $X > \text{current}\to\text{data}$, move to the right child.
4. Repeat until reaching a `NULL` pointer position.
5. Allocate a new node and attach it as the left or right child at that `NULL` position.

##### 3. Deletion Operation
Deleting a node from a BST requires maintaining the BST ordering invariant. There are **three cases**:

* **Case 1: Deleting a Leaf Node (Node with 0 children)**
  * Simply set the parent's link to `NULL` and free the memory of the leaf node.
  * *Example*: Deleting node `20` from the tree above.

* **Case 2: Deleting a Node with One Child**
  * Bypass the node by connecting its parent directly to its single child node, then free the node.
  * *Example*: Deleting a node `30` that has only child `40`.

* **Case 3: Deleting a Node with Two Children**
  * Replace the node's key with either:
    1. Its **In-Order Successor** (the smallest value in its right subtree).
    2. Its **In-Order Predecessor** (the largest value in its left subtree).
  * Then recursively delete the In-order Successor/Predecessor node from the subtree (which falls under Case 1 or Case 2).

```
Case 3 Example: Delete Node 50 (Root)
1. Find In-Order Successor of 50 -> Smallest element in Right Subtree = 60
2. Copy value 60 into Root position
3. Delete original node 60 from Right Subtree (Leaf node deletion)
```

#### Advantages and Disadvantages of BST

##### Advantages:
1. **Fast Searching**: Average search time complexity is $O(\log_2 n)$.
2. **Dynamic Data Allocation**: Easily grows and shrinks dynamically without needing continuous array reallocations.
3. **Sorted Output**: In-order traversal automatically produces sorted keys without additional sorting algorithms.

##### Disadvantages:
1. **Risk of Degeneracy / Skewing**: If keys are inserted in strictly sorted order (e.g., $10, 20, 30, 40, 50$), the tree degenerates into a **Skewed Binary Tree** (a linear linked list), degrading search complexity to $O(n)$.
2. **Pointer Overhead**: Memory overhead due to two pointer variables (`left`, `right`) per node.
3. **Complex Deletion Logic**: Case 3 deletion requires extra pointer re-linking steps.

---

### 2.7 Applications of Binary Trees

Binary trees serve as fundamental building blocks across computer science domains:

```
                      Applications of Binary Trees
                                   │
        ┌──────────────────┬───────┴──────────┬──────────────────┐
  Expression Trees     BST Systems          Heaps           Decision Trees
 (Compiler Design)    (DB Indexing)   (Priority Queues)        (AI / ML)
```

#### 1. Expression Trees
An **Expression Tree** is a binary tree used to represent arithmetic expressions.
* **Internal Nodes**: Represent operators ($+, -, \times, \div$).
* **Leaf Nodes**: Represent operands (variables or numbers).

##### Example: Expression $(a + b) \times (c - d)$
```
           [ * ]               <-- Root Operator
          /     \
      [ + ]     [ - ]          <-- Sub-operators
     /     \   /     \
   [a]     [b] [c]   [d]       <-- Leaf Operands
```
* **Traversal Mappings**:
  * **In-order Traversal** yields Infix Notation: $(a + b) \times (c - d)$
  * **Pre-order Traversal** yields Prefix Notation: $\times + a \ b - c \ d$
  * **Post-order Traversal** yields Postfix Notation: $a \ b + c \ d - \times$
* *Application Domains*: Compiler design, expression parsing and evaluation engines.

#### 2. Binary Search Trees (BST)
* *Applications*: Database indexing structures, dictionary implementation, fast lookup tables, and searching large dynamic datasets.

#### 3. Heaps (Priority Queues)
A **Heap** is a specialized complete binary tree structure used to implement **Priority Queues**.
* **Max Heap**: The key at the root node is greater than or equal to keys of its children ($\text{Root} \ge \text{Children}$).
* **Min Heap**: The key at the root node is smaller than or equal to keys of its children ($\text{Root} \le \text{Children}$).

```
    Max Heap Example           Min Heap Example
         [ 50 ]                     [ 10 ]
        /      \                   /      \
     [ 30 ]   [ 40 ]            [ 20 ]   [ 30 ]
```
* *Applications*: Operating System CPU process scheduling, Heap Sort algorithm ($O(n \log n)$ complexity).

#### 4. Decision Trees
A **Decision Tree** is a binary tree structure used in Artificial Intelligence (AI) and Machine Learning (ML) for classification and decision-making processes.
* **Internal Nodes**: Conditions or feature test questions (e.g., "Is Age > 18?").
* **Leaf Nodes**: Decision outcomes or classification class labels (e.g., "Eligible" / "Not Eligible").

```
             [ Is Age > 18? ]
               /          \
            (Yes)         (No)
             /              \
     [ Eligible ]     [ Not Eligible ]
```

---

### 2.8 AVL Tree (Self-Balancing Binary Search Tree)

#### Definition and Origin
An **AVL Tree** is a **self-balancing Binary Search Tree (BST)** introduced by Russian mathematicians **G.M. Adelson-Velsky and E.M. Landis in 1962** (hence the name **AVL**).

In a standard BST, if elements are inserted in ascending or descending order, the tree becomes skewed with height $H = O(n)$, causing operations to degrade to $O(n)$. An AVL tree prevents this by ensuring the tree remains height-balanced after every insertion and deletion, maintaining $H = O(\log_2 n)$.

#### Height Property and Balance Factor Formula
In an AVL tree, the difference between the height of the left subtree and the right subtree of any node cannot be more than **1**.

$$\text{Balance Factor (BF)} = \text{Height}(\text{Left Subtree}) - \text{Height}(\text{Right Subtree})$$

$$\text{Allowed Balance Factor values } \in \{-1, 0, +1\}$$

* **$\text{BF} = 0$**: The node is perfectly balanced.
* **$\text{BF} = +1$**: The left subtree is one level taller than the right subtree (left-heavy, but balanced).
* **$\text{BF} = -1$**: The right subtree is one level taller than the left subtree (right-heavy, but balanced).
* **$\text{BF} = +2 \text{ or } -2$**: The node is **unbalanced** and strictly requires a **rotation** to restore AVL balance.

#### Calculation Rules for Node Height:
1. Height of a **Leaf Node** $= 0$.
2. Height of an **Empty (`NULL`) Child** $= -1$.
3. For any non-leaf node:

$$\text{Height}(\text{Node}) = 1 + \max(\text{Height}(\text{Left Child}), \text{Height}(\text{Right Child}))$$

#### Detailed Worked Example: Calculating Balance Factor
Consider the tree:
```
           [ 40 ]
          /      \
      [ 20 ]    [ 60 ]
     /     \
  [10]    [30]
```

* **Step 1: Calculate Heights from Leaves to Root**
  * Leaf nodes `10`, `30`, `60`: Have no children $\implies \text{Height} = 0$.
  * Node `20`: Left child `10` ($H=0$), Right child `30` ($H=0$).
    $$\text{Height}(20) = 1 + \max(0, 0) = 1$$
  * Node `40` (Root): Left child `20` ($H=1$), Right child `60` ($H=0$).
    $$\text{Height}(40) = 1 + \max(1, 0) = 2$$

* **Step 2: Calculate Balance Factor ($\text{BF} = \text{Left Height} - \text{Right Height}$)**
  * Node `10`: $\text{BF} = (-1) - (-1) = 0$ (Balanced)
  * Node `30`: $\text{BF} = (-1) - (-1) = 0$ (Balanced)
  * Node `60`: $\text{BF} = (-1) - (-1) = 0$ (Balanced)
  * Node `20`: $\text{Left Height} = 0$, $\text{Right Height} = 0 \implies \text{BF} = 0 - 0 = 0$ (Balanced)
  * Node `40`: $\text{Left Height} = 1$ (node 20), $\text{Right Height} = 0$ (node 60) $\implies \text{BF} = 1 - 0 = +1$ (Balanced)

Since all nodes have $\text{BF} \in \{-1, 0, +1\}$, the tree is a valid AVL tree.

---

#### AVL Tree Rotations

When an insertion or deletion causes a node's balance factor to become $+2$ or $-2$, a **Rotation** is performed to restructure the tree without violating the BST ordering property.

```
                         AVL Rotations
                               │
         ┌─────────────────────┴─────────────────────┐
  Single Rotations                            Double Rotations
 ┌───────┴───────┐                           ┌───────┴───────┐
LL Rotation   RR Rotation                 LR Rotation     RL Rotation
(Right Rot.)  (Left Rot.)                 (Left + Right)  (Right + Left)
```

##### 1. Single Rotations

* **LL Rotation (Left-Left Rotation / Right Rotation)**:
  * **Occurs when**: A new node is inserted into the **left subtree of the left child** of an unbalanced node, making $\text{BF} = +2$ (left-heavy).
  * **Fix**: Perform a **single Right Rotation** on the unbalanced node.
  * **Worked Example**: Insert keys `30`, `20`, `10` into an empty AVL tree.

```
Insert 30 -> Insert 20 -> Insert 10:

    [30] (+2)                         [20] (0)
    /          Perform RIGHT         /    \
  [20] (+1)   ──────────────►     [10]    [30]
  /             Rotation on 30     (0)     (0)
[10] (0)
(Unbalanced)                       (Balanced!)
```

* **RR Rotation (Right-Right Rotation / Left Rotation)**:
  * **Occurs when**: A new node is inserted into the **right subtree of the right child** of an unbalanced node, making $\text{BF} = -2$ (right-heavy).
  * **Fix**: Perform a **single Left Rotation** on the unbalanced node.
  * **Worked Example**: Insert keys `10`, `20`, `30` into an empty AVL tree.

```
Insert 10 -> Insert 20 -> Insert 30:

  [10] (-2)                           [20] (0)
     \         Perform LEFT          /    \
     [20] (-1) ─────────────►      [10]    [30]
        \       Rotation on 10     (0)     (0)
        [30] (0)
  (Unbalanced)                         (Balanced!)
```

##### 2. Double Rotations

* **LR Rotation (Left-Right Rotation / Left Rotation followed by Right Rotation)**:
  * **Occurs when**: A new node is inserted into the **right subtree of the left child** of an unbalanced node ($\text{BF} = +2$).
  * **Fix**:
    1. Perform a **Left Rotation** on the left child node.
    2. Perform a **Right Rotation** on the unbalanced parent node.
  * **Worked Example**: Insert keys `30`, `10`, `20` into an empty AVL tree.

```
Insert 30, 10, 20:

    [30] (+2)                       [30] (+2)                      [20] (0)
    /             Step 1: Left      /             Step 2: Right   /    \
  [10] (-1)     ──────────────►   [20] (+1)     ──────────────► [10]   [30]
     \          Rotation on 10    /               Rotation on 30  (0)    (0)
     [20] (0)                   [10] (0)
  (Unbalanced)                                                     (Balanced!)
```

* **RL Rotation (Right-Left Rotation / Right Rotation followed by Left Rotation)**:
  * **Occurs when**: A new node is inserted into the **left subtree of the right child** of an unbalanced node ($\text{BF} = -2$).
  * **Fix**:
    1. Perform a **Right Rotation** on the right child node.
    2. Perform a **Left Rotation** on the unbalanced parent node.
  * **Worked Example**: Insert keys `10`, `30`, `20` into an empty AVL tree.

```
Insert 10, 30, 20:

  [10] (-2)                       [10] (-2)                        [20] (0)
     \            Step 1: Right      \            Step 2: Left    /    \
     [30] (+1)  ──────────────►      [20] (-1)  ──────────────► [10]   [30]
     /          Rotation on 30          \         Rotation on 10  (0)    (0)
   [20] (0)                         [30] (0)
  (Unbalanced)                                                     (Balanced!)
```

---

#### Insertion and Deletion Algorithms in AVL Trees

##### AVL Node Insertion Steps:
1. Insert the new node using standard BST insertion rules.
2. Backtrack toward the root, updating the height of every ancestor node.
3. Calculate the Balance Factor ($\text{BF}$) of each ancestor node.
4. If $\text{BF} \in \{+2, -2\}$, identify the insertion case (LL, RR, LR, or RL) and apply the appropriate rotation.

##### AVL Node Deletion Steps:
1. Delete the specified node using standard BST deletion rules (Leaf node, 1-child node, or 2-child node with In-order Successor).
2. Backtrack toward the root from the point of deletion, updating node heights.
3. Calculate the Balance Factor ($\text{BF}$) of each ancestor node.
4. If $\text{BF} \in \{+2, -2\}$, perform the required rotation (LL, RR, LR, or RL) to restore balance.
   * *Note*: While insertion requires at most 1 rotation (single or double), deletion may require multiple rotations along the path to the root.

---

## 3. Important Definitions and Terminology Glossary

| Term | Detailed Definition |
| :--- | :--- |
| **Tree** | A non-linear hierarchical data structure comprising a finite set of nodes organized into a root and disjoint subtrees. |
| **Root** | The topmost unique node of a tree structure that has no parent. |
| **Leaf Node** | A terminal node in a tree with zero child nodes ($\text{Degree} = 0$). |
| **Internal Node** | A non-terminal node that has one or more child nodes. |
| **Degree of Node** | The total number of subtrees or direct child nodes connected to a specific node. |
| **Degree of Tree** | The maximum degree among all nodes present in the tree. |
| **Level** | The distance of a node from the root node (Root = Level 0). |
| **Height / Depth** | The maximum level of any node in the tree (or longest path length from root to leaf). |
| **Binary Tree** | A tree structure where each node can have at most two children (left child and right child). |
| **Complete Binary Tree** | A binary tree where all levels are completely filled except possibly the last level, which is filled from left to right. |
| **Threaded Binary Tree** | A binary tree variant where `NULL` pointers are replaced with threads pointing to in-order predecessors/successors. |
| **Binary Search Tree** | A binary tree enforcing $\text{Left Subtree} < \text{Root} \le \text{Right Subtree}$ ordering invariant. |
| **Expression Tree** | A binary tree representing arithmetic expressions where internal nodes are operators and leaves are operands. |
| **Heap** | A complete binary tree satisfying Max-Heap ($\text{Parent} \ge \text{Child}$) or Min-Heap ($\text{Parent} \le \text{Child}$) structural constraints. |
| **AVL Tree** | A self-balancing Binary Search Tree where the Balance Factor of every node satisfies $-1 \le \text{BF} \le +1$. |
| **Balance Factor** | The height difference between a node's left subtree and right subtree ($\text{BF} = H_{\text{left}} - H_{\text{right}}$). |

---

## 4. Algorithms and Step-by-Step Explanations

### 4.1 Recursive Binary Tree Traversals

```
Algorithm: Inorder(node)
Input: Pointer to current tree node
1. If node != NULL then
2.     Inorder(node->left)
3.     Print(node->data)
4.     Inorder(node->right)
5. End If

Algorithm: Preorder(node)
Input: Pointer to current tree node
1. If node != NULL then
2.     Print(node->data)
3.     Preorder(node->left)
4.     Preorder(node->right)
5. End If

Algorithm: Postorder(node)
Input: Pointer to current tree node
1. If node != NULL then
2.     Postorder(node->left)
3.     Postorder(node->right)
4.     Print(node->data)
5. End If
```

### 4.2 Binary Search Tree Operations

```
Algorithm: BST_Search(root, key)
Input: Pointer to root node, target key to search
Output: Pointer to found node or NULL
1. If root == NULL or root->data == key then
2.     Return root
3. End If
4. If key < root->data then
5.     Return BST_Search(root->left, key)
6. Else
7.     Return BST_Search(root->right, key)
8. End If

Algorithm: BST_Insert(root, val)
Input: Pointer to root node, val to insert
Output: Pointer to updated tree root
1. If root == NULL then
2.     Create new node temp
3.     temp->data = val, temp->left = temp->right = NULL
4.     Return temp
5. End If
6. If val < root->data then
7.     root->left = BST_Insert(root->left, val)
8. Else If val > root->data then
9.     root->right = BST_Insert(root->right, val)
10. End If
11. Return root
```

---

## 5. Complexity Analysis

| Data Structure / Operation | Search (Average) | Search (Worst) | Insertion (Average) | Insertion (Worst) | Deletion (Average) | Deletion (Worst) | Space Complexity |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Standard Binary Tree** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Binary Search Tree (BST)** | $O(\log_2 n)$ | $O(n)$ | $O(\log_2 n)$ | $O(n)$ | $O(\log_2 n)$ | $O(n)$ | $O(n)$ |
| **AVL Tree (Balanced)** | $O(\log_2 n)$ | $O(\log_2 n)$ | $O(\log_2 n)$ | $O(\log_2 n)$ | $O(\log_2 n)$ | $O(\log_2 n)$ | $O(n)$ |
| **Threaded Binary Tree** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |

---

## 6. Comprehensive Comparison Tables

### 6.1 General Tree vs Binary Tree
| Feature | General Tree | Binary Tree |
| :--- | :--- | :--- |
| **Child Count Limit** | No limit ($0$ to $n$ children allowed per node). | Maximum of $2$ children per node (left and right). |
| **Subtree Order** | Subtrees are unordered by default. | Subtrees are strictly ordered (Left child $\ne$ Right child). |
| **Representation Complexity**| Complex due to variable child pointer arrays. | Simple fixed structure (`left`, `data`, `right`). |
| **NULL Pointers** | Fewer empty pointers due to dynamic arrays. | $n + 1$ `NULL` pointers in a tree of $n$ nodes. |

### 6.2 Array Representation vs Linked Pointer Representation
| Parameter | Array Sequential Representation | Linked Pointer Representation |
| :--- | :--- | :--- |
| **Memory Allocation** | Static contiguous memory allocation. | Dynamic non-contiguous pointer allocation. |
| **Node Indexing** | Root at $0$; Left at $2i+1$; Right at $2i+2$. | Explicit pointer addresses (`left`, `right`). |
| **Space Efficiency** | High for Complete Trees; Extremely wasteful for Skewed Trees. | Optimal for arbitrary trees; pointer overhead per node. |
| **Flexibility** | Fixed size; insertion requires shifting or large array allocation. | Dynamic size; nodes allocated/freed easily via `malloc`/`free`. |

### 6.3 Standard Binary Search Tree (BST) vs AVL Tree
| Property | Binary Search Tree (BST) | AVL Tree |
| :--- | :--- | :--- |
| **Height Balance Constraint**| None. Tree can become skewed. | Strict balance factor constraint: $\text{BF} \in \{-1, 0, +1\}$. |
| **Worst-Case Search Time** | $O(n)$ (when skewed). | $O(\log_2 n)$ (guaranteed height balance). |
| **Rotations Required** | No rotations during insert/delete. | Requires single/double rotations after insert/delete. |
| **Height Bound** | $0 \le H \le n-1$. | $H \approx 1.44 \log_2 n$. |

---

## 7. Programming Questions

> **Note**: Complete executable C code files are maintained separately in individual `.c` files in accordance with examination guidelines. The programming questions and their corresponding filenames are outlined below.

### Question 1: Binary Search Tree Implementation
**Programming Question**: Write a menu-driven C program to create a Binary Search Tree (BST) and implement Search, Insertion, and Deletion operations for all three deletion cases (leaf node, node with 1 child, and node with 2 children using in-order successor).
* **Target C Source File**: `BST_Operations.c`

### Question 2: Binary Tree Recursive Traversals
**Programming Question**: Write a C program to construct a binary tree using dynamic linked representation and implement In-Order, Pre-Order, and Post-Order recursive tree traversals.
* **Target C Source File**: `Binary_Tree_Traversals.c`

### Question 3: Threaded Binary Tree Construction
**Programming Question**: Write a C program to construct a Right Threaded Binary Tree and demonstrate tree traversal without using recursion or an explicit system stack.
* **Target C Source File**: `Threaded_Binary_Tree.c`

### Question 4: AVL Tree Rotations and Height Calculation
**Programming Question**: Write a C program to implement an AVL Tree with balance factor calculations and execute Single (LL, RR) and Double (LR, RL) rotations upon node insertion.
* **Target C Source File**: `AVL_Tree_Rotations.c`

### Question 5: Expression Tree Construction
**Programming Question**: Write a C program to build an Expression Tree from a postfix arithmetic expression and evaluate the expression using post-order tree traversal.
* **Target C Source File**: `Expression_Tree.c`

---

## 8. Important Short-Answer Questions (2 Marks)

### Q1. Define a Tree data structure.
**Answer**: A tree is a non-linear hierarchical data structure consisting of a finite set of one or more nodes such that there is a unique designated node called the **root**, and the remaining nodes are partitioned into disjoint subtrees.

### Q2. What is a Leaf Node?
**Answer**: A leaf node (or terminal node) is a node in a tree structure that has zero children ($\text{Degree} = 0$).

### Q3. State the condition for a binary tree node to be a leaf node in C representation.
**Answer**: In C linked representation, a node `p` is a leaf node if both its left and right pointers are `NULL`:
```c
if (p->left == NULL && p->right == NULL) {
    /* Node p is a leaf node */
}
```

### Q4. Differentiate between In-degree and Out-degree of a tree node.
**Answer**: **In-degree** is the number of edges arriving at a node (Root has In-degree 0; all other nodes have In-degree 1). **Out-degree** is the number of edges leaving a node (equal to the degree of the node).

### Q5. What is the maximum number of nodes in a binary tree of height $h$?
**Answer**: The maximum number of nodes in a binary tree of height $h$ (where root is at level 0) is given by $N_{max} = 2^{h+1} - 1$.

### Q6. Define a Threaded Binary Tree (TBT).
**Answer**: A Threaded Binary Tree is a binary tree variant where `NULL` child pointers are replaced by direct threads pointing to the node's in-order predecessor or in-order successor, allowing stackless/recursionless traversal.

### Q7. What is the Balance Factor in an AVL Tree?
**Answer**: The Balance Factor ($\text{BF}$) of a node in an AVL tree is the height difference between its left subtree and right subtree ($\text{BF} = \text{Height}_{\text{left}} - \text{Height}_{\text{right}}$). Allowed values are $-1, 0, +1$.

### Q8. What sequence does an In-Order Traversal of a BST yield?
**Answer**: An In-Order Traversal of a Binary Search Tree always yields a strictly **ascending sorted sequence** of the key values stored in the tree.

### Q9. List the four types of rotations performed in AVL trees.
**Answer**:
1. LL Rotation (Single Right Rotation)
2. RR Rotation (Single Left Rotation)
3. LR Rotation (Double Left-Right Rotation)
4. RL Rotation (Double Right-Left Rotation)

### Q10. What is an Expression Tree?
**Answer**: An Expression Tree is a binary tree representation of arithmetic expressions where internal nodes store operators ($+, -, \times, \div$) and leaf nodes store operands (numbers or variables).

---

## 9. Important Questions (4 Marks)

### Q1. Explain the sequential array representation of a binary tree with indexing formulas and an example.
**Answer**:
In sequential array representation, nodes of a binary tree are stored in a contiguous 1D array. It is particularly suitable for complete binary trees.

* **Indexing Formulas (0-based indexing)**:
  1. **Root Node**: Stored at array index `0`.
  2. **Left Child**: For a parent at index $i$, Left Child is at index $2i + 1$.
  3. **Right Child**: For a parent at index $i$, Right Child is at index $2i + 2$.
  4. **Parent Node**: For a child at index $i$, Parent is at index $\lfloor (i - 1) / 2 \rfloor$.

* **Example**: For a tree with Root `10` (idx 0), Left child `9` (idx 1), Right child `5` (idx 2):
  * Left child of `9` (idx 1) $= 2(1) + 1 = 3$.
  * Right child of `9` (idx 1) $= 2(1) + 2 = 4$.
  * Array layout: `[10, 9, 5, Left_of_9, Right_of_9, ...]`.

---

### Q2. Describe the three deletion cases in a Binary Search Tree (BST) with diagrams.
**Answer**:
Deleting a node $X$ from a BST involves three distinct cases:

1. **Case 1: $X$ is a Leaf Node (0 Children)**:
   * Disconnect the parent's pointer to $X$ by setting it to `NULL` and free node $X$.
2. **Case 2: $X$ has One Child**:
   * Connect $X$'s parent directly to $X$'s single child, bypassing node $X$, then free $X$.
3. **Case 3: $X$ has Two Children**:
   * Find $X$'s **In-Order Successor** (smallest node in $X$'s right subtree).
   * Copy the In-Order Successor's data value into node $X$.
   * Recursively delete the In-Order Successor node from the right subtree (which falls under Case 1 or Case 2).

---

### Q3. Explain Threaded Binary Trees and distinguish between Left-Threaded, Right-Threaded, and Double-Threaded trees.
**Answer**:
In a standard binary tree with $n$ nodes, $n+1$ pointers are `NULL`. A Threaded Binary Tree (TBT) replaces these `NULL` pointers with "threads" pointing to in-order predecessors/successors to enable stackless traversal.

* **Left-Threaded Binary Tree**: Only `NULL` left pointers are replaced by threads pointing to the in-order predecessor node.
* **Right-Threaded Binary Tree**: Only `NULL` right pointers are replaced by threads pointing to the in-order successor node.
* **Double-Threaded Binary Tree**: Both `NULL` left and right pointers are replaced by threads (left $\to$ in-order predecessor, right $\to$ in-order successor).

---

### Q4. Construct an AVL Tree by inserting the sequence of keys: 30, 20, 10, 40, 50. Show balance factor calculations and rotations at each step.
**Answer**:
1. **Insert 30**: Root node. $\text{BF} = 0$.
2. **Insert 20**: Placed as left child of 30. $\text{BF}(30) = +1$, $\text{BF}(20) = 0$. Balanced.
3. **Insert 10**: Placed as left child of 20.
   * $\text{BF}(30) = +2$ (Unbalanced! LL Case).
   * Perform **LL Rotation (Right Rotation on 30)**:
   * Node `20` becomes root with left child `10` and right child `30`. Balanced!
4. **Insert 40**: Placed as right child of 30.
   * $\text{BF}(20) = -1$, $\text{BF}(30) = -1$. Balanced.
5. **Insert 50**: Placed as right child of 40.
   * $\text{BF}(30) = -2$ (Unbalanced at node 30! RR Case).
   * Perform **RR Rotation (Left Rotation on 30)**:
   * Node `40` takes 30's place with left child `30` and right child `50`.
   * Final Balanced AVL Tree Root is `20` with right subtree rooted at `40`.

---

## 10. Important Long-Answer Questions

### Q1. Explain Binary Tree Traversals (In-order, Pre-order, Post-order) with recursive algorithms, step-by-step traces, and diagrams.
**Answer**:
Tree traversal is the process of visiting every node in a binary tree exactly once.

#### 1. In-Order Traversal (L $\to$ V $\to$ R)
* **Logic**: Traverse Left Subtree $\to$ Visit Root Node $\to$ Traverse Right Subtree.
* **Recursive Algorithm**:
  1. `If node != NULL then`
  2. `Inorder(node->left)`
  3. `Visit(node->data)`
  4. `Inorder(node->right)`

#### 2. Pre-Order Traversal (V $\to$ L $\to$ R)
* **Logic**: Visit Root Node $\to$ Traverse Left Subtree $\to$ Traverse Right Subtree.
* **Recursive Algorithm**:
  1. `If node != NULL then`
  2. `Visit(node->data)`
  3. `Preorder(node->left)`
  4. `Preorder(node->right)`

#### 3. Post-Order Traversal (L $\to$ R $\to$ V)
* **Logic**: Traverse Left Subtree $\to$ Traverse Right Subtree $\to$ Visit Root Node.
* **Recursive Algorithm**:
  1. `If node != NULL then`
  2. `Postorder(node->left)`
  3. `Postorder(node->right)`
  4. `Visit(node->data)`

#### Trace Example:
```
           [ A ]
          /     \
      [ B ]     [ C ]
     /     \
   [ D ]   [ E ]
```
* **In-Order**: $D \to B \to E \to A \to C$
* **Pre-Order**: $A \to B \to D \to E \to C$
* **Post-Order**: $D \to E \to B \to C \to A$

---

### Q2. What is an AVL Tree? Explain balance factor calculations, height rules, and all four rotation types (LL, RR, LR, RL) with detailed worked examples.
**Answer**:
An **AVL Tree** is a height-balanced Binary Search Tree where the Balance Factor of every node satisfies $\text{BF} = H_{\text{left}} - H_{\text{right}} \in \{-1, 0, +1\}$.

#### Balance Factor & Height Rules:
* $\text{Height}(\text{Leaf}) = 0$, $\text{Height}(\text{NULL}) = -1$.
* $\text{Height}(\text{Node}) = 1 + \max(\text{Height}_{\text{left}}, \text{Height}_{\text{right}})$.
* $\text{BF} = \text{Height}_{\text{left}} - \text{Height}_{\text{right}}$.

#### Rotation Types:

1. **LL Rotation (Single Right Rotation)**:
   * Triggered when insertion occurs in left subtree of left child ($\text{BF} = +2$).
   * *Action*: Single Right Rotation on unbalanced node.

2. **RR Rotation (Single Left Rotation)**:
   * Triggered when insertion occurs in right subtree of right child ($\text{BF} = -2$).
   * *Action*: Single Left Rotation on unbalanced node.

3. **LR Rotation (Double Rotation: Left then Right)**:
   * Triggered when insertion occurs in right subtree of left child ($\text{BF} = +2$).
   * *Action*: Left Rotation on left child, then Right Rotation on unbalanced root.

4. **RL Rotation (Double Rotation: Right then Left)**:
   * Triggered when insertion occurs in left subtree of right child ($\text{BF} = -2$).
   * *Action*: Right Rotation on right child, then Left Rotation on unbalanced root.

---

## 11. Chapter Summary and Key Takeaways

1. **Tree Data Structure**: A non-linear, hierarchical data structure composed of nodes connected by directed edges.
2. **Binary Tree**: A tree where every node has at most two children (left and right).
3. **Binary Tree Representations**:
   * **Linked Pointer Representation**: Dynamic `struct` with `left`, `data`, `right`.
   * **Sequential Array Representation**: Root at $0$, Left child at $2i+1$, Right child at $2i+2$.
4. **Binary Traversals**:
   * **In-Order**: Left $\to$ Root $\to$ Right (Yields sorted keys in BST).
   * **Pre-Order**: Root $\to$ Left $\to$ Right.
   * **Post-Order**: Left $\to$ Right $\to$ Root.
5. **Threaded Binary Tree (TBT)**: Replaces $n+1$ `NULL` pointers with threads to in-order predecessors/successors to eliminate recursion stacks during traversal.
6. **Binary Search Tree (BST)**: Binary tree enforcing $\text{Left} < \text{Root} \le \text{Right}$. Average operational time is $O(\log_2 n)$, degrading to $O(n)$ if skewed.
7. **AVL Tree**: Self-balancing BST maintaining balance factor $\text{BF} = H_{\text{left}} - H_{\text{right}} \in \{-1, 0, +1\}$ using LL, RR, LR, and RL rotations.
8. **Applications**: Expression Trees (compilers), BST (database indexing), Heaps (priority queues / OS CPU scheduling), Decision Trees (AI/ML models).

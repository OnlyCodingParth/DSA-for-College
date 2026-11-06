# Chapter 06 – Graph

## 1. Introduction to Graph

A **Graph** is a non-linear data structure consisting of a finite set of **Vertices** (also called nodes) and a set of **Edges** (also called links or arcs) that connect pairs of vertices. Unlike linear data structures such as arrays, linked lists, stacks, and queues—where elements are stored in a sequential, linear order—graphs represent complex, non-linear relationships and interconnections between real-world objects.

Mathematically, a graph $G$ is represented as an ordered pair:

$$G = (V, E)$$

Where:
* $V$ is a non-empty set of vertices or nodes: $V(G) = \{v_1, v_2, v_3, \dots, v_n\}$.
* $E$ is a set of edges or connections: $E(G) = \{e_1, e_2, e_3, \dots, e_m\}$, where each edge $e_k = (u, v)$ connects vertex $u$ and vertex $v$.

### Concrete Example
Consider a graph $G$ with 5 vertices and 4 edges:
* **Vertices**: $V(G) = \{A, B, C, D, E\}$
* **Edges**: $E(G) = \{(A,B), (A,C), (C,D), (C,E)\}$

Visual Representation:
```
(A) ------- (C) ------- (E)
 |           |
 |           |
(B)         (D)
```

### Real-World Applications of Graphs
Graphs are fundamental in computer science and engineering applications, including:
1. **Social Networks**: Users are represented as vertices, and friendships or follower relationships are represented as edges (e.g., Facebook, LinkedIn).
2. **Navigation Systems (Google Maps)**: Locations, intersections, or cities are modeled as vertices, while roads, highways, and travel distances/times represent weighted edges.
3. **Computer Networks**: Computers, routers, and switches are represented as vertices, while physical ethernet cables or wireless bandwidth connections are edges.
4. **Web Hyperlinks (World Wide Web)**: Individual web pages represent vertices, and hyperlinks connecting one page to another act as directed edges (forming the Web Graph utilized by PageRank algorithms).
5. **Operating Systems & Systems Programming**: Processes and system resources are modeled as Directed Acyclic Graphs (DAGs) to detect deadlock cycles or manage task dependencies.

---

## 2. Basic Graph Terminologies and Definitions

To analyze and manipulate graphs effectively, a formal understanding of standard graph theory terminology is essential. Below are the 22 fundamental terms defined in university curricula:

1. **Graph ($G$)**: A finite collection of nodes (vertices) and edges that connect pairs of nodes within a network, denoted as $G = (V, E)$.
2. **Vertex / Node**: An individual data point, entity, or fundamental element within a graph. In a graph $G$ with nodes $A, B, C, D$, $V = \{A, B, C, D\}$.
3. **Edge**: A connection, link, or line drawn between two vertices. If an edge connects vertices $A$ and $B$, it is denoted as $(A, B)$.
4. **Directed Graph (Digraph)**: A graph in which every edge has a specific direction associated with it (represented by arrowheads). An edge $e = (u, v)$ indicates a one-way path originating from $u$ and terminating at $v$.
5. **Undirected Graph**: A graph in which edges have no direction associated with them. An edge between $A$ and $B$ is bidirectional, meaning traversal can occur from $A$ to $B$ as well as from $B$ to $A$.
6. **Degree of a Vertex**: The total number of edges connected to or incident upon a vertex. For an undirected vertex $A$ connected to $B$, $C$, and $D$, the degree of $A$ is $3$.
7. **Complete Graph**: An undirected graph in which every pair of distinct vertices is connected by a unique edge. A complete undirected graph containing $N$ vertices has exactly:

$$\text{Total Edges} = \frac{N(N - 1)}{2}$$

8. **Weighted Graph**: A graph in which each edge is assigned a numerical value, cost, or weight representing distance, latency, capacity, or toll.
9. **In-Degree**: In a directed graph, the in-degree of a vertex is the total number of edges entering or pointing toward that vertex.
10. **Out-Degree**: In a directed graph, the out-degree of a vertex is the total number of edges leaving or originating from that vertex.
11. **Adjacent Node**: Two vertices $u$ and $v$ are adjacent if they are directly connected to each other by an edge $(u, v)$.
12. **Successor**: In a directed graph, if a directed edge exists from $V_1$ to $V_2$ ($V_1 \to V_2$), then $V_2$ is called the **successor** of $V_1$.
13. **Predecessor**: In a directed graph, if a directed edge exists from $V_1$ to $V_2$ ($V_1 \to V_2$), then $V_1$ is called the **predecessor** of $V_2$.
14. **Path**: A sequence of vertices connected by edges that allows movement from a starting vertex to a destination vertex.
15. **Length of a Path**: The total number of edges traversed along a path.
16. **Cycle**: A path that originates and terminates at the same vertex without repeating any edge (e.g., $A \to B \to C \to A$).
17. **Self Edge / Self Loop**: An edge that connects a vertex to itself, denoted as $(v, v)$.
18. **Multigraph**: A graph that contains multiple parallel edges connecting the same pair of vertices.
19. **Sink Node**: A node in a directed graph that has only incoming edges and zero outgoing edges ($\text{In-degree} > 0, \text{Out-degree} = 0$).
20. **Isolated Node**: A node that has no edges connected to it ($\text{Degree} = 0$). It is not adjacent to any other node in the graph.
21. **Pendant Node**: A node having an in-degree of 1 and an out-degree of 0 (or total degree of 1 in an undirected graph).
22. **Articulation Point (Cut Vertex)**: A vertex in an undirected connected graph whose removal (along with its associated edges) increases the number of connected components, thereby disconnecting the graph.

---

## 3. Types of Graphs

Graphs are classified based on edge properties, orientation, density, and connectivity:

### Classification Matrix
| Graph Type | Edge Direction | Edge Weights | Key Feature | Edge Formula / Constraint |
| :--- | :--- | :--- | :--- | :--- |
| **Undirected Graph** | Bidirectional | Unweighted / Weighted | Edges have no arrows; $(u,v) \equiv (v,u)$ | Max Edges = $\frac{N(N-1)}{2}$ |
| **Directed Graph** | One-way | Unweighted / Weighted | Edges have arrows; $(u,v) \neq (v,u)$ | Max Edges = $N(N-1)$ |
| **Weighted Graph** | Either | Numerical values | Edges carry costs/weights | Edges store $(u, v, w)$ |
| **Complete Graph** | Either | Unweighted / Weighted | Every pair of nodes is directly connected | Edges = $\frac{N(N-1)}{2}$ |
| **Multigraph** | Either | Unweighted / Weighted | Contains parallel edges between same nodes | Multiple edges for $(u,v)$ |
| **Acyclic Graph** | Either | Unweighted / Weighted | Contains no simple cycles | Used in DAG task scheduling |

---

## 4. Graph Representation Techniques

To store and manipulate graphs in computer memory, two primary representation schemes are utilized: **Sequential Representation (Adjacency Matrix)** and **Linked Representation (Adjacency List)**.

### 4.1 Adjacency Matrix Representation (Sequential Memory)

An **Adjacency Matrix** is a two-dimensional array $A$ of dimensions $n \times n$, where $n$ is the total number of vertices in the graph. The entries of matrix $A$ are defined as:

$$A[i][j] = \begin{cases} 1 & \text{if there exists an edge between vertex } i \text{ and vertex } j \\ 0 & \text{if there is no edge between vertex } i \text{ and vertex } j \end{cases}$$

For a **weighted graph**, $A[i][j] = w_{ij}$ (the edge weight), and $A[i][j] = \infty$ or $0$ if no edge exists.

#### Characteristics of Adjacency Matrix:
1. **Undirected Graphs**: The matrix is always **symmetric** across its main diagonal ($A[i][j] = A[j][i]$).
2. **Degree Computation**:
   * For an undirected graph, the degree of vertex $i$ is the sum of elements in row $i$: $\text{Degree}(i) = \sum_{j=0}^{n-1} A[i][j]$.
   * For a directed graph, the sum of row $i$ equals the **out-degree** of vertex $i$, while the sum of column $j$ equals the **in-degree** of vertex $j$.
3. **Space Complexity**: Requires fixed $O(n^2)$ memory space regardless of the number of edges.

#### Example: Adjacency Matrix of an Undirected Graph
Consider an undirected graph with 5 vertices $\{A, B, C, D, E\}$:

```
    A --- C --- E
    |     |     |
    |     |     |
    B --- D ----+
```

Matrix Representation $A$:
$$\begin{array}{c|ccccc} & \text{A} & \text{B} & \text{C} & \text{D} & \text{E} \\ \hline \text{A} & 0 & 1 & 1 & 1 & 0 \\ \text{B} & 1 & 0 & 0 & 1 & 0 \\ \text{C} & 1 & 0 & 0 & 1 & 1 \\ \text{D} & 1 & 1 & 1 & 1 & 1 \\ \text{E} & 0 & 0 & 1 & 1 & 0 \end{array}$$

*Note*: Diagonal entry $A[D][D] = 1$ indicates a self-loop at node $D$.

---

### 4.2 Adjacency List Representation (Linked Memory)

An **Adjacency List** represents a graph using an array of linked lists. An array of head pointers of size $n$ is maintained, where each array entry $i$ points to a singly linked list containing all vertices adjacent to vertex $i$.

#### Characteristics of Adjacency List:
1. **Space Efficiency**: Ideal for **sparse graphs** (graphs with few edges). Memory consumed is proportional to $O(V + E)$ for undirected graphs and $O(V + E)$ for directed graphs.
2. **Dynamic Structure**: Nodes can be dynamically created and destroyed using `malloc()` and `free()`.
3. **Weighted Graph Handling**: Each linked list node stores the destination vertex name along with an extra field for edge weight.

#### Example: Adjacency List of a Directed Weighted Graph
Consider vertices $\{A, B, C\}$ with directed edges: $A \xrightarrow{2} C$, $B \xrightarrow{4} A$, $B \xrightarrow{1} D$, $C \xrightarrow{1} B$.

Linked Memory Layout:
```
[ A ] -> [ C | w=2 ] -> NULL
[ B ] -> [ A | w=4 ] -> [ D | w=1 ] -> NULL
[ C ] -> [ B | w=1 ] -> NULL
```

---

## 5. Graph Traversal Techniques

**Graph Traversal** refers to the process of visiting every vertex (node) in a graph exactly once in a systematic order. Traversal algorithms form the backbone of search engines, network routing protocols, and pathfinding algorithms.

Unlike trees, graphs may contain cycles. To prevent infinite looping during traversal, a boolean array `visited[]` of size $V$ is maintained to track visited nodes.

The two fundamental graph traversal algorithms are:
1. **Breadth-First Search (BFS)** – Level-by-level exploration using a **Queue**.
2. **Depth-First Search (DFS)** – Deep branch exploration with backtracking using a **Stack**.

---

## 6. Breadth First Search (BFS)

### 6.1 Concept and Working Principle
**Breadth-First Search (BFS)** visits vertices in a level-by-level manner, expanding outward from a source vertex across all neighboring nodes before moving to the next level of neighbors.

BFS uses a **Queue data structure** operating on a **First-In-First-Out (FIFO)** basis, with a maximum size equal to the total number of vertices $V$.

### 6.2 Step-by-Step BFS Algorithm
1. Initialize a boolean array `visited[V]` to `false` and create an empty queue `Q`.
2. Select a starting source vertex $S$. Mark `visited[S] = true` and enqueue $S$ into `Q`.
3. While `Q` is not empty:
   a. Dequeue the front vertex $u$ from `Q` and process/display $u$.
   b. Iterate through all adjacent neighbors $v$ of vertex $u$.
   c. If neighbor $v$ has not been visited (`visited[v] == false`):
      * Mark `visited[v] = true`.
      * Enqueue $v$ into `Q`.
4. Stop when queue `Q` becomes empty.

---

### 6.3 Complete Execution Trace of BFS
Consider a graph with 7 vertices $\{A, B, C, D, E, F, G\}$ and edges connecting:
$(A,B), (A,D), (A,E), (B,C), (C,E), (C,F), (C,G), (E,F)$.

```
   (A)-------(B)-------(C)-------(G)
   | \       |        /|
   |  \      |       / |
   |   \     |      /  |
  (D)   ----(E)----(F)-+
```

#### Step-by-Step State Table:

| Step | Action Taken | Current Queue State | Visited Array State | Processed / Traversed Output |
| :---: | :--- | :--- | :--- | :--- |
| **1** | Start at vertex $A$. Mark $A$ visited, enqueue $A$. | `[ A ]` | $A=1$ | — |
| **2** | Dequeue $A$. Visit unvisited neighbors of $A$: $D, E, B$. Enqueue them. | `[ D, E, B ]` | $A, D, E, B = 1$ | **A** |
| **3** | Dequeue $D$. Neighbors of $D$ already visited. | `[ E, B ]` | $A, D, E, B = 1$ | **A, D** |
| **4** | Dequeue $E$. Visit unvisited neighbors of $E$: $C, F$. Enqueue them. | `[ B, C, F ]` | $A, D, E, B, C, F = 1$ | **A, D, E** |
| **5** | Dequeue $B$. Neighbors of $B$ ($A, C$) already visited. | `[ C, F ]` | $A, D, E, B, C, F = 1$ | **A, D, E, B** |
| **6** | Dequeue $C$. Visit unvisited neighbor of $C$: $G$. Enqueue $G$. | `[ F, G ]` | $A, D, E, B, C, F, G = 1$ | **A, D, E, B, C** |
| **7** | Dequeue $F$. Neighbors of $F$ already visited. | `[ G ]` | All = $1$ | **A, D, E, B, C, F** |
| **8** | Dequeue $G$. Neighbors of $G$ already visited. Queue empty. | `[ ]` | All = $1$ | **A, D, E, B, C, F, G** |

**Final BFS Traversal Order**: **$A \to D \to E \to B \to C \to F \to G$**

### 6.4 Complexity Analysis of BFS
* **Time Complexity**:
  * Every vertex is enqueued and dequeued exactly once: $O(V)$.
  * Every edge is examined during adjacency traversal: $O(E)$.
  * **Total Time Complexity**: $\mathbf{O(V + E)}$ (using Adjacency List) or $\mathbf{O(V^2)}$ (using Adjacency Matrix).
* **Space Complexity**: The queue holds at most $V$ vertices, and the visited array consumes $O(V)$ space: $\mathbf{O(V)}$.

---

## 7. Depth First Search (DFS)

### 7.1 Concept and Working Principle
**Depth-First Search (DFS)** explores a graph by delving as deep as possible along each path before **backtracking**. When the traversal reaches a node with no unvisited neighbors, it backtracks to the most recently visited node that still has unexplored neighbors.

DFS uses a **Stack data structure** operating on a **Last-In-First-Out (LIFO)** basis (or system recursion call stack), with a maximum capacity equal to $V$.

### 7.2 Step-by-Step DFS Algorithm
1. Initialize a boolean array `visited[V]` to `false` and create an empty stack `S`.
2. Select a starting source vertex $S$. Mark `visited[S] = true` and push $S$ onto `S`.
3. While `S` is not empty:
   a. Look at the top vertex $u$ of stack `S`.
   b. Find any unvisited adjacent neighbor $v$ of $u$.
   c. If an unvisited neighbor $v$ exists:
      * Mark `visited[v] = true`.
      * Push $v$ onto stack `S`.
   d. If no unvisited neighbor exists for $u$:
      * **Backtrack**: Pop $u$ off stack `S`.
4. Stop when stack `S` becomes empty.

---

### 7.3 Complete Execution Trace of DFS
Using the same 7-vertex graph $\{A, B, C, D, E, F, G\}$:

#### Step-by-Step State Table:

| Step | Action Taken | Current Stack State (Bottom $\to$ Top) | Visited Nodes | Traversal Order |
| :---: | :--- | :--- | :--- | :--- |
| **1** | Select $A$. Mark $A$ visited, push $A$. | `[ A ]` | $A$ | **A** |
| **2** | Unvisited neighbor of $A$ is $B$. Visit $B$, push $B$. | `[ A, B ]` | $A, B$ | **A, B** |
| **3** | Unvisited neighbor of $B$ is $C$. Visit $C$, push $C$. | `[ A, B, C ]` | $A, B, C$ | **A, B, C** |
| **4** | Unvisited neighbor of $C$ is $E$. Visit $E$, push $E$. | `[ A, B, C, E ]` | $A, B, C, E$ | **A, B, C, E** |
| **5** | Unvisited neighbor of $E$ is $D$. Visit $D$, push $D$. | `[ A, B, C, E, D ]` | $A, B, C, E, D$ | **A, B, C, E, D** |
| **6** | No unvisited neighbors from $D$. **Backtrack**: Pop $D$. | `[ A, B, C, E ]` | $A, B, C, E, D$ | — |
| **7** | Unvisited neighbor of $E$ is $F$. Visit $F$, push $F$. | `[ A, B, C, E, F ]` | $A, B, C, E, D, F$ | **A, B, C, E, D, F** |
| **8** | Unvisited neighbor of $F$ is $G$. Visit $G$, push $G$. | `[ A, B, C, E, F, G ]` | All 7 Visited | **A, B, C, E, D, F, G** |
| **9** | No unvisited neighbors from $G$. Pop $G$, $F$, $E$, $C$, $B$, $A$. | `[ ]` (Stack Empty) | All 7 Visited | Complete |

**Final DFS Traversal Order**: **$A \to B \to C \to E \to D \to F \to G$**

### 7.4 Complexity Analysis of DFS
* **Time Complexity**:
  * Every vertex is pushed and popped from the stack: $O(V)$.
  * Every edge is traversed during neighbor lookup: $O(E)$.
  * **Total Time Complexity**: $\mathbf{O(V + E)}$ (using Adjacency List) or $\mathbf{O(V^2)}$ (using Adjacency Matrix).
* **Space Complexity**: Stack stores at most $V$ vertices during deep recursion paths: $\mathbf{O(V)}$.

---

## 8. Transitive Closure and Warshall's Algorithm

### 8.1 Concept of Transitive Closure
In graph theory, the **Transitive Closure** of a directed graph $G = (V, E)$ is a graph $G^* = (V, E^*)$ that reveals whether a path exists between every pair of vertices $i$ and $j$, either directly or indirectly through one or more intermediate vertices.

If a path exists from vertex $i$ to vertex $j$, an edge $(i, j)$ is added to the transitive closure graph.

Transitive closure is represented in computer memory as a Boolean matrix $T$ of dimensions $n \times n$:

$$T[i][j] = \begin{cases} 1 & \text{if there exists a path of length } \ge 1 \text{ from vertex } i \text{ to vertex } j \\ 0 & \text{if no path exists from vertex } i \text{ to vertex } j \end{cases}$$

### 8.2 Warshall's Algorithm Procedure
**Warshall's Algorithm** efficiently constructs the transitive closure matrix $T$ by systematically considering every vertex $k$ ($1 \le k \le n$) as an intermediate vertex in path calculations.

#### Boolean Relation / Dynamic Update Formula:
For intermediate vertex $k$, starting vertex $i$, and destination vertex $j$:

$$A^{(k)}[i][j] = A^{(k-1)}[i][j] \lor \left( A^{(k-1)}[i][k] \land A^{(k-1)}[k][j] \right)$$

*In plain words*: A path exists from $i$ to $j$ if there is already a direct path from $i$ to $j$, OR if there is a path from $i$ to intermediate vertex $k$ AND a path from intermediate vertex $k$ to $j$.

#### Algorithmic Steps:
1. Initialize matrix $A^{(0)}$ as the initial $n \times n$ Adjacency Matrix of the directed graph.
2. Outer Loop: Iterate intermediate vertex $k$ from $1$ to $n$.
3. Middle Loop: Iterate starting vertex $i$ from $1$ to $n$.
4. Inner Loop: Iterate destination vertex $j$ from $1$ to $n$.
5. Update cell value using the Boolean rule:
   `A[i][j] = A[i][j] || (A[i][k] && A[k][j])`
6. Output final matrix $T = A^{(n)}$ as the Transitive Closure.

---

### 8.3 Step-by-Step Numerical Example of Warshall's Algorithm

Consider a directed graph with 3 vertices $\{A, B, C\}$ and directed edges $A \to B$ and $B \to C$:

```
(A) -------> (B) -------> (C)
```

#### Step 0: Initial Adjacency Matrix $A^{(0)}$
$$A^{(0)} = \begin{array}{c|ccc} & \text{A} & \text{B} & \text{C} \\ \hline \text{A} & 0 & 1 & 0 \\ \text{B} & 0 & 0 & 1 \\ \text{C} & 0 & 0 & 0 \end{array}$$

#### Step 1: Intermediate Vertex $k = 1$ (Vertex A)
Check if any new path can be formed through vertex $A$. Since vertex $A$ has no incoming edges, no entry in $A^{(0)}$ changes to 1.
$$A^{(1)} = \begin{array}{c|ccc} & \text{A} & \text{B} & \text{C} \\ \hline \text{A} & 0 & 1 & 0 \\ \text{B} & 0 & 0 & 1 \\ \text{C} & 0 & 0 & 0 \end{array}$$

#### Step 2: Intermediate Vertex $k = 2$ (Vertex B)
Check if new paths can be formed through vertex $B$:
* Look for pairs where $A[i][B] = 1$ and $A[B][j] = 1$.
* $A[A][B] = 1$ and $A[B][C] = 1 \implies A[A][C] = A[A][C] \lor (1 \land 1) = 0 \lor 1 = \mathbf{1}$.
* Update entry $A[A][C]$ from $0$ to $1$.

$$A^{(2)} = \begin{array}{c|ccc} & \text{A} & \text{B} & \text{C} \\ \hline \text{A} & 0 & 1 & \mathbf{1} \\ \text{B} & 0 & 0 & 1 \\ \text{C} & 0 & 0 & 0 \end{array}$$

#### Step 3: Intermediate Vertex $k = 3$ (Vertex C)
Check if new paths can be formed through vertex $C$. Vertex $C$ has no outgoing edges, so no entry changes.
$$A^{(3)} = \begin{array}{c|ccc} & \text{A} & \text{B} & \text{C} \\ \hline \text{A} & 0 & 1 & 1 \\ \text{B} & 0 & 0 & 1 \\ \text{C} & 0 & 0 & 0 \end{array}$$

#### Final Transitive Closure Matrix $T$:
$$T = \begin{bmatrix} 0 & 1 & 1 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

*Interpretation*: $T[A][C] = 1$ confirms that vertex $C$ is reachable from vertex $A$ via path $A \to B \to C$.

### 8.4 Complexity Analysis of Warshall's Algorithm
* **Time Complexity**: The algorithm uses three nested loops, each executing $n$ times (where $n = V$):
  $$\text{Total Time Complexity} = O(n \times n \times n) = \mathbf{O(n^3)} \text{ or } \mathbf{O(V^3)}$$
* **Space Complexity**: Requires an $n \times n$ matrix to store intermediate states: $\mathbf{O(n^2)}$ or $\mathbf{O(V^2)}$.

---

## 9. Complexity Analysis Summary

| Algorithm / Operation | Time Complexity (Adjacency Matrix) | Time Complexity (Adjacency List) | Auxiliary Space Complexity | Primary Data Structure Used |
| :--- | :---: | :---: | :---: | :---: |
| **Adjacency Matrix Construction** | $O(V^2)$ | $O(V^2)$ | $O(V^2)$ | 2D Sequential Array |
| **Adjacency List Construction** | $O(V + E)$ | $O(V + E)$ | $O(V + E)$ | Array of Dynamic Linked Lists |
| **Breadth-First Search (BFS)** | $O(V^2)$ | $O(V + E)$ | $O(V)$ | Queue (FIFO) |
| **Depth-First Search (DFS)** | $O(V^2)$ | $O(V + E)$ | $O(V)$ | Stack (LIFO) / Call Stack |
| **Warshall's Algorithm** | $O(V^3)$ | $O(V^3)$ | $O(V^2)$ | 2D Transitive Matrix |

---

## 10. Comparisons and Summary Tables

### 10.1 BFS vs. DFS Traversal
| Parameter | Breadth-First Search (BFS) | Depth-First Search (DFS) |
| :--- | :--- | :--- |
| **Traversal Strategy** | Level-by-level (broad exploration) | Path-by-path (deep exploration before backtracking) |
| **Data Structure Used** | **Queue** (FIFO) | **Stack** (LIFO) or Recursion |
| **Memory Requirement** | Higher in wide graphs ($O(W)$ where $W$ is max width) | Higher in deep graphs ($O(H)$ where $H$ is max height) |
| **Shortest Path Property** | Guarantees shortest path in unweighted graphs | Does not guarantee shortest path |
| **Primary Applications** | Shortest path finding, Peer-to-Peer networks, Social network distance | Cycle detection, Topological sorting, Solving mazes/puzzles |

### 10.2 Adjacency Matrix vs. Adjacency List
| Parameter | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Memory Representation** | 2D $n \times n$ Sequential Array | Array of Dynamic Linked Lists |
| **Space Complexity** | $O(V^2)$ (Fixed, wasteful for sparse graphs) | $O(V + E)$ (Optimal for sparse graphs) |
| **Edge Lookup Time** | $O(1)$ constant time (`A[i][j]`) | $O(\text{Degree}(v))$ linear list scan |
| **Adding a Vertex** | Costly $O(V^2)$ (Requires reallocating 2D array) | Fast $O(1)$ (Append new list head) |
| **Best Suited For** | **Dense Graphs** ($E \approx V^2$) | **Sparse Graphs** ($E \ll V^2$) |

---

## 11. Important Definitions

* **Graph**: A non-linear data structure defined as $G = (V, E)$, consisting of vertices and edges connecting them.
* **Adjacency Matrix**: A 2D square binary matrix of size $V \times V$ used to represent edge connections between graph vertices.
* **Adjacency List**: A memory-efficient graph representation using an array of linked lists storing neighboring vertices.
* **Breadth-First Search (BFS)**: A level-order graph traversal algorithm that uses a queue to visit all neighbors of a node before moving deeper.
* **Depth-First Search (DFS)**: A graph traversal algorithm that uses a stack or recursion to explore as far as possible along each branch before backtracking.
* **Transitive Closure**: A reachability matrix showing whether a directed path exists between every pair of vertices in a graph.
* **Warshall's Algorithm**: An $O(V^3)$ dynamic programming algorithm used to calculate the transitive closure of a directed graph.
* **Articulation Point**: A vertex whose removal increases the number of connected components in an undirected graph.

---

## 12. Programming Questions

To enforce clean separation of theory and programming implementations, C source code is maintained in dedicated `.c` files. Below are the standard examination programming tasks:

1. **Programming Question 1**: Write a menu-driven C program to create and display the Adjacency Matrix representation of an undirected and directed graph.
   * **Assigned C File**: `Graph_Adjacency_Matrix.c`
   * **Logic & Concepts**: Allocate a 2D array `adj[MAX][MAX]`. Read total vertices $V$ and edges $E$. For each edge $(u, v)$, set `adj[u][v] = 1` (and `adj[v][u] = 1` if undirected). Print the $V \times V$ grid.

2. **Programming Question 2**: Write a C program to implement the Adjacency List representation of a weighted directed graph using dynamic structure nodes.
   * **Assigned C File**: `Graph_Adjacency_List.c`
   * **Logic & Concepts**: Define `struct Node { int vertex; int weight; struct Node* next; }`. Maintain an array of head pointers `struct Node* head[MAX]`. Dynamically allocate nodes using `malloc()` to append neighbors.

3. **Programming Question 3**: Write a C program to implement Breadth-First Search (BFS) graph traversal using an explicit array-based Queue.
   * **Assigned C File**: `BFS_Traversal.c`
   * **Logic & Concepts**: Maintain an array `visited[MAX]` initialized to $0$ and a FIFO queue with `front` and `rear` pointers. Enqueue starting vertex, mark visited, dequeue, print, and enqueue all unvisited neighbors.

4. **Programming Question 4**: Write a C program to implement Depth-First Search (DFS) graph traversal using an explicit array-based Stack.
   * **Assigned C File**: `DFS_Traversal.c`
   * **Logic & Concepts**: Maintain `visited[MAX]` array and a LIFO stack array with `top` pointer. Push start vertex, mark visited. While stack is not empty, peek top node, find unvisited neighbor, push it, or pop if no unvisited neighbor remains.

5. **Programming Question 5**: Write a C program to compute the Transitive Closure of a directed graph using Warshall's Algorithm.
   * **Assigned C File**: `Warshalls_Algorithm.c`
   * **Logic & Concepts**: Read adjacency matrix into `A[MAX][MAX]`. Execute three nested loops `for(k=0; k<V; k++) for(i=0; i<V; i++) for(j=0; j<V; j++)`. Apply Boolean formula `A[i][j] = A[i][j] || (A[i][k] && A[k][j])`. Print final reachability matrix.

---

## 13. Short Answer Questions (2 Marks)

### Q1. Define a Graph. How does it differ from a Tree?
**Answer**: A graph is a non-linear data structure consisting of a set of vertices $V$ and edges $E$, denoted as $G = (V, E)$. Unlike a tree—which is a hierarchical data structure with a single root node, parent-child relationships, and no cycles—a graph is a network structure that can have multiple paths, cycles, self-loops, and no designated root.

### Q2. Calculate the maximum number of edges in an undirected complete graph with 6 vertices.
**Answer**: Formula for max edges in an undirected complete graph is $\frac{N(N-1)}{2}$.
$$\text{Max Edges} = \frac{6 \times (6 - 1)}{2} = \frac{6 \times 5}{2} = 15 \text{ edges}$$

### Q3. What is an Articulation Point in a graph?
**Answer**: An Articulation Point (or cut vertex) is a vertex in an undirected connected graph whose removal (along with its incident edges) increases the number of connected components, thereby disconnecting the graph into two or more separate subgraphs.

### Q4. Differentiate between In-Degree and Out-Degree of a vertex.
**Answer**: In a directed graph:
* **In-Degree**: The number of directed edges pointing toward/entering a vertex.
* **Out-Degree**: The number of directed edges originating from/leaving a vertex.

### Q5. What data structure is used to implement BFS and DFS traversals?
**Answer**:
* **BFS** uses a **Queue** data structure (FIFO) to visit vertices level by level.
* **DFS** uses a **Stack** data structure (LIFO) or system recursion stack to explore branches deeply before backtracking.

---

## 14. Medium Answer Questions (4 Marks)

### Q1. Compare Adjacency Matrix and Adjacency List representations of graphs with respect to memory space and edge lookup efficiency.
**Answer**:
1. **Memory Space Complexity**:
   * **Adjacency Matrix**: Consumes fixed $O(V^2)$ space regardless of whether the graph is sparse or dense. It is inefficient for sparse graphs as most matrix entries remain 0.
   * **Adjacency List**: Consumes $O(V + E)$ space. It dynamically allocates nodes using linked lists, making it highly space-efficient for sparse graphs where $E \ll V^2$.
2. **Edge Lookup Efficiency**:
   * **Adjacency Matrix**: Checking if an edge exists between vertex $i$ and vertex $j$ takes **$O(1)$ constant time** by querying `matrix[i][j]`.
   * **Adjacency List**: Checking an edge requires traversing the linked list of vertex $i$, taking **$O(\text{Degree}(i))$ linear time**.

### Q2. Explain the step-by-step working principle of Breadth-First Search (BFS) with an algorithm.
**Answer**:
Breadth-First Search (BFS) traverses a graph level by level from a designated source vertex $S$.

**Algorithm Steps**:
1. Initialize array `visited[V] = {false}` and an empty Queue `Q`.
2. Mark `visited[S] = true` and insert source $S$ into `Q`.
3. While `Q` is not empty:
   * Dequeue front element $u$ from `Q` and process $u$.
   * For every adjacent neighbor $v$ of $u$:
     * If `visited[v] == false`, set `visited[v] = true` and enqueue $v$ into `Q`.
4. Stop when `Q` is empty.

**Complexity**: Time $O(V + E)$, Space $O(V)$.

---

## 15. Long Answer Questions

### Q1. State Warshall's Algorithm for finding the Transitive Closure of a directed graph. Trace the algorithm step by step on a graph with 3 vertices $A, B, C$ having directed edges $A \to B$ and $B \to C$.

**Answer**:

#### 1. Definition and Concept
Warshall's Algorithm computes the **Transitive Closure** matrix $T$ of a directed graph. Matrix entry $T[i][j] = 1$ if there exists a directed path of length $\ge 1$ from vertex $i$ to vertex $j$, and $0$ otherwise.

#### 2. Boolean Formula
For intermediate vertex $k$ ($1 \le k \le n$):

$$A^{(k)}[i][j] = A^{(k-1)}[i][j] \lor \left( A^{(k-1)}[i][k] \land A^{(k-1)}[k][j] \right)$$

#### 3. Step-by-Step Trace
Given directed graph: $A \to B$ and $B \to C$.

* **Step 0: Initial Adjacency Matrix $A^{(0)}$**
  $$A^{(0)} = \begin{bmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

* **Step 1: Intermediate Vertex $k = 1$ ($A$)**
  No incoming edges to $A$. Matrix remains unchanged:
  $$A^{(1)} = \begin{bmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

* **Step 2: Intermediate Vertex $k = 2$ ($B$)**
  Check pairs through $B$:
  $A[A][B] = 1$ and $A[B][C] = 1 \implies A[A][C] = 0 \lor (1 \land 1) = \mathbf{1}$.
  $$A^{(2)} = \begin{bmatrix} 0 & 1 & \mathbf{1} \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

* **Step 3: Intermediate Vertex $k = 3$ ($C$)**
  $C$ has no outgoing edges. Matrix remains unchanged:
  $$A^{(3)} = \begin{bmatrix} 0 & 1 & 1 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

#### 4. Final Transitive Closure Matrix $T$
$$T = \begin{bmatrix} 0 & 1 & 1 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{bmatrix}$$

#### 5. Complexity
* **Time Complexity**: $O(V^3)$ due to 3 nested loops.
* **Space Complexity**: $O(V^2)$ for matrix storage.

---

## 16. Chapter Summary and Key Points

* **Graph Definition**: A non-linear network data structure $G = (V, E)$ consisting of vertices connected by edges.
* **Core Terminologies**: Vertices, edges, directed vs. undirected, complete graph ($N(N-1)/2$ edges), weighted graph, in-degree, out-degree, cycle, self loop, isolated node, articulation point.
* **Representation**:
  * **Adjacency Matrix**: $V \times V$ 2D array, $O(V^2)$ space, $O(1)$ edge lookup. Best for dense graphs.
  * **Adjacency List**: Array of linked lists, $O(V + E)$ space, $O(\text{Degree})$ edge lookup. Best for sparse graphs.
* **Traversals**:
  * **BFS**: Level-order traversal using **Queue** (FIFO), $O(V + E)$ time, $O(V)$ space.
  * **DFS**: Deep-dive traversal using **Stack** (LIFO) and backtracking, $O(V + E)$ time, $O(V)$ space.
* **Warshall's Algorithm**: Computes transitive closure matrix $T$ using $A[i][j] = A[i][j] \lor (A[i][k] \land A[k][j])$, executing in $O(V^3)$ time and $O(V^2)$ space.

# Chapter 05 – Sorting & Hashing

## 1. Introduction
Data organization is a fundamental problem in computer science. Once data is collected, it must be arranged systematically to enable rapid searching, retrieval, and analysis. **Sorting** and **Hashing** represent two core paradigms for managing data efficiently:
* **Sorting** reorders a collection of data elements into a specified sequential order (ascending or descending), transforming an unsorted dataset into a structured array that enables logarithmic searching techniques such as Binary Search.
* **Hashing** bypasses sequential searching entirely by using a mathematical transformation (a Hash Function) to compute the exact storage address of a record, achieving near-instantaneous, constant-time $O(1)$ search, insertion, and deletion operations.

---

## 2. Sorting Fundamentals & Classification

### 2.1 Definition of Sorting
**Sorting** is an operational process performed on a data structure to arrange a list of data elements in a specific order (either ascending or descending numerical/alphabetical sequence).

For example, given an unsorted array:
$$\text{Unsorted Array: } [25, 12, 20, 15, 30]$$
A sorting algorithm rearranges the elements in ascending order as:
$$\text{Sorted Array: } [12, 15, 20, 25, 30]$$

### 2.2 Classification of Sorting Methods
Sorting algorithms are broadly categorized into two main classes based on where the data is stored during the execution of the sort:

#### 1. Internal Storage Sorting
* **Definition**: Internal sorting applies when the dataset to be sorted is small enough to fit completely within the computer's primary memory (RAM).
* **Working Principle**: All data comparisons, movements, and pointer manipulations occur directly in high-speed main memory.
* **Examples**: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Heap Sort (when applied to in-memory arrays).

#### 2. External Storage Sorting
* **Definition**: External sorting is required when the file or dataset to be sorted is too large to fit into main memory at once, requiring physical storage in secondary memory (such as hard disks, solid-state drives, or magnetic tapes).
* **Working Principle**: Data is processed in chunks or "runs" loaded from secondary storage into main memory, sorted internally, and then merged back onto secondary disk storage.
* **Examples**: External Merge Sort, Multi-way Merge Sort.

---

## 3. Elementary Comparison-Based Sorting Algorithms

### 3.1 Bubble Sort

#### 1. Definition & Working Principle
**Bubble Sort** is a simple comparison-based sorting algorithm. It works by repeatedly stepping through the array, comparing adjacent pairs of elements, and swapping them if they are in the wrong order. 

During each complete pass over the array, the largest unsorted element "bubbles up" to its correct final position at the end of the array.

#### 2. Step-by-Step Algorithm
Let $a[\text{max}]$ be an array and $n$ be the total number of elements:
1. **Step 1**: Repeat for pass $i = 1$ to $n-1$.
2. **Step 2**: Repeat for index $j = 0$ to $n - i - 1$.
3. **Step 3**: If $a[j] > a[j+1]$, swap $a[j]$ and $a[j+1]$.
4. **Step 4**: At the end of pass $i$, the largest element among the remaining unsorted elements is settled at index $n - i$.
5. **Step 5**: Continue until all passes are completed and print the sorted array.

#### 3. Step-by-Step Dry Run Example
Sort the following unsorted array in ascending order using Bubble Sort:
$$\text{Array } a[] = \{5, 9, 6, 2, 8, 1\} \quad (n = 6)$$

* **Pass 1**:
  * Compare $a[0]$ (5) and $a[1]$ (9): $5 \le 9 \implies \text{No swap}$. Array: `[5, 9, 6, 2, 8, 1]`
  * Compare $a[1]$ (9) and $a[2]$ (6): $9 > 6 \implies \text{Swap}$. Array: `[5, 6, 9, 2, 8, 1]`
  * Compare $a[2]$ (9) and $a[3]$ (2): $9 > 2 \implies \text{Swap}$. Array: `[5, 6, 2, 9, 8, 1]`
  * Compare $a[3]$ (9) and $a[4]$ (8): $9 > 8 \implies \text{Swap}$. Array: `[5, 6, 2, 8, 9, 1]`
  * Compare $a[4]$ (9) and $a[5]$ (1): $9 > 1 \implies \text{Swap}$. Array: `[5, 6, 2, 8, 1, 9]`
  * *End of Pass 1*: Element **`9`** is locked at index 5. Unsorted portion: `[5, 6, 2, 8, 1]`

* **Pass 2**:
  * Compare $a[0]$ (5) and $a[1]$ (6): $5 \le 6 \implies \text{No swap}$. Array: `[5, 6, 2, 8, 1, 9]`
  * Compare $a[1]$ (6) and $a[2]$ (2): $6 > 2 \implies \text{Swap}$. Array: `[5, 2, 6, 8, 1, 9]`
  * Compare $a[2]$ (6) and $a[3]$ (8): $6 \le 8 \implies \text{No swap}$. Array: `[5, 2, 6, 8, 1, 9]`
  * Compare $a[3]$ (8) and $a[4]$ (1): $8 > 1 \implies \text{Swap}$. Array: `[5, 2, 6, 1, 8, 9]`
  * *End of Pass 2*: Element **`8`** is locked at index 4. Unsorted portion: `[5, 2, 6, 1]`

* **Pass 3**:
  * Compare $a[0]$ (5) and $a[1]$ (2): $5 > 2 \implies \text{Swap}$. Array: `[2, 5, 6, 1, 8, 9]`
  * Compare $a[1]$ (5) and $a[2]$ (6): $5 \le 6 \implies \text{No swap}$. Array: `[2, 5, 6, 1, 8, 9]`
  * Compare $a[2]$ (6) and $a[3]$ (1): $6 > 1 \implies \text{Swap}$. Array: `[2, 5, 1, 6, 8, 9]`
  * *End of Pass 3*: Element **`6`** is locked at index 3. Unsorted portion: `[2, 5, 1]`

* **Pass 4**:
  * Compare $a[0]$ (2) and $a[1]$ (5): $2 \le 5 \implies \text{No swap}$. Array: `[2, 5, 1, 6, 8, 9]`
  * Compare $a[1]$ (5) and $a[2]$ (1): $5 > 1 \implies \text{Swap}$. Array: `[2, 1, 5, 6, 8, 9]`
  * *End of Pass 4*: Element **`5`** is locked at index 2. Unsorted portion: `[2, 1]`

* **Pass 5**:
  * Compare $a[0]$ (2) and $a[1]$ (1): $2 > 1 \implies \text{Swap}$. Array: `[1, 2, 5, 6, 8, 9]`
  * *End of Pass 5*: Element **`2`** and **`1`** are in position.

* **Final Sorted Array**: `[1, 2, 5, 6, 8, 9]`

#### 4. Programming Implementation Concept & C Logic
The C implementation relies on two nested loops: an outer loop iterating $n-1$ times for passes, and an inner loop comparing adjacent elements `a[j]` and `a[j+1]`. If `a[j] > a[j+1]`, a temporary variable `temp` swaps their values.

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n)$ (when the array is already sorted and an optimized flag stops iteration after 1 pass).
* **Average Case Time Complexity**: $O(n^2)$
* **Worst Case Time Complexity**: $O(n^2)$ (when the input array is sorted in reverse order).
* **Auxiliary Space Complexity**: $O(1)$ (in-place sorting requiring no additional memory).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Very simple to understand and easy to implement.
  2. In-place algorithm requiring $O(1)$ extra space.
  3. Stable sorting algorithm (preserves relative order of equal elements).
* **Disadvantages**:
  1. Highly inefficient for large datasets due to $O(n^2)$ time complexity.
  2. Performs excessive comparisons and swapping operations.

---

### 3.2 Selection Sort

#### 1. Definition & Working Principle
**Selection Sort** is a comparison-based in-place sorting algorithm. It divides the array into two logical parts: a sorted subarray at the left end and an unsorted subarray at the right end. In each pass, the algorithm finds (selects) the smallest (minimum) element from the unsorted subarray and swaps it with the first element of the unsorted subarray, thereby expanding the sorted boundary by one position.

#### 2. Step-by-Step Algorithm
Let $a[\text{max}]$ be an array of size $n$:
1. **Step 1**: Loop $i$ from $0$ to $n-2$ (representing the boundary of the sorted region).
2. **Step 2**: Set $\text{min\_idx} = i$.
3. **Step 3**: Loop $j$ from $i+1$ to $n-1$:
   * If $a[j] < a[\text{min\_idx}]$, update $\text{min\_idx} = j$.
4. **Step 4**: Swap $a[i]$ with $a[\text{min\_idx}]$.
5. **Step 5**: Repeat until the outer loop terminates.

#### 3. Step-by-Step Dry Run Example
Sort the following array in ascending order using Selection Sort:
$$\text{Array } a[] = \{23, 15, 29, 11, 01\} \quad (n = 5)$$

* **Pass 1** ($i = 0$):
  * Initial minimum candidate: $a[0] = 23$.
  * Compare with $a[1]$ (15): $15 < 23 \implies \text{min} = 15$ at idx 1.
  * Compare with $a[2]$ (29): $29 > 15 \implies \text{min remains } 15$.
  * Compare with $a[3]$ (11): $11 < 15 \implies \text{min} = 11$ at idx 3.
  * Compare with $a[4]$ (01): $01 < 11 \implies \text{min} = 01$ at idx 4.
  * Swap $a[0]$ (23) and $a[4]$ (01).
  * *Array after Pass 1*: `[01 | 15, 29, 11, 23]` (Sorted: `[01]`)

* **Pass 2** ($i = 1$):
  * Unsorted region starts at index 1 (`15, 29, 11, 23`).
  * Initial minimum candidate: $a[1] = 15$.
  * Compare with $a[2]$ (29): $29 > 15 \implies \text{min remains } 15$.
  * Compare with $a[3]$ (11): $11 < 15 \implies \text{min} = 11$ at idx 3.
  * Compare with $a[4]$ (23): $23 > 11 \implies \text{min remains } 11$.
  * Swap $a[1]$ (15) and $a[3]$ (11).
  * *Array after Pass 2*: `[01, 11 | 29, 15, 23]` (Sorted: `[01, 11]`)

* **Pass 3** ($i = 2$):
  * Unsorted region starts at index 2 (`29, 15, 23`).
  * Initial minimum candidate: $a[2] = 29$.
  * Compare with $a[3]$ (15): $15 < 29 \implies \text{min} = 15$ at idx 3.
  * Compare with $a[4]$ (23): $23 > 15 \implies \text{min remains } 15$.
  * Swap $a[2]$ (29) and $a[3]$ (15).
  * *Array after Pass 3*: `[01, 11, 15 | 29, 23]` (Sorted: `[01, 11, 15]`)

* **Pass 4** ($i = 3$):
  * Unsorted region starts at index 3 (`29, 23`).
  * Initial minimum candidate: $a[3] = 29$.
  * Compare with $a[4]$ (23): $23 < 29 \implies \text{min} = 23$ at idx 4.
  * Swap $a[3]$ (29) and $a[4]$ (23).
  * *Array after Pass 4*: `[01, 11, 15, 23, 29]`

* **Final Sorted Array**: `[01, 11, 15, 23, 29]`

#### 4. Programming Implementation Concept & C Logic
Selection sort uses an outer loop to advance the sorted partition pointer `i`, an inner loop `j` scanning from `i+1` to `n-1` to find the index `min_idx` holding the minimum value, and a swap between `a[i]` and `a[min_idx]`.

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n^2)$
* **Average Case Time Complexity**: $O(n^2)$
* **Worst Case Time Complexity**: $O(n^2)$
  *(Note: Selection sort always performs $n(n-1)/2$ comparisons regardless of initial array order).*
* **Auxiliary Space Complexity**: $O(1)$ (in-place).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Simple logic, easy to code and understand.
  2. Performs a minimal number of data swaps ($O(n)$ total swaps), making it useful when write operations to memory are expensive.
  3. In-place sorting requiring $O(1)$ memory.
* **Disadvantages**:
  1. Slow $O(n^2)$ performance on all inputs, including already sorted arrays.
  2. Unstable sort in its standard implementation.

---

### 3.3 Insertion Sort

#### 1. Definition & Working Principle
**Insertion Sort** is an in-place comparison-based algorithm that works similarly to the way we sort playing cards in our hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked one by one (called the `key`) and inserted into their correct position in the sorted part by shifting all larger elements one position to the right.

#### 2. Step-by-Step Algorithm
1. **Step 1**: Assume the first element ($a[0]$) is already sorted.
2. **Step 2**: For $i = 1$ to $n-1$, pick $key = a[i]$.
3. **Step 3**: Set index $j = i - 1$.
4. **Step 4**: While $j \ge 0$ and $a[j] > key$:
   * Shift $a[j]$ one position right: $a[j+1] = a[j]$.
   * Decrement $j = j - 1$.
5. **Step 5**: Insert $key$ at its correct position: $a[j+1] = key$.
6. **Step 6**: Repeat until the entire array is sorted.

#### 3. Step-by-Step Dry Run Example
Sort the following array using Insertion Sort:
$$\text{Array } a[] = \{25, 12, 20, 15, 30\} \quad (n = 5)$$

* **Initial State**: Sorted: `[25]`, Unsorted: `[12, 20, 15, 30]`
* **Pass 1** ($i = 1, key = 12$):
  * Compare $key$ (12) with $a[0]$ (25): $25 > 12 \implies \text{Shift 25 right to index 1}$.
  * Insert $key$ (12) at index 0.
  * *Array*: `[12, 25 | 20, 15, 30]`

* **Pass 2** ($i = 2, key = 20$):
  * Compare $key$ (20) with $a[1]$ (25): $25 > 20 \implies \text{Shift 25 right to index 2}$.
  * Compare $key$ (20) with $a[0]$ (12): $12 \le 20 \implies \text{Stop shifting}$.
  * Insert $key$ (20) at index 1.
  * *Array*: `[12, 20, 25 | 15, 30]`

* **Pass 3** ($i = 3, key = 15$):
  * Compare $key$ (15) with $a[2]$ (25): $25 > 15 \implies \text{Shift 25 right}$.
  * Compare $key$ (15) with $a[1]$ (20): $20 > 15 \implies \text{Shift 20 right}$.
  * Compare $key$ (15) with $a[0]$ (12): $12 \le 15 \implies \text{Stop shifting}$.
  * Insert $key$ (15) at index 1.
  * *Array*: `[12, 15, 20, 25 | 30]`

* **Pass 4** ($i = 4, key = 30$):
  * Compare $key$ (30) with $a[3]$ (25): $30 > 25 \implies \text{No shift needed}$.
  * Insert $key$ (30) at index 4.
  * *Array*: `[12, 15, 20, 25, 30]`

* **Final Sorted Array**: `[12, 15, 20, 25, 30]`

#### 4. Programming Implementation Concept & C Logic
The C logic stores `key = a[i]` in an outer loop `for(i=1; i<n; i++)`, then executes an inner `while(j >= 0 && a[j] > key)` loop that shifts `a[j+1] = a[j]` and decrements `j`. Finally, `a[j+1] = key` inserts the element.

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n)$ (when the input array is already sorted; inner loop condition fails immediately).
* **Average Case Time Complexity**: $O(n^2)$
* **Worst Case Time Complexity**: $O(n^2)$ (when the array is sorted in reverse order).
* **Auxiliary Space Complexity**: $O(1)$ (in-place).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Adaptive: Excellent $O(n)$ speed for nearly-sorted datasets.
  2. Stable sorting algorithm.
  3. In-place sorting requiring $O(1)$ extra space.
  4. Very low overhead for small arrays.
* **Disadvantages**:
  1. Inefficient $O(n^2)$ time complexity for large unsorted datasets.
  2. Requires significant element shifting in worst-case scenarios.

---

## 4. Advanced Divide-and-Conquer Sorting Algorithms

### 4.1 Quick Sort

#### 1. Definition & Working Principle
**Quick Sort** is an advanced, highly efficient, comparison-based algorithm that operates on the **Divide-and-Conquer** paradigm. It selects an element as a **pivot** and partitions the array into two sub-arrays such that all elements less than or equal to the pivot are placed to its left, and all elements greater than the pivot are placed to its right. It then recursively applies Quick Sort to the left and right sub-arrays.

#### 2. Three Algorithmic Phases
1. **Divide**: Partition the array $a[low \dots high]$ around a pivot element $P$. Rearrange elements such that elements in the left partition $\le P$ and elements in the right partition $\ge P$.
2. **Conquer**: Recursively call Quick Sort on the left partition $a[low \dots pivot-1]$ and the right partition $a[pivot+1 \dots high]$.
3. **Combine**: No explicit work is needed during combination; the sub-arrays are sorted in-place.

#### 3. Partitioning Logic & Rules (First Element as Pivot)
Let $P = a[low]$ be the pivot element:
1. Initialize left pointer $a = low + 1$ and right pointer $b = high$.
2. **Move $a$**: Increment $a$ while $a \le high$ and $a[a] \le P$.
3. **Move $b$**: Decrement $b$ while $b \ge low$ and $a[b] > P$.
4. **Swap condition**: If $a < b$ (pointers have not crossed), swap $a[a]$ and $a[b]$, then repeat steps 2 and 3.
5. **Cross condition**: If $a \ge b$ (pointers have crossed), stop moving pointers. Swap the pivot element $a[low]$ with $a[b]$.
6. The pivot is now at its correct final sorted index $b$. Return index $b$ as the partition boundary.

#### 4. Step-by-Step Dry Run Example
Sort the following array using Quick Sort:
$$\text{Array } a[] = \{40, 20, 10, 50, 30\} \quad (low = 0, high = 4)$$

* **Partition 1**:
  * Set Pivot $P = a[0] = 40$. Pointer $a = 1$ ($a[1]=20$), Pointer $b = 4$ ($a[4]=30$).
  * *Move $a$*:
    * $a[1]$ (20) $\le 40 \implies a$ moves to 2 ($a[2]=10$).
    * $a[2]$ (10) $\le 40 \implies a$ moves to 3 ($a[3]=50$).
    * $a[3]$ (50) $> 40 \implies a$ stops at index 3.
  * *Move $b$*:
    * $a[4]$ (30) $\le 40 \implies b$ stops at index 4.
  * *Check pointers*: $a = 3, b = 4$. Since $a < b$, swap $a[3]$ (50) and $a[4]$ (30).
    * Array becomes: `[40, 20, 10, 30, 50]`
  * *Resume moving $a$ and $b$*:
    * *Move $a$*: $a[3]$ (30) $\le 40 \implies a$ moves to 4 ($a[4]=50$). $a[4]$ (50) $> 40 \implies a$ stops at index 4.
    * *Move $b$*: $a[4]$ (50) $> 40 \implies b$ moves left to 3 ($a[3]=30$). $a[3]$ (30) $\le 40 \implies b$ stops at index 3.
  * *Check pointers*: $a = 4, b = 3$. Pointers have crossed ($a \ge b$).
  * *Final Partition Swap*: Swap pivot $a[0]$ (40) with $a[b]$ ($a[3]=30$).
    * Array becomes: `[30, 20, 10, 40, 50]`
  * Pivot **`40`** is now at index 3 (its correct position).

* **Recursive Sub-problems**:
  * Left Sub-array: `[30, 20, 10]` ($low = 0, high = 2$)
    * Pivot $P = 30$. $a=1 (20), b=2 (10)$.
    * Move $a$: $20 \le 30 \implies a=2 (10)$. $10 \le 30 \implies a=3$.
    * Move $b$: $10 \le 30 \implies b$ stops at index 2.
    * Pointers crossed ($a=3, b=2$). Swap pivot 30 with $a[2]$ (10).
    * Sub-array becomes: `[10, 20, 30]`. Pivot **`30`** locked.
  * Right Sub-array: `[50]` ($low = 4, high = 4$) $\implies$ Single element base case, already sorted.

* **Final Sorted Array**: `[10, 20, 30, 40, 50]`

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n \log n)$ (when the pivot splits the array into two nearly equal halves at every step).
* **Average Case Time Complexity**: $O(n \log n)$
* **Worst Case Time Complexity**: $O(n^2)$ (when the input array is already sorted in ascending/descending order and the smallest or largest element is chosen as pivot every time).
* **Auxiliary Space Complexity**: $O(\log n)$ average call stack memory ($O(n)$ worst-case call stack recursion depth).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Fastest internal sorting algorithm in practice with $O(n \log n)$ average time complexity.
  2. In-place sorting algorithm (requires no secondary array storage).
  3. Low memory overhead beyond the call stack.
* **Disadvantages**:
  1. Unstable sorting algorithm.
  2. Degenerates to $O(n^2)$ worst-case complexity if poor pivots are chosen.
  3. High recursion stack usage in worst-case scenarios.

---

### 4.2 Merge Sort

#### 1. Definition & Working Principle
**Merge Sort** is a popular, stable, comparison-based sorting algorithm built on the **Divide-and-Conquer** strategy. It operates by recursively splitting the unsorted array into two equal halves until each sub-array contains only a single element, and then merging those sorted sub-arrays back together in sorted order.

#### 2. Three Algorithmic Steps
1. **Divide**: Calculate mid index $\text{mid} = \lfloor(low + high)/2\rfloor$ and divide the array $a[low \dots high]$ into two equal halves: $a[low \dots mid]$ and $a[mid+1 \dots high]$.
2. **Conquer**: Recursively apply Merge Sort to sort both halves independently.
3. **Merge**: Merge the two sorted sub-arrays into a single combined sorted array using an auxiliary array.

#### 3. Step-by-Step Dry Run Example
Sort the following array using Merge Sort:
$$\text{Array } a[] = \{70, 30, 50, 10\} \quad (low = 0, high = 3)$$

* **Phase 1: Recursive Division (Divide)**:
  * Initial Array: `[70, 30, 50, 10]` ($\text{mid} = 1$)
  * Split into Left: `[70, 30]` and Right: `[50, 10]`
  * Split Left `[70, 30]` ($\text{mid} = 0$) into `[70]` and `[30]`
  * Split Right `[50, 10]` ($\text{mid} = 2$) into `[50]` and `[10]`
  * Base case reached: Single elements `[70]`, `[30]`, `[50]`, `[10]` are trivially sorted.

* **Phase 2: Combination & Merging (Conquer & Merge)**:
  * Merge `[70]` and `[30]`: Compare $70$ and $30 \implies 30 < 70 \implies \text{Merged}: [30, 70]$
  * Merge `[50]` and `[10]`: Compare $50$ and $10 \implies 10 < 50 \implies \text{Merged}: [10, 50]$
  * Merge `[30, 70]` and `[10, 50]`:
    * Compare $a[0]$ (30) and $b[0]$ (10): $10 < 30 \implies \text{Result}: [10]$
    * Compare $a[0]$ (30) and $b[1]$ (50): $30 < 50 \implies \text{Result}: [10, 30]$
    * Compare $a[1]$ (70) and $b[1]$ (50): $50 < 70 \implies \text{Result}: [10, 30, 50]$
    * Append remaining element $a[1]$ (70) $\implies \text{Result}: [10, 30, 50, 70]$

* **Final Sorted Array**: `[10, 30, 50, 70]`

```
                 [ 70  30  50  10 ]           <-- Unsorted Array
                      /    \
                     /      \
            [ 70  30 ]      [ 50  10 ]        <-- Divide
             /     \          /     \
          [ 70 ]  [ 30 ]   [ 50 ]  [ 10 ]     <-- Base Case
             \     /          \     /
            [ 30  70 ]      [ 10  50 ]        <-- Merge
                     \      /
                      \    /
                 [ 10  30  50  70 ]           <-- Final Sorted Array
```

#### 4. Programming Implementation Concept & C Logic
Merge sort uses a recursive function `merge_sort(arr, low, high)` that computes `mid = (low + high) / 2`, calls `merge_sort` on `(low, mid)` and `(mid+1, high)`, and then calls `merge(arr, low, mid, high)`. The `merge` helper function uses three index pointers `i`, `j`, and `k` to merge elements into an auxiliary array `temp[]`, before copying them back to `arr[]`.

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n \log n)$
* **Average Case Time Complexity**: $O(n \log n)$
* **Worst Case Time Complexity**: $O(n \log n)$
  *(Note: Merge Sort guarantees $O(n \log n)$ time efficiency in all cases).*
* **Auxiliary Space Complexity**: $O(n)$ (requires additional array space to perform merging).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Guarantees consistent $O(n \log n)$ performance across best, average, and worst cases.
  2. Stable sorting algorithm.
  3. Highly effective for external sorting on large files stored in disk memory.
* **Disadvantages**:
  1. Requires $O(n)$ additional auxiliary memory space.
  2. Slower than Quick Sort for small, in-memory arrays due to array copy overhead.

---

## 5. Heap Sort & Heap Mechanics

### 5.1 Definition & Properties of Heap
**Heap Sort** is a comparison-based sorting algorithm that uses a specialized tree data structure called a **Heap**.

A **Heap** is defined as a **Complete Binary Tree** that satisfies the **Heap Property**:
* **Complete Binary Tree Definition**: A binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are filled as far left as possible.

#### Types of Heaps
1. **Max Heap**: A complete binary tree where the key value of every parent node is **greater than or equal to** the key values of its children:
   $$\text{Parent Key} \ge \text{Child Keys}$$
   *Property*: The largest element in a Max Heap is always located at the **Root Node**.
2. **Min Heap**: A complete binary tree where the key value of every parent node is **less than or equal to** the key values of its children:
   $$\text{Parent Key} \le \text{Child Keys}$$
   *Property*: The smallest element in a Min Heap is always located at the **Root Node**.

```
       Max Heap Example:                    Min Heap Example:
             (90)                                 (10)
            /    \                               /    \
          (70)   (60)                          (20)   (30)
          /  \                                 /  \
        (40) (50)                            (40) (50)
  Root (90) = Largest                 Root (10) = Smallest
```

### 5.2 Array Representation Formulae of a Heap
A complete binary tree can be represented sequentially in a 1D array without child/parent pointers. For any node located at 0-based array index $i$:
* **Parent Index Formula**: $\text{Parent}(i) = \lfloor (i - 1) / 2 \rfloor$
* **Left Child Index Formula**: $\text{Left Child}(i) = 2i + 1$
* **Right Child Index Formula**: $\text{Right Child}(i) = 2i + 2$

### 5.3 The Heapify Process
**Heapify** is the operation of adjusting a node and its children in a tree so that the subtree rooted at that node satisfies the Heap Property.

* **Working Logic for Max Heapify**:
  1. Given a parent node at index $i$, determine the indices of its left child ($2i+1$) and right child ($2i+2$).
  2. Find the largest key among the parent, left child, and right child.
  3. If the largest key is one of the children (not the parent), swap the parent with that child.
  4. Recursively call Heapify on the affected child node until the entire subtree satisfies the Max Heap property.

### 5.4 Building a Max Heap from an Unsorted Array
To transform an arbitrary unsorted array of size $n$ into a valid Max Heap:
1. **Formula for Last Non-Leaf Node**:
   $$\text{Last Non-Leaf Node Index} = \lfloor n / 2 \rfloor - 1$$
   *(All nodes from index $\lfloor n/2 \rfloor$ to $n-1$ are leaf nodes and already satisfy the heap property trivially).*
2. **Bottom-Up Heapification**: Iterate from the last non-leaf node index down to $0$, calling `Heapify()` on each node.

### 5.5 Two Main Phases of Heap Sort
1. **Phase 1 (Build Max Heap)**: Convert the unsorted array of size $n$ into a Max Heap.
2. **Phase 2 (Sorting Phase)**:
   * **Step 1**: Swap the root element (which contains the largest value) with the last element of the heap (at index $\text{heap\_size} - 1$).
   * **Step 2**: Reduce the active heap size by 1 ($\text{heap\_size} = \text{heap\_size} - 1$).
   * **Step 3**: Call `Heapify()` on the root node (index 0) to restore the Max Heap property among remaining elements.
   * **Step 4**: Repeat steps 1–3 until only one element remains in the heap.

### 5.6 Comprehensive Step-by-Step Dry Run Example
Sort the following unsorted array using Heap Sort in ascending order:
$$\text{Array } a[] = \{40, 30, 50, 20, 60, 10\} \quad (n = 6)$$

#### Phase 1: Build Max Heap
* **Step 1**: Calculate Last Non-Leaf Node Index: $\lfloor n/2 \rfloor - 1 = \lfloor 6/2 \rfloor - 1 = 2$.
  * Nodes to heapify: Index 2, Index 1, Index 0.
* **Initial Array Representation**: `[40, 30, 50, 20, 60, 10]`
  * Tree: Root `40`, Left Child `30` (children `20`, `60`), Right Child `50` (child `10`).

* **Heapify at Index 2** ($a[2] = 50$):
  * Children of index 2: Left child $2(2)+1 = 5 \implies a[5] = 10$. No right child.
  * Compare parent (50) and child (10): $50 > 10 \implies \text{Heap property holds, no swap}$.
  * *Array remains*: `[40, 30, 50, 20, 60, 10]`

* **Heapify at Index 1** ($a[1] = 30$):
  * Children of index 1: Left child $a[3] = 20$, Right child $a[4] = 60$.
  * Largest among $\{30, 20, 60\}$ is $60$ at index 4.
  * Swap $a[1]$ (30) and $a[4]$ (60).
  * *Array becomes*: `[40, 60, 50, 20, 30, 10]`

* **Heapify at Index 0** ($a[0] = 40$):
  * Children of index 0: Left child $a[1] = 60$, Right child $a[2] = 50$.
  * Largest among $\{40, 60, 50\}$ is $60$ at index 1.
  * Swap $a[0]$ (40) and $a[1]$ (60).
  * *Array becomes*: `[60, 40, 50, 20, 30, 10]`
  * *Recursive Heapify at affected Index 1* ($a[1] = 40$):
    * Children of index 1: Left child $a[3] = 20$, Right child $a[4] = 30$.
    * Parent 40 is greater than both children 20 and 30 $\implies \text{No swap}$.

* **Final Max Heap Built**: `[60, 40, 50, 20, 30, 10]`

```
          Max Heap Built:
               (60)
              /    \
            (40)   (50)
            /  \   /
          (20)(30)(10)
```

#### Phase 2: Heap Sort Passes
* **Pass 1** ($\text{heap\_size} = 6$):
  * Swap root $a[0]$ (60) with last element $a[5]$ (10).
  * Array: `[10, 40, 50, 20, 30 | 60]` (Sorted: `[60]`). Reduce $\text{heap\_size} = 5$.
  * *Heapify Root (10)*: Children $a[1]=40, a[2]=50$. Largest is 50. Swap $a[0]$ (10) & $a[2]$ (50).
  * Array becomes: `[50, 40, 10, 20, 30 | 60]`

* **Pass 2** ($\text{heap\_size} = 5$):
  * Swap root $a[0]$ (50) with last active element $a[4]$ (30).
  * Array: `[30, 40, 10, 20 | 50, 60]` (Sorted: `[50, 60]`). Reduce $\text{heap\_size} = 4$.
  * *Heapify Root (30)*: Children $a[1]=40, a[2]=10$. Largest is 40. Swap $a[0]$ (30) & $a[1]$ (40).
  * Array becomes: `[40, 30, 10, 20 | 50, 60]`

* **Pass 3** ($\text{heap\_size} = 4$):
  * Swap root $a[0]$ (40) with last active element $a[3]$ (20).
  * Array: `[20, 30, 10 | 40, 50, 60]` (Sorted: `[40, 50, 60]`). Reduce $\text{heap\_size} = 3$.
  * *Heapify Root (20)*: Children $a[1]=30, a[2]=10$. Largest is 30. Swap $a[0]$ (20) & $a[1]$ (30).
  * Array becomes: `[30, 20, 10 | 40, 50, 60]`

* **Pass 4** ($\text{heap\_size} = 3$):
  * Swap root $a[0]$ (30) with last active element $a[2]$ (10).
  * Array: `[10, 20 | 30, 40, 50, 60]`. Reduce $\text{heap\_size} = 2$.
  * *Heapify Root (10)*: Children $a[1]=20$. Swap $a[0]$ (10) & $a[1]$ (20).
  * Array becomes: `[20, 10 | 30, 40, 50, 60]`

* **Pass 5** ($\text{heap\_size} = 2$):
  * Swap root $a[0]$ (20) with last active element $a[1]$ (10).
  * Array: `[10 | 20, 30, 40, 50, 60]`. Reduce $\text{heap\_size} = 1 \implies \text{Done}$.

* **Final Ascending Sorted Array**: `[10, 20, 30, 40, 50, 60]`

#### 5. Complexity Analysis
* **Best Case Time Complexity**: $O(n \log n)$
* **Average Case Time Complexity**: $O(n \log n)$
* **Worst Case Time Complexity**: $O(n \log n)$
* **Auxiliary Space Complexity**: $O(1)$ (in-place).

#### 6. Advantages & Disadvantages
* **Advantages**:
  1. Guarantees optimal $O(n \log n)$ time complexity in all cases.
  2. In-place algorithm requiring $O(1)$ auxiliary space.
* **Disadvantages**:
  1. Unstable sorting algorithm.
  2. Substantial array cache misses due to non-contiguous array access jumps ($2i+1, 2i+2$).

---

## 6. Performance Comparison of Sorting Algorithms

The following comprehensive table synthesizes the operational, time, and space parameters across all six sorting algorithms covered in the curriculum:

| Algorithm | Best Time | Average Time | Worst Time | Space Complexity | Stable? | In-Place? | Suitable for Large Data? | Primary Technique Used |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes | No | Adjacent Element Swapping |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | No | Yes | No | Minimum Selection & Placement |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes | No | Key Insertion into Sorted Sub-array |
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | No | Yes | Yes | Divide & Conquer (Pivot Partitioning) |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes | No | Yes | Divide & Conquer (Recursive Merging) |
| **Heap Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | No | Yes | Yes | Complete Binary Tree (Max Heap) |

---

## 7. Hashing Fundamentals & Hash Functions

### 7.1 Definition & Motivation
**Hashing** is a technique used to store and retrieve data in record time. While searching algorithms such as Linear Search ($O(n)$) or Binary Search ($O(\log n)$) depend on sequential comparisons, Hashing calculates the exact location (index) where data should be stored using a **Hash Function**.

This enables searching, insertion, and deletion operations to execute in **constant average time $O(1)$**.

#### Real-World Analogy
Imagine a library containing 1,000 books. If you wish to locate Book Number 820 without an index system, you might have to check books sequentially from 1 to 820 (very slow). 

With **Hashing**: Suppose every book is assigned directly to a shelf matching its book number. Book 820 is placed directly on Shelf 820. You can walk straight to Shelf 820 and pick up the book instantly without searching other shelves.

### 7.2 Core Terminology of Hashing
1. **Key**: The unique input value used to identify a data item (e.g., `roll_no = 25`, `emp_id = 108`).
2. **Hash Function**: A mathematical formula $h(\text{key})$ that transforms a large key value into a valid hash table index.
   $$\text{Example Hash Function: } h(\text{key}) = \text{key} \pmod{\text{table\_size}}$$
3. **Hash Table**: A fixed-size array structure used to store data records according to the indices generated by the hash function.
4. **Hash Value (Index)**: The integer array index produced by evaluating $h(\text{key})$.

#### Basic Hashing Calculation Example
Let $\text{table\_size} = 10$ and $h(\text{key}) = \text{key} \pmod{10}$:
* Given $\text{key} = 25$:
  $$h(25) = 25 \pmod{10} = 5 \implies \text{Store key 25 at index 5}$$

### 7.3 Step-by-Step Hashing Execution Trace
Insert keys `25, 36, 17, 48` into a Hash Table of size 10 using $h(\text{key}) = \text{key} \pmod{10}$:

1. **Insert 25**: $h(25) = 25 \pmod{10} = 5$. Store 25 at Index 5.
2. **Insert 36**: $h(36) = 36 \pmod{10} = 6$. Store 36 at Index 6.
3. **Insert 17**: $h(17) = 17 \pmod{10} = 7$. Store 17 at Index 7.
4. **Insert 48**: $h(48) = 48 \pmod{10} = 8$. Store 48 at Index 8.

**Final Hash Table State**:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Value** | — | — | — | — | — | **25** | **36** | **17** | **48** | — |

Searching for key `17` evaluates $h(17) = 7$, jumping directly to Index 7 in $O(1)$ time.

---

## 8. Collision Resolution Techniques

### 8.1 Definition of Collision
A **Collision** occurs when two or more distinct keys produce the exact same hash value (index) when passed through a hash function.

#### Collision Example
Let $\text{table\_size} = 10$ and $h(\text{key}) = \text{key} \pmod{10}$.
* Insert Key 25: $h(25) = 25 \pmod{10} = 5$.
* Insert Key 35: $h(35) = 35 \pmod{10} = 5$.

Both keys (25 and 35) map to Index 5. Since Index 5 can hold only one element in a basic array, a **collision** occurs.

```
       Key 25 ---> [ Hash Function: key % 10 ] ---> Index 5  \
                                                              ===> COLLISION AT INDEX 5!
       Key 35 ---> [ Hash Function: key % 10 ] ---> Index 5  /
```

### 8.2 Classification of Collision Resolution Strategies
There are two primary paradigms for resolving hash collisions:

```
               Collision Resolution Techniques
                              │
         ┌────────────────────┴────────────────────┐
         ▼                                         ▼
1. Separate Chaining                     2. Open Addressing
   (Open Hashing)                           (Closed Hashing)
   [Linked Lists Outside Table]             [Search Free Slot Inside Table]
                                                   │
                                ┌──────────────────┼──────────────────┐
                                ▼                  ▼                  ▼
                         Linear Probing    Quadratic Probing    Double Hashing
```

---

### 8.3 Separate Chaining (Open Hashing)

#### 1. Concept & Working Principle
In **Separate Chaining (Open Hashing)**, the hash table array slots do not store data directly; instead, each table slot acts as the `head` pointer of a Singly Linked List. When multiple keys map to the same hash index, they are appended as nodes in that slot's linked list outside the main hash table array.

#### 2. Visual Representation
Insert keys `25, 35, 45` with $h(\text{key}) = \text{key} \pmod{10}$:
* Index 5: `[Head] -> [25] -> [35] -> [45] -> NULL`

#### 3. Advantages & Disadvantages
* **Advantages**:
  1. Simple to implement using dynamic linked list allocation.
  2. The hash table never fills up completely; it can handle more elements than the table size.
  3. Deletion is easy (standard linked list node deletion).
* **Disadvantages**:
  1. Requires extra memory overhead for pointers (`next` node pointers).
  2. If many keys hash to the same index, the linked list grows long and search performance degrades from $O(1)$ to $O(n)$.

---

### 8.4 Open Addressing (Closed Hashing)

#### 1. Concept & Working Principle
In **Open Addressing (Closed Hashing)**, all elements are stored directly inside the hash table array itself. If a collision occurs at index $h(\text{key})$, the algorithm probes (searches) through alternative slots inside the array until an empty position is found.

#### 2. Probing Strategies

##### A. Linear Probing
* **Probing Rule**: Searches sequentially for the next immediate free slot ($i = 0, 1, 2, \dots$):
  $$h(\text{key}, i) = (\text{hash}(\text{key}) + i) \pmod{\text{table\_size}}$$
* **Drawback**: Suffers from **Primary Clustering** (long continuous blocks of occupied slots build up, increasing search times).

##### B. Quadratic Probing
* **Probing Rule**: Searches slots using quadratic steps ($i^2$):
  $$h(\text{key}, i) = (\text{hash}(\text{key}) + c_1 \cdot i + c_2 \cdot i^2) \pmod{\text{table\_size}}$$
* **Advantage**: Eliminates primary clustering by jumping across slots quadratic distances ($1, 4, 9, 16 \dots$).

##### C. Double Hashing
* **Probing Rule**: Uses a second independent hash function $h_2(\text{key})$ to compute variable probe step sizes:
  $$h(\text{key}, i) = (h_1(\text{key}) + i \cdot h_2(\text{key})) \pmod{\text{table\_size}}$$
* **Advantage**: Completely eliminates both primary and secondary clustering.

---

### 8.5 Comparison: Open Hashing vs. Closed Hashing

The following table contrasts the structural and operational features of Open Hashing and Closed Hashing:

| Parameter | Open Hashing (Separate Chaining) | Closed Hashing (Open Addressing) |
| :--- | :--- | :--- |
| **Storage Location** | Colliding elements are stored outside the hash table in linked lists. | All elements are stored inside the hash table array itself. |
| **Memory Overhead** | Requires extra memory for list node pointers. | Requires less memory overhead (no pointers needed). |
| **Table Capacity Limit** | Table can store more elements than its physical array size $N$. | Table can store at most $N$ elements (limited by array size). |
| **Deletion Operation** | Simple; involves unlinking a node from a linked list. | Complex; requires deleted slots to be marked with dummy markers. |
| **Techniques Used** | Separate Chaining using Singly Linked Lists. | Linear Probing, Quadratic Probing, Double Hashing. |
| **Performance Impact** | Degrades gracefully when overloaded. | Degrades sharply when table load factor exceeds 70%. |

---

## 9. Important Definitions

1. **Sorting**: The process of arranging a collection of data elements in a specific sequential order (ascending or descending).
2. **Internal Sorting**: Sorting techniques performed entirely within main memory (RAM) for small datasets.
3. **External Sorting**: Sorting techniques designed for massive datasets stored in secondary memory (hard disk) that cannot fit in RAM.
4. **Stable Sorting**: A sorting algorithm property where the relative order of equal key elements is preserved after sorting.
5. **In-Place Sorting**: A sorting algorithm that requires $O(1)$ auxiliary memory space beyond the input array.
6. **Pivot**: A selected reference element in Quick Sort used to partition an array into lower and higher sub-arrays.
7. **Heap**: A complete binary tree structure that satisfies either the Max Heap ($Parent \ge Child$) or Min Heap ($Parent \le Child$) property.
8. **Heapify**: The process of rearranging a complete binary tree node and its subtrees to satisfy the Heap Property.
9. **Hashing**: A data lookup technique that maps keys to array indices using a mathematical formula to achieve $O(1)$ average search time.
10. **Hash Function**: A mathematical function $h(\text{key})$ that maps a key value to a valid index in a hash table.
11. **Collision**: An event where two or more distinct keys evaluate to the exact same index in a hash table.
12. **Separate Chaining**: A collision resolution technique where colliding records are stored in a linked list attached to the hash table slot.

---

## 10. Programming Questions

The following programming assignments convert C implementation requirements into structured questions mapped to individual `.c` source files:

1. **Programming Question**: Write a C program to implement **Bubble Sort**. Read an array of $n$ integers from the user, display the unsorted array, sort the elements in ascending order, and print the final sorted array.
   * **Separate C File**: `Bubble_Sort.c`
   * **Key Logic**: Dual nested loops `for(i=0; i<n-1; i++)` and `for(j=0; j<n-i-1; j++)` with conditional swap `if(a[j] > a[j+1])`.

2. **Programming Question**: Write a C program to implement **Selection Sort**. Find the minimum element in each pass and swap it with the element at the beginning of the unsorted sub-array.
   * **Separate C File**: `Selection_Sort.c`
   * **Key Logic**: Outer loop `i`, inner loop `j` from `i+1` to `n-1` updating `min_idx`, and swapping `a[i]` with `a[min_idx]`.

3. **Programming Question**: Write a C program to implement **Insertion Sort**. Insert each key element into its correct position within the sorted sub-array.
   * **Separate C File**: `Insertion_Sort.c`
   * **Key Logic**: Store `key = a[i]`, shift elements using `while(j>=0 && a[j]>key) a[j+1] = a[j]`, and insert `a[j+1] = key`.

4. **Programming Question**: Write a C program to implement **Quick Sort** using the divide-and-conquer strategy. Choose the first element as pivot, partition the array, and recursively sort sub-arrays.
   * **Separate C File**: `Quick_Sort.c`
   * **Key Logic**: Recursive `quick_sort(arr, low, high)`, pointers `a = low + 1`, `b = high`, swapping `a[a]` and `a[b]` while $a < b$, and swapping pivot with `a[b]` when $a \ge b$.

5. **Programming Question**: Write a C program to implement **Merge Sort**. Divide the array into equal halves recursively and merge the sorted sub-arrays using an auxiliary array.
   * **Separate C File**: `Merge_Sort.c`
   * **Key Logic**: Recursive `merge_sort(arr, low, high)`, `mid = (low+high)/2`, and `merge()` helper function using two pointers merging into `temp[]`.

6. **Programming Question**: Write a C program to implement **Heap Sort**. Construct a Max Heap from an input array using `heapify()` and perform heap sort by repeatedly swapping root with the last element.
   * **Separate C File**: `Heap_Sort.c`
   * **Key Logic**: Bottom-up heap construction from `(n/2)-1` down to 0, followed by loop swapping `a[0]` with `a[i]` and calling `heapify(a, i, 0)`.

---

## 11. Short Answer Questions (2 Marks)

### Q1. Differentiate between Internal and External Sorting.
**Answer**:
* **Internal Sorting**: Occurs entirely in primary memory (RAM) when the dataset is small enough to fit in memory (e.g., Quick Sort, Insertion Sort).
* **External Sorting**: Used for huge datasets stored on secondary storage (hard disks) that cannot fit in RAM at once (e.g., External Merge Sort).

### Q2. What is a Stable Sorting algorithm? Give two examples.
**Answer**:
A sorting algorithm is **stable** if it preserves the relative order of duplicate elements present in the original input array.
* *Examples*: Insertion Sort and Merge Sort are stable sorting algorithms.

### Q3. Why is Quick Sort's worst-case time complexity $O(n^2)$?
**Answer**:
Quick Sort degenerates to $O(n^2)$ when the chosen pivot element is consistently the smallest or largest element (e.g., when the array is already sorted and the first element is selected as pivot), resulting in unbalanced partitions of size $0$ and $n-1$.

### Q4. Define Complete Binary Tree and state its importance in Heap Sort.
**Answer**:
A **Complete Binary Tree** is a binary tree where all levels except possibly the last are fully filled, and all nodes in the last level are filled from left to right. Heap Sort uses complete binary trees because they can be represented sequentially in an array without pointer overhead using indexing formulas $2i+1$ and $2i+2$.

### Q5. What is a Hash Function? State the division hash function formula.
**Answer**:
A **Hash Function** is a mathematical algorithm $h(\text{key})$ that maps a large key value to a valid array index in a Hash Table. The Division Method formula is:
$$h(\text{key}) = \text{key} \pmod{\text{table\_size}}$$

### Q6. Define Collision in Hashing.
**Answer**:
A **Collision** occurs when two distinct keys evaluate to the exact same hash value or index when processed by a hash function ($h(k_1) = h(k_2)$ for $k_1 \neq k_2$).

---

## 12. Medium Answer Questions (4 Marks)

### Q1. Trace Insertion Sort on the array `[25, 12, 20, 15, 30]` step by step.
**Answer**:
* **Pass 1** ($key = 12$): Compare $key$ 12 with 25. Shift 25 right $\implies$ Array: `[12, 25, 20, 15, 30]`.
* **Pass 2** ($key = 20$): Compare 20 with 25. Shift 25 right. Compare 20 with 12 (no shift) $\implies$ Insert 20 $\implies$ Array: `[12, 20, 25, 15, 30]`.
* **Pass 3** ($key = 15$): Compare 15 with 25 (shift 25), compare 15 with 20 (shift 20), compare 15 with 12 (stop) $\implies$ Insert 15 $\implies$ Array: `[12, 15, 20, 25, 30]`.
* **Pass 4** ($key = 30$): Compare 30 with 25 (no shift) $\implies$ Array: `[12, 15, 20, 25, 30]`.
* **Final Sorted Array**: `[12, 15, 20, 25, 30]`.

### Q2. Explain the Quick Sort algorithm partitioning logic when taking the first element as pivot.
**Answer**:
1. Select $P = a[low]$ as the pivot element. Initialize left pointer $a = low + 1$ and right pointer $b = high$.
2. Increment $a$ while $a[a] \le P$. Decrement $b$ while $a[b] > P$.
3. If $a < b$, swap $a[a]$ and $a[b]$ and continue moving pointers.
4. If $a \ge b$ (pointers have crossed), stop moving pointers and swap pivot $a[low]$ with $a[b]$.
5. Return index $b$ as the partition boundary separating lower and higher sub-arrays.

### Q3. Describe the Heapify algorithm and show how to calculate parent and child indices in an array representation.
**Answer**:
* **Heapify Algorithm**:
  1. For a node at index $i$, determine left child $L = 2i+1$ and right child $R = 2i+2$.
  2. Identify the index `largest` holding the maximum value among $a[i]$, $a[L]$, and $a[R]$.
  3. If `largest` $\neq i$, swap $a[i]$ with $a[\text{largest}]$ and call `Heapify(a, largest)` recursively.
* **Array Indexing Formulas**:
  * $\text{Parent Index} = \lfloor (i - 1) / 2 \rfloor$
  * $\text{Left Child Index} = 2i + 1$
  * $\text{Right Child Index} = 2i + 2$

### Q4. Explain Separate Chaining (Open Hashing) with a neat diagram and example.
**Answer**:
* **Explanation**: In Separate Chaining, each slot of the hash table acts as the head of a singly linked list. When a collision occurs, the colliding key is inserted into the linked list at that hash index outside the table.
* **Example**: Insert keys `25, 35` into table size 10 using $h(k) = k \pmod{10}$.
  * $h(25) = 5$, $h(35) = 5$.
  * Both map to Index 5.
* **Diagram**:
  ```
  Index 0 -> NULL
  ...
  Index 5 -> [ 25 | * ] -> [ 35 | NULL ]
  ```

---

## 13. Long Answer Questions

### Q1. Explain Heap Sort in detail. Build a Max Heap and trace Heap Sort for the array `[40, 30, 50, 20, 60, 10]`.
**Answer**:
* **Theoretical Explanation**: Heap Sort converts an unsorted array into a Max Heap (a complete binary tree where parent $\ge$ children). It repeatedly swaps the root element (maximum value) with the last element of the heap, reduces heap size by 1, and heapifies the root to restore the Max Heap property.
* **Phase 1: Build Max Heap**:
  * Array: `[40, 30, 50, 20, 60, 10]` ($n=6$). Last non-leaf node $= \lfloor 6/2 \rfloor - 1 = 2$.
  * Heapify index 2 ($50$): Children $10 \implies$ No swap.
  * Heapify index 1 ($30$): Children $20, 60 \implies$ Swap 30 and 60. Array: `[40, 60, 50, 20, 30, 10]`.
  * Heapify index 0 ($40$): Children $60, 50 \implies$ Swap 40 and 60. Array: `[60, 40, 50, 20, 30, 10]`.
  * Max Heap Built: `[60, 40, 50, 20, 30, 10]`.
* **Phase 2: Sorting Passes**:
  * Pass 1: Swap root 60 with $a[5]$ (10) $\implies$ Array: `[10, 40, 50, 20, 30 | 60]`. Heapify root $10 \implies$ Array: `[50, 40, 10, 20, 30 | 60]`.
  * Pass 2: Swap root 50 with $a[4]$ (30) $\implies$ Array: `[30, 40, 10, 20 | 50, 60]`. Heapify root $30 \implies$ Array: `[40, 30, 10, 20 | 50, 60]`.
  * Pass 3: Swap root 40 with $a[3]$ (20) $\implies$ Array: `[20, 30, 10 | 40, 50, 60]`. Heapify root $20 \implies$ Array: `[30, 20, 10 | 40, 50, 60]`.
  * Pass 4: Swap root 30 with $a[2]$ (10) $\implies$ Array: `[10, 20 | 30, 40, 50, 60]`. Heapify root $10 \implies$ Array: `[20, 10 | 30, 40, 50, 60]`.
  * Pass 5: Swap root 20 with $a[1]$ (10) $\implies$ Array: `[10 | 20, 30, 40, 50, 60]`.
* **Final Sorted Array**: `[10, 20, 30, 40, 50, 60]`.

### Q2. Compare all 6 sorting algorithms across time complexity, space complexity, stability, and sorting techniques.
**Answer**:
Refer to the comprehensive performance comparison table in **Section 6** detailing Bubble, Selection, Insertion, Quick, Merge, and Heap Sort across Best/Average/Worst time complexity, space complexity, stability, in-place behavior, and underlying techniques.

### Q3. Explain Hashing, Hash Functions, Collisions, Open Addressing (Linear Probing, Quadratic Probing, Double Hashing), and Open Hashing in detail.
**Answer**:
Refer to **Section 7** and **Section 8** for full theoretical definitions, library bookshelf analogy, mathematical formulas, collision resolution techniques, probing formulas, and the detailed comparison table between Open Hashing and Closed Hashing.

---

## 14. Chapter Summary and Key Points

* **Sorting Classification**: Internal sorting operates in RAM ($O(1)$ to $O(n)$ extra space), while External sorting handles massive files in secondary storage (hard disk).
* **Elementary Sorting**: Bubble, Selection, and Insertion Sort have $O(n^2)$ average time complexity. Insertion sort is adaptive ($O(n)$ best case for nearly sorted data).
* **Divide & Conquer Sorting**: Quick Sort and Merge Sort achieve $O(n \log n)$ average efficiency. Merge Sort guarantees $O(n \log n)$ worst-case time but requires $O(n)$ extra memory. Quick Sort is in-place ($O(\log n)$ stack) but has $O(n^2)$ worst-case time.
* **Heap Sort**: Uses a Complete Binary Tree (Max Heap) represented as an array via $2i+1$ and $2i+2$. Guarantees $O(n \log n)$ time and $O(1)$ space in all cases.
* **Hashing**: Maps keys to array indices via $h(\text{key}) = \text{key} \pmod m$ to enable average constant time $O(1)$ lookups.
* **Collision Resolution**: Separate Chaining (Open Hashing) uses linked lists outside the table. Open Addressing (Closed Hashing) probes within the table using Linear Probing, Quadratic Probing, or Double Hashing.

# Program 03: Insertion Sort

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement Insertion Sort in C++ to arrange a sequence of $N$ integers in ascending order. Understand its adaptive behavior on pre-sorted arrays and its shifting mechanism.

---

## 2. Approach
Insertion Sort mimics the way people sort playing cards in their hands:
1. Assume the first element (`arr[0]`) is sorted.
2. For each element `key = arr[i]` from $i = 1$ to $N - 1$:
   - Compare `key` with elements in the sorted subarray `arr[0...i-1]` from right to left.
   - Shift elements greater than `key` one position to the right.
   - Place `key` into its correct sorted insertion slot.
3. **Adaptive Advantage:** If the input array is already sorted, only 1 comparison is made per element and 0 shifts occur, yielding $O(N)$ running time.

---

## 3. Algorithm & Pseudocode

```text
FUNCTION InsertionSort(arr, N):
    FOR i = 1 TO N - 1 DO:
        key = arr[i]
        j = i - 1
        WHILE j >= 0 AND arr[j] > key DO:
            arr[j + 1] = arr[j] // Shift rightward
            j = j - 1
        END WHILE
        arr[j + 1] = key
    END FOR
END FUNCTION
```

---

## 4. Dry Run Trace
Input: `[12, 11, 13, 5, 6]` ($N = 5$)

| Step $i$ | Key | Comparisons & Shifts | Resulting Subarray `arr[0...i]` | Full Array State |
| :--- | :--- | :--- | :--- | :--- |
| **Initial** | — | — | `[12]` | `[12, 11, 13, 5, 6]` |
| **$i = 1$** | $11$ | $12 > 11 \rightarrow$ Shift $12$ right; Insert $11$ at idx 0 | `[11, 12]` | `[11, 12, 13, 5, 6]` |
| **$i = 2$** | $13$ | $12 < 13 \rightarrow$ No shift; Insert $13$ at idx 2 | `[11, 12, 13]` | `[11, 12, 13, 5, 6]` |
| **$i = 3$** | $5$ | Shift $13, 12, 11$ right; Insert $5$ at idx 0 | `[5, 11, 12, 13]` | `[5, 11, 12, 13, 6]` |
| **$i = 4$** | $6$ | Shift $13, 12, 11$ right; Insert $6$ at idx 1 | `[5, 6, 11, 12, 13]` | `[5, 6, 11, 12, 13]` |

---

## 5. Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case Time** | $O(N)$ | Array already sorted. Only 1 comparison per key, 0 shifts ($N-1$ total comparisons). |
| **Average Case Time** | $O(N^2)$ | Elements are shifted on average halfway across the sorted prefix ($N^2/4$ operations). |
| **Worst Case Time** | $O(N^2)$ | Array in reverse order. Every element shifted to beginning ($N(N-1)/2$ shifts). |
| **Auxiliary Space** | $O(1)$ | Strictly in-place using scalar variables (`key`, `i`, `j`). |
| **Stability** | Stable | Elements equal to `key` are not shifted; `key` is placed immediately after duplicates. |

---

## 6. Real-Life Application
- **Online Streaming Data Sorting:** Sorting streaming sensor data or transaction events arriving in real-time, where items arrive nearly in chronological order.
- **Hybrid Sorting Algorithms:** Used as the base-case sorter in industrial algorithms like **Timsort** (Python/Java default) and **Introsort** (C++ `std::sort`) when sub-arrays shrink to $N \le 16$ or $32$.

---

## 7. Sample Input & Output
```text
Initial Array: [ 12 11 13 5 6 ]

--- Execution Trace ---
Step 1 [Inserting Key = 11]: [ 11 12 13 5 6 ]
Step 2 [Inserting Key = 13]: [ 11 12 13 5 6 ]
Step 3 [Inserting Key = 5]: [ 5 11 12 13 6 ]
Step 4 [Inserting Key = 6]: [ 5 6 11 12 13 ]

[Metrics] Total Comparisons: 9 | Total Shifts: 7

Final Sorted Array: [ 5 6 11 12 13 ]
```

---

## 8. Learning Outcomes
1. Mastered the insertion mechanism via element shifting rather than multiple adjacent swaps.
2. Understood why Insertion Sort is the fastest algorithm in practice for small ($N \le 30$) or nearly-sorted datasets.

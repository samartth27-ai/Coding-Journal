# Program 02: Selection Sort

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement the Selection Sort algorithm in C++ to arrange a sequence of $N$ integers in non-decreasing order. Analyze its swap count and comparison properties.

---

## 2. Approach
Selection Sort divides the array into two segments: sorted (left) and unsorted (right).
1. In each pass $i$ (from $0$ to $N-2$), identify the index of the minimum element in the unsorted subarray `arr[i...N-1]`.
2. Swap this minimum element with `arr[i]`.
3. The boundary between sorted and unsorted subarrays moves one position to the right after each iteration.
4. **Key Advantage:** Selection sort performs at most $O(N)$ swaps, which is optimal when write operations are significantly more expensive than read operations.

---

## 3. Algorithm & Pseudocode

```text
FUNCTION SelectionSort(arr, N):
    FOR i = 0 TO N - 2 DO:
        minIdx = i
        FOR j = i + 1 TO N - 1 DO:
            IF arr[j] < arr[minIdx] THEN:
                minIdx = j
            END IF
        END FOR
        IF minIdx != i THEN:
            SWAP(arr[i], arr[minIdx])
        END IF
    END FOR
END FUNCTION
```

---

## 4. Dry Run Trace
Given input: `[29, 10, 14, 37, 13]` ($N = 5$)

| Pass $i$ | Search Range `[i...4]` | Minimum Element Found | Swap $(arr[i], arr[minIdx])$ | Resulting Array |
| :--- | :--- | :--- | :--- | :--- |
| **Pass 1 ($i=0$)** | `[29, 10, 14, 37, 13]` | $10$ (at idx 1) | Swap $29 \leftrightarrow 10$ | `[10, 29, 14, 37, 13]` |
| **Pass 2 ($i=1$)** | `[29, 14, 37, 13]` | $13$ (at idx 4) | Swap $29 \leftrightarrow 13$ | `[10, 13, 14, 37, 29]` |
| **Pass 3 ($i=2$)** | `[14, 37, 29]` | $14$ (at idx 2) | No swap ($minIdx == i$) | `[10, 13, 14, 37, 29]` |
| **Pass 4 ($i=3$)** | `[37, 29]` | $29$ (at idx 4) | Swap $37 \leftrightarrow 29$ | `[10, 13, 14, 29, 37]` |

---

## 5. Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case Time** | $O(N^2)$ | Still performs $N(N-1)/2$ comparisons even if already sorted. |
| **Average Case Time** | $O(N^2)$ | Always executes nested loops regardless of initial ordering. |
| **Worst Case Time** | $O(N^2)$ | $N(N-1)/2$ comparisons. |
| **Auxiliary Space** | $O(1)$ | Operates strictly in-place with integer index tracking. |
| **Number of Swaps** | $O(N)$ | At most $N-1$ swaps, unlike Bubble Sort ($O(N^2)$ swaps). |
| **Stability** | Unstable | Long-distance swaps can reorder identical elements. |

---

## 6. Real-Life Application
- **Flash / EEPROM Memory Management:** Solid-state flash memory devices have limited write endurance cycles. Because Selection Sort guarantees at most $N-1$ swaps (writes), it is preferable over algorithms with high write frequencies when write operations degrade hardware lifespan.

---

## 7. Sample Input & Output
```text
Initial Array: [ 29 10 14 37 13 ]

--- Execution Trace ---
Pass 1 [Selected Min: 10 at index 1]: [ 10 29 14 37 13 ]
Pass 2 [Selected Min: 13 at index 4]: [ 10 13 14 37 29 ]
Pass 3 [Selected Min: 14 at index 2]: [ 10 13 14 37 29 ]
Pass 4 [Selected Min: 29 at index 4]: [ 10 13 14 29 37 ]

[Metrics] Total Comparisons: 10 | Total Swaps: 3

Final Sorted Array: [ 10 13 14 29 37 ]
```

---

## 8. Learning Outcomes
1. Evaluated the trade-off between total comparisons ($O(N^2)$) versus total memory writes ($O(N)$).
2. Analyzed why Selection Sort is inherently unstable due to long-range element exchanges.

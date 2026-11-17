# Program 01: Bubble Sort (Optimized)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement the Bubble Sort algorithm in C++ to arrange a sequence of $N$ integers in ascending order. Incorporate an early-termination optimization to achieve linear time complexity $O(N)$ when the input is already sorted or nearly sorted.

---

## 2. Approach
Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 
- In each pass $i$ (from $0$ to $N-2$), the largest element among the unsorted prefix bubbles up to its correct position at the end ($N-1-i$).
- **Optimization:** A boolean flag `swapped` is maintained. If an entire pass completes without any swaps, the array is already sorted, and execution terminates immediately.

---

## 3. Algorithm & Pseudocode

### Pseudocode
```text
FUNCTION BubbleSort(arr, N):
    FOR i = 0 TO N - 2 DO:
        swapped = FALSE
        FOR j = 0 TO N - i - 2 DO:
            IF arr[j] > arr[j + 1] THEN:
                SWAP(arr[j], arr[j + 1])
                swapped = TRUE
            END IF
        END FOR
        IF swapped == FALSE THEN:
            BREAK // Early termination
        END IF
    END FOR
END FUNCTION
```

---

## 4. Dry Run Trace
Given input: `[64, 34, 25, 12]` ($N = 4$)

| Pass | Pair $(j, j+1)$ | Values | Condition $(arr[j] > arr[j+1])$ | Action | Array State |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Pass 1** | $(0, 1)$ | $64 > 34$ | True | Swap | `[34, 64, 25, 12]` |
| | $(1, 2)$ | $64 > 25$ | True | Swap | `[34, 25, 64, 12]` |
| | $(2, 3)$ | $64 > 12$ | True | Swap | `[34, 25, 12, 64]` (64 placed) |
| **Pass 2** | $(0, 1)$ | $34 > 25$ | True | Swap | `[25, 34, 12, 64]` |
| | $(1, 2)$ | $34 > 12$ | True | Swap | `[25, 12, 34, 64]` (34 placed) |
| **Pass 3** | $(0, 1)$ | $25 > 12$ | True | Swap | `[12, 25, 34, 64]` (Sorted) |

---

## 5. Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case Time** | $O(N)$ | Occurs when the input is already sorted; exits after 1 pass ($N-1$ comparisons, 0 swaps). |
| **Average Case Time** | $O(N^2)$ | On average, $N(N-1)/4$ comparisons and swaps occur. |
| **Worst Case Time** | $O(N^2)$ | Occurs when the array is in reverse order; requires $N(N-1)/2$ comparisons and swaps. |
| **Auxiliary Space** | $O(1)$ | In-place sorting; only a few scalar variables (`i`, `j`, `swapped`). |
| **Stability** | Stable | Does not swap equal elements ($arr[j] > arr[j+1]$ strict inequality preserves original relative order). |

---

## 6. Real-Life Application
- **Detecting Nearly-Sorted Data:** Checking if an incoming batch of timestamped log events or sensor readings is already sorted with minimal overhead.
- **Embedded Microcontrollers:** Simple implementation with minimal instruction footprint and zero dynamic memory allocation overhead.

---

## 7. Sample Input & Output
```text
Test Case 1: Unsorted Array
Initial: [ 64 34 25 12 22 11 90 ]
--- Pass 1 ---
[ 34 25 12 22 11 64 90 ]
--- Pass 2 ---
[ 25 12 22 11 34 64 90 ]
...
Sorted Result: [ 11 12 22 25 34 64 90 ]

Test Case 2: Best-Case Already Sorted Array
Initial: [ 10 20 30 40 50 ]
--- Pass 1 ---
[ 10 20 30 40 50 ]
Early exit triggered at Pass 1 (Array is already sorted).
Sorted Result: [ 10 20 30 40 50 ]
```

---

## 8. Learning Outcomes
1. Understood adjacent comparison and in-place swapping mechanics.
2. Implemented the early termination flag optimization to reduce best-case time from $O(N^2)$ to $O(N)$.
3. Observed how stable sorting preserves relative ordering of duplicate keys.

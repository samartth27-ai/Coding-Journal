# Program 04: Merge Sort

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement the Merge Sort algorithm using C++ following the Divide-and-Conquer paradigm. Analyze its recurrence relation, recursive tree depth, and auxiliary space usage.

---

## 2. Approach
Merge Sort operates in three phases:
1. **Divide:** Find the midpoint `mid = left + (right - left) / 2` and divide the problem into two subproblems of size $N/2$.
2. **Conquer:** Recursively sort each subarray until the base case ($left \ge right$, a single element) is reached.
3. **Combine (Merge):** Merge two sorted adjacent subarrays `L` and `R` back into the main array in sorted order by comparing leading elements.

---

## 3. Algorithm & Recurrence Relation

### Recurrence Relation
$$T(N) = 2T(N/2) + \Theta(N)$$
By Master's Theorem ($a = 2, b = 2, f(N) = \Theta(N)$):
Since $f(N) = \Theta(N^{\log_b a}) = \Theta(N^1)$,
$$T(N) = \Theta(N \log_2 N)$$

### Pseudocode
```text
FUNCTION MergeSort(arr, left, right):
    IF left < right THEN:
        mid = left + (right - left) / 2
        MergeSort(arr, left, mid)
        MergeSort(arr, mid + 1, right)
        Merge(arr, left, mid, right)
    END IF
END FUNCTION

FUNCTION Merge(arr, left, mid, right):
    Create temp arrays L[0...mid-left] and R[0...right-mid-1]
    Copy data to L and R
    i = 0, j = 0, k = left
    WHILE i < len(L) AND j < len(R) DO:
        IF L[i] <= R[j] THEN:
            arr[k++] = L[i++]
        ELSE:
            arr[k++] = R[j++]
        END IF
    END WHILE
    Copy remaining elements of L and R into arr
END FUNCTION
```

---

## 4. Dry Run Trace
Input: `[38, 27, 43, 3, 9, 82, 10]` ($N = 7$)

```text
                     [38, 27, 43, 3, 9, 82, 10]
                             /          \
                [38, 27, 43, 3]        [9, 82, 10]
                  /         \            /      \
             [38, 27]     [43, 3]      [9, 82]  [10]
              /    \       /   \        /   \     |
            [38]  [27]   [43]  [3]    [9]  [82] [10]
              \    /       \   /        \   /     |
             [27, 38]     [3, 43]      [9, 82]  [10]
                 \           /             \     /
               [3, 27, 38, 43]          [9, 10, 82]
                       \                     /
                     [3, 9, 10, 27, 38, 43, 82]
```

---

## 5. Complexity Analysis

| Case | Time Complexity | Auxiliary Space | Explanation |
| :--- | :--- | :--- | :--- |
| **Best Case** | $\Theta(N \log N)$ | $O(N)$ | Subarray divisions and linear merge scans occur regardless of initial ordering. |
| **Average Case** | $\Theta(N \log N)$ | $O(N)$ | Tree height is $\lceil \log_2 N \rceil$, each level takes $O(N)$ merge time. |
| **Worst Case** | $\Theta(N \log N)$ | $O(N)$ | Guaranteed upper bound; does not degrade like QuickSort. |
| **Stability** | Stable | Using `<=` during merge retains relative order of equal keys. |

---

## 6. Real-Life Application
- **External Sorting:** Sorting massive files that cannot fit into RAM (e.g., multi-gigabyte log databases) using disk-based Multiway Merge Sort.
- **E-Commerce Product Catalogs:** Sorting product listings by multiple attributes (e.g., Price then Rating) where stability is mandatory.

---

## 7. Sample Input & Output
```text
Initial Array: [ 38 27 43 3 9 82 10 ]

Executing Divide-and-Conquer Merge Sort...
[Metrics] Total Subarray Merges: 6
Sorted Array:  [ 3 9 10 27 38 43 82 ]
```

---

## 8. Learning Outcomes
1. Formulated and resolved divide-and-conquer recurrences using Master's Theorem.
2. Understood the trade-off of Merge Sort: guaranteed $O(N \log N)$ performance at the cost of $O(N)$ temporary memory allocation.

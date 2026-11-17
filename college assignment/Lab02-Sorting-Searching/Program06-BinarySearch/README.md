# Program 06: Binary Search (Iterative & Recursive)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement both Iterative and Recursive Binary Search in C++ on a sorted sequence of numbers. Analyze how dividing the search interval in half achieves logarithmic runtime $O(\log_2 N)$.

---

## 2. Approach
Binary search repeatedly divides the search interval in half:
1. Examine the element at the midpoint `mid = left + (right - left) / 2`.
2. If `arr[mid] == target`, search terminates with success.
3. If `arr[mid] < target`, the target must reside in the right subarray (`left = mid + 1`).
4. If `arr[mid] > target`, the target must reside in the left subarray (`right = mid - 1`).
5. Continue until `left > right` (target not found).

---

## 3. Algorithm & Pseudocode

```text
FUNCTION BinarySearchIterative(arr, target):
    left = 0, right = N - 1
    WHILE left <= right DO:
        mid = left + (right - left) / 2
        IF arr[mid] == target THEN:
            RETURN mid
        ELSE IF arr[mid] < target THEN:
            left = mid + 1
        ELSE:
            right = mid - 1
        END IF
    END WHILE
    RETURN -1
END FUNCTION
```

---

## 4. Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case Time** | $O(1)$ | Target element is located at the exact initial midpoint. |
| **Average Case Time** | $O(\log_2 N)$ | Search space shrinks by a factor of 2 on each comparison. |
| **Worst Case Time** | $O(\log_2 N)$ | Target is at an extremity or not present in the array. |
| **Auxiliary Space** | $O(1)$ (Iterative) / $O(\log_2 N)$ (Recursive) | Iterative variant requires no call stack frames. |

---

## 5. Real-Life Application
- Database indexing (B-Trees / Binary search on page keys).
- Dictionary lookup and Git commit bisecting to isolate bugs.

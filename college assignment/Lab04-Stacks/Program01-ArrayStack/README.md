# Program 01: Array-Based Stack

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement a static contiguous array-based Stack supporting LIFO (Last-In-First-Out) operations (`push`, `pop`, `peek`, `isEmpty`, `isFull`) with exception handling for overflow and underflow conditions.

---

## 2. Approach
- A single integer `topIndex` tracks the most recently added item.
- Initially `topIndex = -1`.
- `push`: Increments `++topIndex` and inserts data if `topIndex < CAPACITY - 1`.
- `pop`: Retrieves `data[topIndex--]` if `topIndex >= 0`.
- Exception throwing prevents memory corruption when bounds are breached.

---

## 3. Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Push** | $O(1)$ | $O(1)$ |
| **Pop** | $O(1)$ | $O(1)$ |
| **Peek** | $O(1)$ | $O(1)$ |
| **isEmpty / isFull** | $O(1)$ | $O(1)$ |

---

## 4. Real-Life Application
- Function call execution stack (CPU call frames).
- Expression syntax verification in parsers and compilers.

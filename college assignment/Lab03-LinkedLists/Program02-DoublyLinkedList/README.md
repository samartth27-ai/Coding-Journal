# Program 02: Doubly Linked List (DLL)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement a Doubly Linked List in C++ with forward and backward traversal capabilities, dynamic head/tail insertion, and safe node deletion without pointer corruption.

---

## 2. Approach
Each node in a Doubly Linked List holds two pointers:
- `next`: Points to the successor node.
- `prev`: Points to the predecessor node.
This allows bidirectional traversal and permits deleting any known node in $O(1)$ time by adjusting `curr->prev->next` and `curr->next->prev`.

---

## 3. Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert at Head / Tail** | $O(1)$ | $O(1)$ |
| **Delete Node (given pointer)** | $O(1)$ | $O(1)$ |
| **Delete by Value (search)** | $O(N)$ | $O(1)$ |
| **Forward / Backward Traversal** | $O(N)$ | $O(1)$ |

---

## 4. Real-Life Application
- Web browser backward and forward navigation history.
- LRU (Least Recently Used) cache implementation combining Hash Map + Doubly Linked List.

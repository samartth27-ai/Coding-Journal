# Program 03: Circular Linked List (CLL)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement a Circular Linked List in C++ where the last node points back to the first node. Optimize head and tail insertions to $O(1)$ by maintaining a single pointer to `tail`.

---

## 2. Approach
Maintaining a `tail` pointer instead of `head`:
- `tail->next` is always the `head`.
- Insert at Head: Insert after `tail` without moving `tail` ($O(1)$).
- Insert at Tail: Insert after `tail` and advance `tail = tail->next` ($O(1)$).
- Traversal checks `curr != head` to avoid infinite loops while allowing continuous cycles.

---

## 3. Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert at Head / Tail** | $O(1)$ | $O(1)$ |
| **Traversal (1 Cycle)** | $O(N)$ | $O(1)$ |
| **Search** | $O(N)$ | $O(1)$ |

---

## 4. Real-Life Application
- Round-Robin Process Scheduling in Operating Systems.
- Multiplayer turn-based board games (e.g., Monopoly turn cycles).

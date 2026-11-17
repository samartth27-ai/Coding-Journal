# Program 01: Singly Linked List (SLL)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement a dynamic Singly Linked List in C++ supporting:
- Insertion at Head, Tail, and an arbitrary position $k$
- Deletion by key
- Search for a target value
- In-place reversal using the three-pointer technique
- Safe memory deallocation in destructor

---

## 2. Approach
A Singly Linked List is a linear data structure of nodes connected via unidirectional pointers:
- `insertAtHead`: Instantiates a new node whose `next` points to current `head`, then updates `head` ($O(1)$).
- `insertAtTail`: Traverses to the last node whose `next == nullptr` and links the new node ($O(N)$).
- `reverse`: Uses 3 sliding pointers (`prev`, `curr`, `nextNode`) to reverse node pointers in a single pass without extra memory ($O(N)$ time, $O(1)$ space).

---

## 3. Algorithm & Pseudocode

```text
FUNCTION ReverseLinkedList(head):
    prev = NULL
    curr = head
    WHILE curr != NULL DO:
        nextNode = curr->next
        curr->next = prev
        prev = curr
        curr = nextNode
    END WHILE
    head = prev
    RETURN head
END FUNCTION
```

---

## 4. Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert at Head** | $O(1)$ | $O(1)$ |
| **Insert at Tail** | $O(N)$ | $O(1)$ |
| **Insert at Position $k$** | $O(k)$ | $O(1)$ |
| **Delete by Value** | $O(N)$ | $O(1)$ |
| **Search** | $O(N)$ | $O(1)$ |
| **In-place Reversal** | $O(N)$ | $O(1)$ |

---

## 5. Real-Life Application
- Memory management free-lists in operating systems.
- Dynamic adjacency lists for graph representations.
- Undo/redo logs where sequential forward links track execution steps.

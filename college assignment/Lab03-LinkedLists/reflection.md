# Lab 03: Reflection & Analysis

**Cluster:** Linked Lists (Singly, Doubly, Circular, Applications)  
**Student:** Samarth Dubey (IC-2K25-75)  

---

## 1. What I Learned
- Understood the structural distinctions and trade-offs between Singly, Doubly, and Circular Linked Lists.
- Experienced dynamic memory allocation using `new` and learned strict resource cleanup using `delete` in destructors to prevent memory leaks.
- Mastered the three-pointer technique (`prev`, `curr`, `next`) for $O(N)$ time and $O(1)$ space in-place list reversal.
- Recognized how circular links allow continuous wrapping without null-pointer checks, which is essential for round-robin dispatchers and media playlists.

## 2. Difficulties Encountered & Resolutions
- **Issue with Destructor in Circular Linked List:** Traversing until `nullptr` causes an infinite loop in circular structures.  
  *Resolution:* Broke the circle by setting `tail->next = nullptr` before beginning the sequential node deletion.
- **Dangling Pointers in Doubly Linked List:** Deleting head or tail nodes could leave `prev` or `next` pointing to freed memory.  
  *Resolution:* Explicitly checked edge cases where `curr == head` or `curr == tail` and updated boundary pointers before `delete`.

## 3. Optimizations Applied
- Maintained a `tail` pointer in the Circular Linked List, reducing both insertion-at-head and insertion-at-tail to $O(1)$ operations.
- Stored bidirectional links in the Music Playlist Manager to achieve instantaneous $O(1)$ song skipping in both forward and backward directions.

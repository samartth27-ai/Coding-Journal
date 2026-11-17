# Lab 03: Linked Lists

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## Overview
This laboratory cluster implements dynamic node-based linear data structures in C++ (Singly, Doubly, and Circular Linked Lists) and applies them to real-world software components like music playlists.

## Table of Programs

| Directory | Program | Description | Key Operation Time | Auxiliary Space |
| :--- | :--- | :--- | :--- | :--- |
| `Program01-SinglyLinkedList/` | Singly Linked List | Insert, delete, search, in-place reversal | $O(1)$ head, $O(N)$ rev | $O(1)$ |
| `Program02-DoublyLinkedList/` | Doubly Linked List | Bidirectional pointer traversal & deletion | $O(1)$ head/tail | $O(1)$ |
| `Program03-CircularLinkedList/`| Circular Linked List| Round-robin looping without null pointers | $O(1)$ insert | $O(1)$ |
| `Program05-PlaylistManager/` | Application | Music Playlist Manager (Looping / Next / Prev) | $O(1)$ navigation | $O(1)$ |

## Compilation & Execution
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o app
./app
```

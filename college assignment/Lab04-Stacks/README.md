# Lab 04: Stacks

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## Overview
This laboratory cluster implements LIFO data structures in C++, addressing static array implementations, expression conversion algorithms, and interactive application engines.

## Table of Programs

| Directory | Program | Description | Key Operation Time | Auxiliary Space |
| :--- | :--- | :--- | :--- | :--- |
| `Program01-ArrayStack/` | Array Stack | Static capacity bounded stack with overflow checking | $O(1)$ | $O(1)$ |
| `Program03-InfixToPostfix/`| Expression Converter| Shunting-yard algorithm with precedence handling | $O(N)$ | $O(N)$ |
| `Program05-UndoRedoBuffer/`| Application | Dual-Stack Undo/Redo Engine (Command Pattern) | $O(1)$ | $O(M)$ |

## Compilation & Execution
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o app
./app
```

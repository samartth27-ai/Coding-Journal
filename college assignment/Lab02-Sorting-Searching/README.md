# Lab 02: Sorting and Searching Algorithms

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## Overview
This laboratory cluster implements, benchmarks, and applies essential sorting and searching algorithms in C++ (C++17 standard).

## Table of Programs

| Directory | Program | Description | Best Time | Worst Time | Space |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `Program01-BubbleSort/` | Bubble Sort | Optimized with early-exit flag | $O(N)$ | $O(N^2)$ | $O(1)$ |
| `Program02-SelectionSort/` | Selection Sort | Min-element selection, $O(N)$ swaps | $O(N^2)$ | $O(N^2)$ | $O(1)$ |
| `Program03-InsertionSort/` | Insertion Sort | Adaptive shifting into sorted prefix | $O(N)$ | $O(N^2)$ | $O(1)$ |
| `Program04-MergeSort/` | Merge Sort | Divide-and-conquer recursive sort | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ |
| `Program06-BinarySearch/` | Binary Search | Iterative & Recursive interval bisection | $O(1)$ | $O(\log N)$ | $O(1)$ |
| `Program07-StudentRecordManager/`| Application | Student Record Manager (Search/Sort) | $O(1)$ | $O(N \log N)$ | $O(N)$ |

## Compilation & Execution Instructions
Compile any program using GCC/G++:
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o app
./app
```

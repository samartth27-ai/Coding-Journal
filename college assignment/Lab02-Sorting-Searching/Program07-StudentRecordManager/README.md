# Program 07: Student Record Manager (Application)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Develop a modular C++ application to manage university student academic records. Provide features to sort students by roll number (using Merge Sort), generate a merit ranking list by marks (using Insertion Sort), and perform $O(\log N)$ student searches using Binary Search.

---

## 2. Approach & Architecture
- **Data Model:** Encapsulates `Student` entity with `rollNo`, `name`, and `marks`.
- **Merge Sort Integration:** Sorts records by Roll Number in guaranteed $O(N \log N)$ time.
- **Insertion Sort Integration:** Stable sorting of records in descending order of marks to create a merit list.
- **Binary Search Integration:** Enables rapid $O(\log N)$ record retrieval by student ID once roll numbers are sorted.

---

## 3. Complexity Summary

| Feature | Underlying Algorithm | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- | :--- |
| **Sort by Roll No** | Merge Sort | $O(N \log N)$ | $O(N)$ |
| **Merit Ranking by Marks** | Insertion Sort | $O(N^2)$ worst, $O(N)$ best | $O(1)$ |
| **Search by Roll No** | Binary Search | $O(\log N)$ | $O(1)$ |

---

## 4. Learning Outcomes
1. Integrated multiple fundamental sorting and searching algorithms into a unified real-world management system.
2. Understood why Merge Sort is preferred for primary key ordering while Binary Search enables fast query resolution.

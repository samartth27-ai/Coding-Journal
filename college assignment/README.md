# IC-2K25-75-DS-Samarth_Dubey

# IC-307D: Data Structures & Algorithms LAB

> **Student Name:** Samarth Dubey  
> **Roll Number:** IC-2K25-75  
> **Course:** Master of Computer Application (MCA) - Semester III  
> **Course Code:** IC-307D | Data Structures and Algorithms LAB  
> **Institution:** International Institute of Professional Studies (IIPS), Devi Ahilya Vishwavidyalaya (DAVV), Indore  
> **GitHub Profile:** [@samartth27-ai](https://github.com/samartth27-ai)  
> **Language / Toolchain:** C++ (C++17 Standard), GCC/G++ 15.2 (MSYS2 UCRT64)  

---

## 🌟 Repository Overview & Progression

This repository contains practical implementations, real-world applications, mathematical complexity derivations, and faculty presentation materials for the **IC-307D Data Structures and Algorithms Lab**.

The project places special emphasis on **Sorting & Searching**, **Linked Lists**, and **Stacks**, culminating in an enterprise **Smart Library Management System** that unites all three foundational concepts.

```text
IC-2K25-75-DS-Samarth_Dubey/
│
├── Lab02-Sorting-Searching/
│   ├── Program01-BubbleSort/         # Optimized Bubble Sort with early termination
│   ├── Program02-SelectionSort/      # Minimum element selection, O(N) swaps
│   ├── Program03-InsertionSort/      # Adaptive shifting into sorted prefix
│   ├── Program04-MergeSort/          # Divide-and-conquer O(N log N) recursive sort
│   ├── Program06-BinarySearch/       # Iterative and Recursive interval bisection
│   ├── Program07-StudentRecordManager/ # Faculty Application: Student search/sort
│   ├── README.md                     # Unit overview & complexity matrix
│   └── reflection.md                 # Cluster learnings, edge cases & optimizations
│
├── Lab03-LinkedLists/
│   ├── Program01-SinglyLinkedList/   # Dynamic SLL: Insert, delete, search, in-place reversal
│   ├── Program02-DoublyLinkedList/   # Bidirectional prev/next pointer navigation
│   ├── Program03-CircularLinkedList/ # Continuous loop without null pointers
│   ├── Program05-PlaylistManager/    # Faculty Application: Looping Music Playlist
│   ├── README.md                     # Unit overview
│   └── reflection.md                 # Learnings, circular pointer cleanup & optimizations
│
├── Lab04-Stacks/
│   ├── Program01-ArrayStack/         # Static bounded stack with overflow/underflow checks
│   ├── Program03-InfixToPostfix/     # Dijkstra's Shunting-yard expression converter
│   ├── Program05-UndoRedoBuffer/     # Faculty Application: Text Editor Undo/Redo Engine
│   ├── README.md                     # Unit overview
│   └── reflection.md                 # Learnings, operator precedence & Command Pattern
│
├── Capstone-Projects/
│   ├── Project01-LibraryManagement/  # Showcase Project: Integrates LL + Stack + Merge Sort
│   └── README.md                     # Capstone documentation & architecture
│
├── docs/
│   ├── diagrams/                     # PlantUML diagrams (Architecture, Undo/Redo, Reversal)
│   ├── algorithm-flowcharts/         # Visual ASCII / Flowcharts for core algorithms
│   ├── complexity-analysis.pdf       # Master asymptotic complexity reference table
│   ├── final-report.pdf              # Comprehensive lab report for faculty submission
│   └── presentation.pdf              # Presentation slides for viva defense
│
├── .gitignore                        # Git exclusion rules
└── README.md                         # Main repository guide
```

---

## 🏆 Faculty Presentation Highlight: Capstone Project

### **Smart Library Management System** (`Capstone-Projects/Project01-LibraryManagement/`)
Engineered specifically for faculty viva and practical demonstration:

```text
                      +-----------------------------+
                      |     SmartLibrarySystem      |
                      +-----------------------------+
                                     |
       +-----------------------------+-----------------------------+
       |                                                           |
       v                                                           v
[Singly Linked List]                                       [LIFO Stack]
 Dynamic Book Inventory                               Transaction Undo History
 - O(1) dynamic node addition                          - Tracks checkouts & returns
 - Zero fixed array allocation                         - O(1) single-click undo
 - In-place Merge Sort O(N log N) by title
```

- **Linked List Integration:** All book records are allocated on the heap as connected nodes (`isbn`, `title`, `author`, `isAvailable`).
- **Merge Sort Integration:** Uses the fast/slow pointer method to partition the linked list in $\Theta(N \log N)$ without auxiliary memory arrays.
- **Stack Integration:** Tracks checkout and return transactions in a LIFO stack, allowing instantaneous single-click **Undo** of any operation.

---

## 📊 Algorithmic Complexity Reference

| Module | Algorithm / Structure | Best Time | Average Time | Worst Time | Aux Space | Stability |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Lab 02** | Bubble Sort (Optimized) | $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Stable |
| **Lab 02** | Selection Sort | $O(N^2)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Unstable |
| **Lab 02** | Insertion Sort | $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Stable |
| **Lab 02** | Merge Sort | $O(N \log N)$| $O(N \log N)$| $O(N \log N)$| $O(N)$ | Stable |
| **Lab 02** | Binary Search | $O(1)$ | $O(\log N)$ | $O(\log N)$ | $O(1)$ | N/A |
| **Lab 03** | Singly Linked List | $O(1)$ head | $O(N)$ | $O(N)$ rev | $O(1)$ | N/A |
| **Lab 03** | Doubly Linked List | $O(1)$ head/tail | $O(N)$ | $O(N)$ | $O(1)$ | N/A |
| **Lab 03** | Circular Linked List | $O(1)$ insert | $O(N)$ loop | $O(N)$ | $O(1)$ | N/A |
| **Lab 04** | Array Stack | $O(1)$ push/pop | $O(1)$ | $O(1)$ | $O(1)$ | N/A |
| **Lab 04** | Shunting-Yard (Infix $\to$ Postfix) | $O(N)$ | $O(N)$ | $O(N)$ | $O(N)$ | N/A |
| **Lab 04** | Undo/Redo Engine | $O(1)$ | $O(1)$ | $O(1)$ | $O(M)$ | N/A |
| **Capstone** | Smart Library System | $O(1)$ add/undo | $O(N \log N)$ sort | $O(N \log N)$ | $O(\log N)$ | Stable |

---

## 🛠️ Build and Compilation Instructions

All programs are written in ISO C++17 without external proprietary dependencies and can be compiled using GCC/Clang or MSVC.

### Compile and Run Any Program:
```powershell
# Example: Running the Capstone Library System
cd Capstone-Projects\Project01-LibraryManagement
g++ -std=c++17 -Wall -Wextra main.cpp -o library_app
.\library_app

# Example: Running the Music Playlist Manager
cd Lab03-LinkedLists\Program05-PlaylistManager
g++ -std=c++17 -Wall -Wextra main.cpp -o playlist_app
.\playlist_app

# Example: Running the Text Editor Undo/Redo Buffer
cd Lab04-Stacks\Program05-UndoRedoBuffer
g++ -std=c++17 -Wall -Wextra main.cpp -o undoredo_app
.\undoredo_app
```

---

## 📑 Documentation & Presentation Reports

PDF documents are generated in the `docs/` directory:
- [final-report.pdf](docs/final-report.pdf) - Formal laboratory practical report formatted for faculty evaluation.
- [complexity-analysis.pdf](docs/complexity-analysis.pdf) - Asymptotic proofs, Master Theorem derivations, and operation complexity matrices.
- [presentation.pdf](docs/presentation.pdf) - Viva presentation slides for faculty defense.
- [diagrams/](docs/diagrams/) - PlantUML architecture and sequence diagrams.
- [algorithm-flowcharts/](docs/algorithm-flowcharts/) - Algorithm decision flowcharts and execution traces.

---

## 🌿 Git Branching Strategy

This repository demonstrates professional Git workflows using dedicated feature branches merged into `main`:
- `feature/lab02-sorting-searching`: Sorting & searching algorithms with student record manager.
- `feature/lab03-linked-lists`: Singly, doubly, and circular linked lists with music playlist application.
- `feature/lab04-stacks`: Array stack, expression converter, and dual-stack undo/redo buffer.
- `feature/capstone-library-management`: Capstone Smart Library System.
- `docs/documentation-reports`: PDF reports, PlantUML diagrams, and algorithm flowcharts.

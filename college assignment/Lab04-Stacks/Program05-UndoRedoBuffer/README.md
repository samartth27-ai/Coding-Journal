# Program 05: Text Editor Undo/Redo Engine (Application)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement an Undo/Redo text buffer in C++ using the **Command Design Pattern** combined with **Dual Stacks** (`undoStack` and `redoStack`). Demonstrate the execution, undoing, and redoing of text modification commands.

---

## 2. Approach & Architecture
- **Command Pattern Interface:** Abstract base class `Command` defines pure virtual methods `execute(doc)` and `undo(doc)`.
- **Dual Stacks:**
  - `undoStack`: Stores previously executed commands.
  - `redoStack`: Stores commands reverted by undo.
- When an `undo()` action is invoked:
  1. Pop top command from `undoStack`.
  2. Invoke `cmd->undo(doc)`.
  3. Push `cmd` onto `redoStack`.
- When a new mutating action is executed, `redoStack` is cleared to prevent divergent history branching.

---

## 3. Complexity Analysis

| Action | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Execute Command** | $O(1)$ amortized | $O(\text{command delta})$ |
| **Undo** | $O(1)$ | $O(1)$ |
| **Redo** | $O(1)$ | $O(1)$ |

---

## 4. Real-Life Application
- Text editors (VS Code, Microsoft Word, Notepad++).
- Vector graphics editors (Figma, Photoshop, Adobe Illustrator).
- Database transaction rollback checkpoints.

# Lab 04: Reflection & Analysis

**Cluster:** Stacks (Static, Expressions, Undo/Redo Engine)  
**Student:** Samarth Dubey (IC-2K25-75)  

---

## 1. What I Learned
- Mastered the LIFO (Last-In-First-Out) discipline and its natural mapping to recursive call stacks, evaluation engines, and historical reversibility.
- Understood the mechanics of operator precedence, associativity, and parenthetical matching using Dijkstra's Shunting-yard algorithm.
- Implemented real-world software design by combining the classic Command Pattern with two stacks (`undoStack` and `redoStack`) to produce a production-grade undo engine.

## 2. Difficulties Encountered & Resolutions
- **Right-Associativity in Expressions:** Exponentiation (`^`) evaluates right-to-left ($2^{3^2} = 2^9 = 512$, not $8^2 = 64$).  
  *Resolution:* Formulated a custom precedence comparator distinguishing left-associative operators (`*`, `/`, `+`, `-`) from right-associative (`^`).
- **Redo History Invalidation:** Executing a new typing action after undoing could lead to an inconsistent state if redo elements persisted.  
  *Resolution:* Cleared the entire `redoStack` whenever a new command executed.

## 3. Optimizations Applied
- Utilized `std::shared_ptr<Command>` to manage polymorphic heap memory safely without raw pointer leaks.
- Used fixed-size static arrays for the embedded array stack to eliminate dynamic memory allocation overhead.

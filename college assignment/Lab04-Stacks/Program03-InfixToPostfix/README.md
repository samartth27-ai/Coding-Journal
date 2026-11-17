# Program 03: Infix to Postfix Conversion

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Implement Dijkstra's Shunting-yard algorithm using a Stack in C++ to transform human-readable infix expressions containing parenthesized operations and variable operator precedence into unambiguous postfix (Reverse Polish Notation) expressions.

---

## 2. Approach
1. Scan tokens left-to-right.
2. If token is an **operand**, append directly to output string.
3. If token is `'('`, push onto stack.
4. If token is `')'`, pop stack to output until `'('` is encountered, then discard `'('`.
5. If token is an **operator** `op`:
   - While stack top has higher precedence (or equal precedence with left associativity), pop it to output.
   - Push `op` onto stack.
6. Pop remaining operators from stack to output upon reaching end of expression.

---

## 3. Operator Precedence Hierarchy

| Operator | Symbol | Precedence | Associativity |
| :--- | :--- | :--- | :--- |
| **Exponentiation** | `^` | 3 (Highest) | Right-to-Left |
| **Multiplication / Division / Modulo** | `*`, `/`, `%` | 2 | Left-to-Right |
| **Addition / Subtraction** | `+`, `-` | 1 (Lowest) | Left-to-Right |

---

## 4. Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | Each character is pushed and popped from the stack at most once. |
| **Space Complexity** | $O(N)$ | Operator stack size bounded by total operators in the formula. |

---

## 5. Real-Life Application
- Compiler front-ends: parsing algebraic expressions into Intermediate Representation (IR) without ambiguity.
- Stack-based hardware architectures (e.g., JVM execution bytecode).

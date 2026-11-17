# Algorithm Flowcharts & Execution Traces

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey (IC-2K25-75)  

---

## 1. Bubble Sort with Early Exit Optimization

```
         +-----------------------+
         |         START         |
         +-----------------------+
                     |
                     v
             [ i = 0, n = len ]
                     |
      +------------->|
      |              v
      |       /-------------\
      |      /    i < n - 1  \ ---- NO ----+
      |      \        ?      /             |
      |       \-------------/              |
      |              | YES                 |
      |              v                     |
      |      [ swapped = FALSE ]           |
      |              |                     |
      |   +--------->|                     |
      |   |          v                     |
      |   |   /---------------\            |
      |   |  / j < n - i - 1 ? \ --- NO ---+
      |   |  \                 /           |
      |   |   \---------------/            |
      |   |          | YES                 |
      |   |          v                     |
      |   |   /---------------\            |
      |   |  /  arr[j] >       \           |
      |   |  \  arr[j+1] ?     /           |
      |   |   \---------------/            |
      |   |       | YES       | NO         |
      |   |       v           |            |
      |   | [ SWAP arr[j],    |            |
      |   |     arr[j+1] ]    |            |
      |   | [ swapped = TRUE] |            |
      |   |       |           |            |
      |   |       v           v            |
      |   |        [ j = j + 1 ]           |
      |   +---------------+                |
      |                                    |
      |                                    v
      |                           /-----------------\
      |                          / swapped == FALSE  \ ---- YES ----+
      |                          \         ?         /              |
      |                           \-----------------/               |
      |                                    | NO                     |
      |                                    v                        |
      +----------------------------- [ i = i + 1 ]                  |
                                                                    v
                                                       +------------------------+
                                                       |   END (Sorted Array)   |
                                                       +------------------------+
```

---

## 2. Linked List In-Place Reversal (Three Pointers)

```
        +-----------------------------------------+
        |                 START                   |
        +-----------------------------------------+
                             |
                             v
               [ prev = NULL, curr = head ]
                             |
              +------------->|
              |              v
              |       /--------------\
              |      / curr != NULL ? \ ---- NO ----+
              |      \                /             |
              |       \--------------/              |
              |              | YES                  |
              |              v                      |
              |     [ nextNode = curr->next ]       |
              |     [ curr->next = prev     ]       |
              |     [ prev = curr           ]       |
              |     [ curr = nextNode       ]       |
              |              |                      |
              +--------------+                      |
                                                    v
                                            [ head = prev ]
                                                    |
                                                    v
                                        +-----------------------+
                                        |  END (Reversed List)  |
                                        +-----------------------+
```

---

## 3. Dijkstra Shunting-Yard (Infix to Postfix)

```
                  +---------------------------+
                  |           START           |
                  +---------------------------+
                                |
                                v
                    [ For each token in Infix ]
                                |
             +------------------+------------------+
             |                                     |
             v                                     v
       /-----------\                         /-----------\
      / Is Operand? \ --- YES --->          / Is Operator \ --- YES --->
      \             /   Append to Output    \      op     /   Pop higher precedence
       \-----------/                         \-----------/    operators to output,
                                                              then push op to stack.
```

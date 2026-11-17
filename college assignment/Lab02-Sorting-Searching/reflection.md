# Lab 02: Reflection & Analysis

**Cluster:** Sorting and Searching Algorithms  
**Student:** Samarth Dubey (IC-2K25-75)  

---

## 1. What I Learned
- Understood the practical performance difference between $O(N^2)$ elementary sorting algorithms (Bubble, Selection, Insertion) and $O(N \log N)$ Divide-and-Conquer algorithms (Merge Sort).
- Learned how the nature of the dataset (random, pre-sorted, reverse-sorted) dramatically impacts runtime behavior. For instance, Insertion Sort executes in linear time $O(N)$ on pre-sorted data, making it ideal for nearly-sorted datasets.
- Discovered the crucial role of stability in sorting: preserving original ordering of duplicate records is essential when multi-attribute sorting is required (e.g. sorting students first by section, then by name).

## 2. Difficulties Encountered & Resolutions
- **Issue with Integer Overflow in Binary Search:** Computing `mid = (left + right) / 2` can overflow 32-bit signed integers when arrays exceed $2^{30}$ elements.  
  *Resolution:* Replaced with the safe midpoint computation: `mid = left + (right - left) / 2`.
- **Merge Sort Auxiliary Space Allocation:** Creating dynamic subarrays in deep recursion can cause frequent heap allocations.  
  *Resolution:* Allocated vectors sized to the exact partition size (`n1` and `n2`), avoiding unbounded reallocations.

## 3. Optimizations Applied
- Added the `swapped` boolean flag in Bubble Sort to exit early when no inversions remain ($O(N)$ best case).
- Selected Insertion Sort for merit ranking because of its minimal instruction overhead on small to medium college batch sizes.
- Utilized Binary Search over linear search to reduce student lookup from $O(N)$ to $O(\log N)$.

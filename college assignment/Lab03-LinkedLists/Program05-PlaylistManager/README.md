# Program 05: Music Playlist Manager (Application)

**Course:** IC-307D | Data Structures and Algorithms LAB  
**Student:** Samarth Dubey  
**Roll Number:** IC-2K25-75  
**Institution:** IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore  

---

## 1. Problem Statement
Design and implement an interactive Music Playlist Manager in C++ utilizing a **Circular Doubly Linked List**. Support song insertion, forward playback (Next), backward playback (Previous), and continuous loop playback without null pointer crashes.

---

## 2. Approach & Data Structure Selection
A **Circular Doubly Linked List** is optimal for a media player:
- `next` pointer transitions to the next track. When at the last track, it loops seamlessly back to the first track.
- `prev` pointer transitions to the previous track. When at the first track, it wraps directly to the last track.
- All track transitions occur in strict $O(1)$ constant time with zero array reallocation or shifting overhead.

---

## 3. Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Add Song** | $O(1)$ | $O(1)$ |
| **Play Next Track** | $O(1)$ | $O(1)$ |
| **Play Previous Track** | $O(1)$ | $O(1)$ |
| **Display All Tracks** | $O(N)$ | $O(1)$ |

---

## 4. Real-Life Application
- Music streaming apps (Spotify, Apple Music, YouTube Music) playlist loops and queue controls.
- Carousel sliders and image gallery navigation widgets.

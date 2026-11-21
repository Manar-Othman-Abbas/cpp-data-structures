# C++ Data Structures

My implementations of the core data structures from my Data Structures course, written in C++ from scratch (no STL containers).

## What's inside

| File | Data structure | Main operations |
|---|---|---|
| `singly_linked_list.cpp` | Singly linked list | insert, delete, search, print |
| `stack.cpp` | Stack (array-based) | push, pop, peek, isEmpty |
| `queue.cpp` | Queue (array-based) | enqueue, dequeue, front, isEmpty |
| `binary_search_tree.cpp` | Binary search tree | insert, search, inorder traversal |

Each file has a small `main()` that demonstrates the operations.

## How to run

You need a C++ compiler like g++. Then for any file:

```bash
g++ singly_linked_list.cpp -o linked_list
./linked_list
```

## What I learned

- How pointers and dynamic memory work in practice
- The difference between array-based and linked structures
- Time complexity of common operations (O(1) vs O(n))
- Traversing trees recursively

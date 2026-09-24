# FAANG Interview Prep Guide (C++)

A focused path for coding interviews at Meta, Amazon, Apple, Netflix, Google (and similar).  
Theory checklist lives in [README.md](./README.md). **This page is what to actually study and code.**

## What FAANG coding rounds test

| Round type | What matters |
|------------|--------------|
| Online assessment / phone | Speed + correctness on medium DSA |
| Onsite coding | Clean C++, edge cases, complexity talk |
| System design (L5+) | Tradeoffs, scalability — see `System Design/` |
| Behavioral | STAR stories (Leadership Principles / Googleyness) |

For **L3–L5 SWE**, coding DSA is ~60–70% of the signal. Master patterns below before obscure sorts/trees from the full checklist.

---

## Study order (recommended)

1. **Arrays + Hash Map** — frequency maps, two sum family  
2. **Two Pointers + Sliding Window** — strings/subarrays  
3. **Binary Search** — on indexes *and* on answer space  
4. **Linked List** — reverse, cycle, merge  
5. **Stack / Queue / Deque** — monotonic stack, BFS queue  
6. **Trees** — DFS/BFS, BST, LCA  
7. **Heap** — top-K, merge K lists  
8. **Graphs** — BFS/DFS, topo sort, Union-Find  
9. **Backtracking** — subsets / permutations / combination sum  
10. **Dynamic Programming** — 1D → knapsack → LCS/LIS → grid  
11. **Tries + Bits** — prefix problems, bit tricks  
12. **Greedy** — interval / jump / scheduling  

Target: **150–200** well-understood LeetCode problems (quality > quantity).

---

## Materials in this repo

### Data Structures (C++)

| Topic | Docs | Code |
|-------|------|------|
| Arrays / `std::vector` | [Arrays.md](./Data%20Structures/Arrays.md) | — |
| Linked List | [LinkedList.md](./Data%20Structures/LinkedList.md) | [LinkedList.cpp](./Data%20Structures/LinkedList.cpp) |
| Stack | [Stack.md](./Data%20Structures/Stack.md) | [Stack.cpp](./Data%20Structures/Stack.cpp) |
| Queue / Deque | [Queue.md](./Data%20Structures/Queue.md) | [Queue.cpp](./Data%20Structures/Queue.cpp) |
| Hash Map / Set | [HashMap.md](./Data%20Structures/HashMap.md) | [HashMap.cpp](./Data%20Structures/HashMap.cpp) |
| Binary Tree / BST | [BinaryTree.md](./Data%20Structures/BinaryTree.md) | [BinaryTree.cpp](./Data%20Structures/BinaryTree.cpp) |
| Heap / Priority Queue | [Heap.md](./Data%20Structures/Heap.md) | [Heap.cpp](./Data%20Structures/Heap.cpp) |
| Graph | [Graph.md](./Data%20Structures/Graph.md) | [Graph.cpp](./Data%20Structures/Graph.cpp) |
| Trie | [Trie.md](./Data%20Structures/Trie.md) | [Trie.cpp](./Data%20Structures/Trie.cpp) |
| Union-Find (DSU) | [UnionFind.md](./Data%20Structures/UnionFind.md) | [UnionFind.cpp](./Data%20Structures/UnionFind.cpp) |

### Algorithms (C++)

| Topic | Docs | Code |
|-------|------|------|
| Two Pointers | [Two-Pointer-Algo.md](./Algorithms/Two-Pointer-Algo.md) | [Two-Pointer-Algo.cpp](./Algorithms/Two-Pointer-Algo.cpp) |
| Sliding Window | [Sliding-Window-Algo.md](./Algorithms/Sliding-Window-Algo.md) | — (examples in md) |
| Binary Search | [BinarySearch.md](./Algorithms/BinarySearch.md) | [BinarySearch.cpp](./Algorithms/BinarySearch.cpp) |
| Sorting | [Sorting.md](./Algorithms/Sorting.md) | [Sorting.cpp](./Algorithms/Sorting.cpp) |
| Recursion / Backtracking | [Recursion-Backtracking.md](./Algorithms/Recursion-Backtracking.md) | [Recursion-Backtracking.cpp](./Algorithms/Recursion-Backtracking.cpp) |
| Dynamic Programming | [DynamicProgramming.md](./Algorithms/DynamicProgramming.md) | [DynamicProgramming.cpp](./Algorithms/DynamicProgramming.cpp) |
| Greedy | [Greedy.md](./Algorithms/Greedy.md) | [Greedy.cpp](./Algorithms/Greedy.cpp) |
| Bit Manipulation | [BitManipulation.md](./Algorithms/BitManipulation.md) | [BitManipulation.cpp](./Algorithms/BitManipulation.cpp) |

### System design & other

| Topic | Material |
|-------|----------|
| REST | [RESTfulArchitecture.md](./System%20Design/RESTfulArchitecture.md) |
| Microservices | [Microservices.md](./System%20Design/Microservices.md) |
| Databases | [database-interview-prep-guide.md](./Databases/database-interview-prep-guide.md) |
| Git | [Git.md](./Version%20Control%20Systems/Git.md) |
| Full checklist PDF | [SDE-Interview-and-Prep-Roadmap.pdf](./SDE-Interview-and-Prep-Roadmap.pdf) |

---

## Must-know C++ for interviews

```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>          // queue, priority_queue
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>      // sort, lower_bound, next_permutation
#include <numeric>        // iota, accumulate
#include <climits>
```

Know: references vs pointers, pass-by-const-ref, iterators, lambdas for `sort`/`priority_queue`, complexity of each container.

---

## Complexity cheat sheet

| Structure | Access | Search | Insert | Delete |
|-----------|--------|--------|--------|--------|
| `vector` | O(1) | O(n) | O(1)* amort. back | O(n) |
| `list` / LL | O(n) | O(n) | O(1) at known node | O(1) at known node |
| `stack`/`queue` | — | — | O(1) | O(1) |
| `unordered_map` | — | O(1) avg | O(1) avg | O(1) avg |
| `map` / `set` | — | O(log n) | O(log n) | O(log n) |
| heap (`priority_queue`) | O(1) top | — | O(log n) | O(log n) |
| balanced BST | O(log n) | O(log n) | O(log n) | O(log n) |

\* reallocation amortized

---

## Weekly cadence (example 8 weeks)

| Week | Focus | Goal |
|------|-------|------|
| 1 | Arrays, HashMap, Two Pointers | 25 problems |
| 2 | Sliding Window, Binary Search, Stack | 25 problems |
| 3 | Linked List, Recursion basics | 20 problems |
| 4 | Trees (DFS/BFS/BST) | 25 problems |
| 5 | Heaps, Graphs, Union-Find | 25 problems |
| 6 | Backtracking + medium graphs | 20 problems |
| 7 | DP fundamentals | 25 problems |
| 8 | Mixed mocks + weak areas | timed contests |

Do **timed** practice (30–45 min/problem) in the last 2–3 weeks.

---

## How to use the `.cpp` files

```bash
g++ -std=c++17 -Wall -O2 -o demo "Data Structures/BinaryTree.cpp" && ./demo
g++ -std=c++17 -Wall -O2 -o demo Algorithms/DynamicProgramming.cpp && ./demo
```

Read the `.md` for the pattern, then re-implement the `.cpp` from memory on a whiteboard / empty file.

---

## Out of scope (intentionally)

The README checklist includes many niche topics (Tango trees, Pancake Sort, etc.). They are **not** FAANG coding staples. Prefer depth on the patterns above. Use the full checklist only after the core is strong.

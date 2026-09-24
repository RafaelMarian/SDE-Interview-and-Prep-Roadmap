# Arrays in C++

## Table of Contents
1. [Introduction](#introduction)
2. [Basic Concepts](#basic-concepts)
3. [C-Style Arrays](#c-style-arrays)
4. [std::array](#stdarray)
5. [std::vector (Dynamic Arrays)](#stdvector-dynamic-arrays)
6. [Intermediate Concepts](#intermediate-concepts)
7. [Advanced Concepts](#advanced-concepts)
8. [Array Algorithms](#array-algorithms)
9. [Memory Management](#memory-management)
10. [Practical Considerations](#practical-considerations)
11. [Top 50 Array Theory Questions](#top-50-array-theory-questions)

## Introduction
An array is a data structure that stores a collection of elements, typically of the same data type, in a contiguous block of memory. Elements are accessed using indices, which usually start at 0.

In C++, you will most often use:
- **C-style arrays** (`int arr[10];`) — fixed size, no bounds checking
- **`std::array`** — fixed-size wrapper with STL-friendly interface
- **`std::vector`** — dynamic array that can grow/shrink at runtime (the usual choice for interviews)

## Basic Concepts

### Array Properties
- **Fixed Size**: Traditional (C-style / `std::array`) arrays have a fixed size set at creation.
- **Homogeneity**: All elements must be of the same type (e.g., `int`, `double`, `std::string`).
- **Random Access**: Arrays allow constant time (O(1)) access to elements using their index.
- **Contiguous Memory Allocation**: Elements are stored in contiguous memory locations, which allows for efficient access and good cache locality.

### Array Representation in Memory
Arrays are stored in contiguous memory locations, so each element sits next to the previous one. Address of `arr[i]` is roughly `base + i * sizeof(T)`.

### Array Types
1. **Static Arrays**: Fixed size determined at compile time. Example: `int arr[10];`
2. **Dynamic Arrays**: Size can change at runtime. In C++, this is primarily `std::vector<T>`.

### Array Operations
- **Traversal**: Accessing each element one by one
- **Insertion**: Adding an element at a specific index (may require shifting)
- **Deletion**: Removing an element at a specific index (may require shifting)
- **Searching**: Linear O(n) or binary O(log n) if sorted
- **Sorting**: Various algorithms with different time complexities

## C-Style Arrays

### Creating Arrays
```cpp
#include <iostream>

int arr[5] = {1, 2, 3, 4, 5};   // fixed size, stack-allocated
int arr2[5] = {};               // all zeros
int arr3[] = {1, 2, 3};         // size deduced as 3
```

### Accessing Elements
```cpp
std::cout << arr[0] << "\n";                    // Output: 1
std::cout << arr[sizeof(arr)/sizeof(arr[0]) - 1] << "\n";  // Output: 5
```

### Modifying Elements
```cpp
arr[0] = 10;
std::cout << arr[0] << "\n";  // Output: 10
```

### Common Patterns
```cpp
// Iterate
for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
}

// Range-based for
for (int x : arr) {
    std::cout << x << " ";
}

// Pass to functions — decays to pointer (size is lost)
void print(int* a, int n) {
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
}
```

> **Caveat:** C-style arrays decay to pointers when passed to functions, so you must pass the size separately. Prefer `std::array` or `std::vector` in modern C++.

## std::array

Fixed-size array with value semantics and STL iterators.

```cpp
#include <array>
#include <iostream>

std::array<int, 5> arr = {1, 2, 3, 4, 5};

std::cout << arr[0] << "\n";       // 1
std::cout << arr.at(0) << "\n";    // 1 (throws std::out_of_range if invalid)
std::cout << arr.size() << "\n";   // 5
std::cout << arr.front() << " " << arr.back() << "\n";

arr.fill(0);  // set all elements to 0
```

## std::vector (Dynamic Arrays)

`std::vector` is the go-to dynamic array for C++ interviews and production code.

### Creating Vectors
```cpp
#include <vector>

std::vector<int> arr = {1, 2, 3, 4, 5};
std::vector<int> arr2(5);       // 5 default-initialized elements (0 for int)
std::vector<int> arr3(5, 42);   // 5 elements, each 42
std::vector<int> arr4;          // empty
```

### Accessing Elements
```cpp
std::cout << arr[0] << "\n";     // Output: 1
std::cout << arr.back() << "\n"; // Output: 5
std::cout << arr.at(0) << "\n";  // bounds-checked
```

### Modifying Elements
```cpp
arr[0] = 10;
std::cout << arr[0] << "\n";  // Output: 10
```

### Common Methods
```cpp
// Adding elements
arr.push_back(6);           // add to the end — amortized O(1)
arr.insert(arr.begin(), 0); // insert at beginning — O(n)

// Removing elements
arr.pop_back();                       // remove last — O(1)
arr.erase(arr.begin());               // remove first — O(n)
arr.erase(arr.begin() + 2);           // remove at index 2

// Size / capacity
arr.size();      // number of elements
arr.capacity();  // allocated storage
arr.empty();
arr.reserve(100);  // preallocate to avoid reallocations
arr.resize(10);    // grow/shrink to size 10
arr.clear();       // remove all elements

// Slicing (copy a range)
std::vector<int> sliced(arr.begin() + 1, arr.begin() + 3);  // elements [1, 3)

// Iterating
for (size_t i = 0; i < arr.size(); i++) {
    std::cout << i << " " << arr[i] << "\n";
}
for (int x : arr) {
    std::cout << x << "\n";
}
```

## Intermediate Concepts

### Multidimensional Arrays

#### C-style 2D
```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
std::cout << matrix[1][1] << "\n";  // Output: 5
```

#### vector of vectors
```cpp
std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
std::cout << matrix[1][1] << "\n";  // Output: 5
```

#### Contiguous 2D via flat vector (often better cache behavior)
```cpp
int rows = 3, cols = 3;
std::vector<int> flat(rows * cols);
auto at = [&](int r, int c) -> int& { return flat[r * cols + c]; };
at(1, 1) = 5;
```

### STL Algorithms on Arrays / Vectors
```cpp
#include <algorithm>
#include <numeric>

std::vector<int> arr = {1, 2, 3, 4, 5};

std::vector<int> doubled(arr.size());
std::transform(arr.begin(), arr.end(), doubled.begin(),
               [](int x) { return x * 2; });

std::vector<int> filtered;
std::copy_if(arr.begin(), arr.end(), std::back_inserter(filtered),
             [](int x) { return x > 2; });

int sum = std::accumulate(arr.begin(), arr.end(), 0);
```

## Advanced Concepts

### Higher-Dimensional Arrays
```cpp
// 3D via nested vectors
std::vector<std::vector<std::vector<int>>> tensor = {
    {{1, 2}, {3, 4}},
    {{5, 6}, {7, 8}}
};
std::cout << tensor[1][0][1] << "\n";  // Output: 6
```

### Dynamic Allocation (raw / smart pointers)
Prefer `std::vector` over raw `new[]`, but know the classic form for interviews:

```cpp
int* arr = new int[5]{1, 2, 3, 4, 5};
std::cout << arr[0] << "\n";
delete[] arr;  // must free

// Better: unique_ptr
#include <memory>
auto up = std::make_unique<int[]>(5);
up[0] = 42;
```

### Views (C++20)
```cpp
#include <span>

void process(std::span<int> s) {
    for (int x : s) { /* ... */ }
}

int a[5] = {1, 2, 3, 4, 5};
std::vector<int> v = {1, 2, 3};
process(a);  // works with C-array
process(v);  // works with vector
```

## Array Algorithms

### Searching Algorithms
1. **Linear Search**: O(n). Traverses sequentially.
2. **Binary Search**: O(log n). Requires a sorted array.
   ```cpp
   #include <algorithm>
   bool found = std::binary_search(arr.begin(), arr.end(), target);
   auto it = std::lower_bound(arr.begin(), arr.end(), target);
   ```

### Sorting Algorithms
1. **Bubble Sort** — O(n²), simple but slow
2. **Selection Sort** — O(n²)
3. **Insertion Sort** — O(n²), good for nearly sorted data
4. **Merge Sort** — O(n log n), stable
5. **Quick Sort** — O(n log n) average
6. **Heap Sort** — O(n log n), in-place

In practice use the standard library:
```cpp
std::sort(arr.begin(), arr.end());                    // typically introsort
std::stable_sort(arr.begin(), arr.end());             // merge-sort based
std::partial_sort(arr.begin(), arr.begin() + k, arr.end());
```

### Divide and Conquer
Algorithms like Merge Sort and Quick Sort divide the problem into subproblems, solve independently, and combine results.

### Dynamic Programming
Arrays/vectors store intermediate results (tabulation):
- Fibonacci series
- Longest Increasing Subsequence
- Knapsack / Coin Change DP tables

## Memory Management

### Contiguous Allocation
Arrays need a contiguous block. Large allocations can fail if memory is fragmented. `std::vector` may reallocate and move elements when capacity is exceeded (amortized growth, typically ×2).

### Fragmentation & Capacity
```cpp
std::vector<int> v;
v.reserve(1000);  // avoid repeated reallocations
std::cout << v.capacity() << "\n";
v.shrink_to_fit();  // request capacity == size (non-binding)
```

## Practical Considerations

### Initialization
```cpp
std::vector<int> arr(1000, 0);           // 1000 zeros
std::array<int, 1000> fixed{};           // value-initialized zeros
int c_arr[1000] = {};                    // zeros
```

### Boundary Conditions
- C-style `arr[i]` and `vector::operator[]` do **not** check bounds — undefined behavior if out of range.
- Use `.at(i)` when you want an exception on invalid index.
- Unlike Python, negative indices are **not** supported (`arr[-1]` is invalid).

### Performance Tuning
- Prefer `push_back` + `reserve` over repeated `insert` at the front.
- Prefer flat `vector` over nested `vector<vector<>>` when dimensions are known.
- Profile before micro-optimizing.

## Top 50 Array Theory Questions

1. **What is an array?**
   A contiguous collection of same-type elements accessible by index in O(1).

2. **How do you declare an array in C++?**
   - C-style: `int arr[10];`
   - `std::array`: `std::array<int, 10> arr;`
   - Dynamic: `std::vector<int> arr(10);`

3. **What are the advantages of using arrays?**
   - Efficient random access
   - Contiguous memory → good cache locality
   - Simple structure

4. **What are the disadvantages of using arrays?**
   - Fixed size (for static arrays)
   - Insertion/deletion in the middle is O(n)
   - Contiguous allocation can fail for very large sizes

5. **Explain the difference between a one-dimensional and a multi-dimensional array.**
   - 1D: `int arr[5] = {1, 2, 3, 4, 5};`
   - 2D: `int arr[3][4];` (3 rows, 4 columns)

6. **How do you initialize an array in C++?**
   ```cpp
   int arr[3] = {1, 2, 3};
   std::vector<int> v = {1, 2, 3};
   ```

7. **What is an array index?**
   A zero-based integer position. In `{10, 20, 30}`, `arr[0]` is 10.

8. **What is a dynamic array?**
   An array that can grow/shrink at runtime. In C++: `std::vector`.

9. **How do you find the length of an array?**
   - `std::vector` / `std::array`: `arr.size()`
   - C-style (only when not decayed): `sizeof(arr) / sizeof(arr[0])`

10. **What is array slicing?**
    Copying a contiguous range, e.g.:
    ```cpp
    std::vector<int> slice(arr.begin() + 1, arr.begin() + 4);
    ```

11. **What is a sparse array?**
    An array where most elements are zero/empty; often stored with maps or compressed formats.

12. **Explain how arrays are stored in memory.**
    Contiguously: address of element `i` is `base + i * sizeof(T)`.

13. **What is a jagged array?**
    An array of arrays with unequal row lengths:
    ```cpp
    std::vector<std::vector<int>> jagged = {{1}, {2, 3}, {4, 5, 6}};
    ```

14. **How do you copy elements from one array to another?**
    ```cpp
    std::vector<int> destination = source;  // copy constructor
    std::copy(source.begin(), source.end(), destination.begin());
    ```

15. **Explain the difference between an array and a list (linked list).**
    - **Array:** contiguous, O(1) access, costly middle insert/delete
    - **Linked list:** nodes + pointers, O(n) access, cheap insert/delete at known positions

16. **How do you reverse an array?**
    ```cpp
    std::reverse(arr.begin(), arr.end());
    ```

17. **What is an associative array?**
    Key-value map. In C++: `std::map` / `std::unordered_map`.

18. **What is the time complexity of accessing an element in an array?**
    O(1)

19. **How do you find the largest element in an array?**
    ```cpp
    int max_val = *std::max_element(arr.begin(), arr.end());
    // or manually:
    int max_val = arr[0];
    for (int num : arr) if (num > max_val) max_val = num;
    ```

20. **How do you find the smallest element in an array?**
    ```cpp
    int min_val = *std::min_element(arr.begin(), arr.end());
    ```

21. **Explain the concept of array rotation.**
    Shift elements left/right by `k` positions.
    Example (left by 2): `{1,2,3,4,5}` → `{3,4,5,1,2}`
    ```cpp
    std::rotate(arr.begin(), arr.begin() + 2, arr.end());
    ```

22. **What is an array buffer?**
    Contiguous raw storage for elements (e.g. `vector`’s internal buffer, or `std::byte` buffers).

23. **How do you merge two arrays?**
    ```cpp
    std::vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    ```

24. **Explain how to remove duplicates from an array.**
    ```cpp
    std::sort(arr.begin(), arr.end());
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    ```

25. **What is a circular array?**
    Logical wrap-around from end to start (used in ring buffers / circular queues). Index via `i % n`.

26. **How do you implement a dynamic array?**
    Allocate a larger buffer, move/copy elements, free the old buffer; grow capacity (often ×2). This is what `std::vector` does.

27. **What is the difference between shallow and deep copying of arrays?**
    - **Shallow:** copy the container of pointers; nested objects shared
    - **Deep:** recursively copy nested objects so each side owns its data
    `std::vector` of values is a deep copy of elements; `vector` of raw pointers is shallow regarding pointed-to objects.

28. **How do you find the sum of all elements in an array?**
    ```cpp
    int total = std::accumulate(arr.begin(), arr.end(), 0);
    ```

29. **What is a sentinel in an array?**
    A special end marker value used to stop a loop without tracking length separately.

30. **Explain array-based queue implementation.**
    Store elements in an array/vector with `front` and `rear` indices (often circular).

31. **How do you find the median of an unsorted array?**
    ```cpp
    std::nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
    int median = arr[arr.size() / 2];
    ```

32. **What is the difference between an array and a linked list?**
    Arrays: contiguous + random access. Linked lists: non-contiguous nodes + sequential access.

33. **Explain the process of binary search on an array.**
    ```cpp
    int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0, right = (int)arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    ```

34. **What is the time complexity of inserting an element at the beginning of an array?**
    O(n) — all elements must shift right.

35. **How do you find the second largest element in an array?**
    ```cpp
    int first = INT_MIN, second = INT_MIN;
    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }
    ```

36. **What is an in-place algorithm regarding arrays?**
    Transforms the input using O(1) extra space (beyond a few variables), mutating the existing array.

37. **How do you implement a stack using an array?**
    ```cpp
    class Stack {
        std::vector<int> data;
    public:
        void push(int v) { data.push_back(v); }
        void pop() { if (!data.empty()) data.pop_back(); }
        int top() const { return data.back(); }
        bool empty() const { return data.empty(); }
    };
    ```

38. **Explain the difference between row-major and column-major order.**
    - **Row-major** (C/C++): rows stored contiguously
    - **Column-major** (Fortran/MATLAB): columns stored contiguously

39. **What is a permutation of an array?**
    A rearrangement of its elements into a different order.
    ```cpp
    std::next_permutation(arr.begin(), arr.end());
    ```

40. **How do you sort an array?**
    ```cpp
    std::sort(arr.begin(), arr.end());
    ```

41. **What is an immutable array?**
    Elements cannot change after creation. C++ has no built-in immutable array type; approximate with `const std::array` / `const std::vector`, or use libraries.

42. **How do you check if an array is sorted?**
    ```cpp
    bool isSorted(const std::vector<int>& arr) {
        return std::is_sorted(arr.begin(), arr.end());
    }
    ```

43. **What is a frequency array?**
    An array counting occurrences of each value (common for digits / limited alphabets):
    ```cpp
    int freq[26] = {};
    for (char c : s) freq[c - 'a']++;
    ```

44. **How do you concatenate two arrays?**
    ```cpp
    std::vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    ```

45. **What is an array literal?**
    Brace initialization: `int arr[] = {1, 2, 3};` or `std::vector<int> v{1, 2, 3};`

46. **How do you find the intersection of two arrays?**
    ```cpp
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::vector<int> inter;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                          std::back_inserter(inter));
    ```

47. **What is a subarray?**
    A contiguous segment of an array. In `{1,2,3,4,5}`, `{2,3,4}` is a subarray (not the same as subsequence).

48. **How do you implement array-based heap?**
    Parent/child via indices:
    - Parent: `(i - 1) / 2`
    - Left child: `2 * i + 1`
    - Right child: `2 * i + 2`
    Or use `std::priority_queue` / `std::make_heap`.

49. **What is a bit array?**
    Compact storage of bits (`std::bitset`, `std::vector<bool>`, or manual bit packing).

50. **How do you find the majority element in an array?**
    Boyer–Moore Voting Algorithm:
    ```cpp
    int findMajority(const std::vector<int>& arr) {
        int count = 0, candidate = 0;
        for (int num : arr) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        int freq = std::count(arr.begin(), arr.end(), candidate);
        return (freq > (int)arr.size() / 2) ? candidate : -1;
    }
    ```

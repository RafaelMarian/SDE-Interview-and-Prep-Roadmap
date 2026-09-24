# LC 23. Merge k Sorted Lists
**Lists:** Top 150  
**Topic:** Heap  
**Difficulty:** Hard

## Problem (short + example)

Merge `k` sorted linked lists into one sorted list.

**Example:** `[1→4→5], [1→3→4], [2→6]` → `1 → 1 → 2 → 3 → 4 → 4 → 5 → 6`.

## Intuition

Always pick the smallest current head among lists — a min-heap of size k does this efficiently.

## Approach

1. Push head of each non-empty list on min-heap (compare by node value).
2. Pop smallest, attach to result tail, push its `next` if any.
3. Return dummy.next.

## Complexity

- **Time:** O(N log k) where N is total nodes  
- **Space:** O(k)

## C++ Solution

```cpp
class Solution {
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (ListNode* h : lists)
            if (h) pq.push(h);
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
```

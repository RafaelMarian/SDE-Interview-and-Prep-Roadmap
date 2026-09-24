# 23. Merge k Sorted Lists

**Lists:** Top Interview 150  
**Topic:** Heap  
**Difficulty:** Hard  

## Problem

You are given an array of `k` linked lists, each sorted in ascending order. Merge all lists into one sorted linked list and return it.

## Intuition

The smallest next node among all list heads is the next global minimum. Keep those heads in a min-heap keyed by node value.

## Approach

1. Push the head of each non-null list into a min-heap (compare by `ListNode*` value).
2. Pop the smallest node, append to a dummy tail, push its `next` if non-null.
3. Continue until the heap is empty.

## Complexity

- **Time:** O(N log k) where N is total nodes, k is number of lists
- **Space:** O(k) for the heap

## C++ Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (ListNode* head : lists)
            if (head) pq.push(head);

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) pq.push(node->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
```

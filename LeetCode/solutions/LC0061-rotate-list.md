# LC 61. Rotate List
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Rotate the list to the right by `k` places.

**Example:** `1 → 2 → 3 → 4 → 5`, k=2 → `4 → 5 → 1 → 2 → 3`.

## Intuition

Make the list circular, then break at `(length - k % length)`-th node from the start.

## Approach

1. Count length `n`; find tail.
2. `k %= n`; if `k == 0` return head.
3. Connect tail to head; new tail is `n - k` steps from old head; break link after it.
4. Return new head.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next) { tail = tail->next; ++n; }
        k %= n;
        if (k == 0) return head;
        tail->next = head;
        int steps = n - k;
        ListNode* newTail = head;
        while (--steps) newTail = newTail->next;
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
```

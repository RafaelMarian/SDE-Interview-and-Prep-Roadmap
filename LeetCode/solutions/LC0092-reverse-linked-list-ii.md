# LC 92. Reverse Linked List II
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Reverse the sublist from position `left` to `right` (1-indexed). Return the head.

**Example:** `1 → 2 → 3 → 4 → 5`, left=2, right=4 → `1 → 4 → 3 → 2 → 5`.

## Intuition

Find the node before the sublist, reverse `right - left + 1` nodes in place, then reconnect tails.

## Approach

1. Dummy before head; advance to node at `left - 1` (`prev`).
2. `cur = prev->next`; repeat `right - left` times: move `cur->next` before `prev->next` (standard partial reverse).
3. Return `dummy.next`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        for (int i = 0; i < left - 1; ++i) prev = prev->next;
        ListNode* cur = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        return dummy.next;
    }
};
```

# LC 25. Reverse Nodes in k-Group
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Hard

## Problem (short + example)

Reverse nodes in groups of `k`. If fewer than `k` nodes remain, leave them as-is.

**Example:** `1 → 2 → 3 → 4 → 5`, k=2 → `2 → 1 → 4 → 3 → 5`.

## Intuition

For each group, check that `k` nodes exist, reverse that segment, then link the reversed block to the rest.

## Approach

1. Dummy head; `prevGroupEnd` starts at dummy.
2. While true: find `k`th node from `prevGroupEnd`; if missing, break.
3. Reverse nodes between `groupStart` and `k`th; connect `prevGroupEnd->next` to new head and old head to next group.
4. Advance `prevGroupEnd` to old group head (now tail).

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prevEnd = &dummy;
        while (true) {
            ListNode* kth = prevEnd;
            for (int i = 0; i < k && kth; ++i) kth = kth->next;
            if (!kth) break;
            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* cur = prevEnd->next;
            while (cur != groupNext) {
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            ListNode* oldStart = prevEnd->next;
            prevEnd->next = kth;
            prevEnd = oldStart;
        }
        return dummy.next;
    }
};
```

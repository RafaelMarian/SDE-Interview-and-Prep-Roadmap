# LC 82. Remove Duplicates from Sorted List II
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Delete all nodes that have duplicate values (keep only nodes that appear once).

**Example:** `1 → 2 → 3 → 3 → 4 → 4 → 5` → `1 → 2 → 5`.

## Intuition

If the node after `prev` duplicates, skip the entire run of that value, then link `prev` past it.

## Approach

1. Dummy; `prev` before the list being built.
2. While `cur`: if `cur` equals `cur->next`, advance `cur` while value repeats, then `prev->next = cur`.
3. Else advance both `prev` and `cur`.
4. Return `dummy.next`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next) {
            ListNode* cur = prev->next;
            if (cur->next && cur->val == cur->next->val) {
                int v = cur->val;
                while (cur && cur->val == v) cur = cur->next;
                prev->next = cur;
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};
```

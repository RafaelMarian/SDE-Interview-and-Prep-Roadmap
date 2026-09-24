# LC 19. Remove Nth Node From End of List
**Lists:** Blind 75 · Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Remove the **n**th node from the end of the list (1-indexed) and return the head.

**Example:** `1 → 2 → 3 → 4 → 5`, n = 2 → `1 → 2 → 3 → 5`.

## Intuition

If the gap between two pointers is **n**, when the fast pointer hits the end, the slow pointer sits just before the node to delete. A dummy head handles removing the first node.

## Approach

1. Dummy node before `head`; `fast` and `slow` start at dummy.
2. Advance `fast` **n + 1** steps so `slow` is `(n+1)`-th from the end.
3. Move both until `fast` is null; `slow->next = slow->next->next`.
4. Return `dummy.next`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for (int i = 0; i <= n; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
```

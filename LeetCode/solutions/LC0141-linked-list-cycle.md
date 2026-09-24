# LC 141. Linked List Cycle
**Lists:** Blind 75 · Top 150  
**Topic:** Linked List  
**Difficulty:** Easy

## Problem (short + example)

Return `true` if the linked list has a cycle (some node’s `next` points back to a previous node).

**Example:** `3 → 2 → 0 → -4` with `-4.next → 2` → `true`.

## Intuition

In a cycle, fast (2 steps) eventually laps slow (1 step) inside the loop—they meet. If there is no cycle, fast reaches `nullptr`.

## Approach

1. `slow = head`, `fast = head`.
2. While `fast` and `fast->next`, advance slow by 1 and fast by 2.
3. If they meet, return `true`; if loop ends, return `false`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
```

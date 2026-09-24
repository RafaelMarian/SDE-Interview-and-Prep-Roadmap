# LC 143. Reorder List
**Lists:** Blind 75 · Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Reorder `L0 → L1 → … → Ln-1 → Ln` to `L0 → Ln → L1 → Ln-1 → …`.

**Example:** `1 → 2 → 3 → 4` → `1 → 4 → 2 → 3`.

## Intuition

Split the list in half, reverse the second half, then weave the two halves together. Finding the middle with slow/fast pointers avoids extra arrays.

## Approach

1. Find the middle with slow/fast pointers; break the list after the middle.
2. Reverse the second half.
3. Merge alternating nodes from first and second halves.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        second = prev;

        ListNode* first = head;
        while (second) {
            ListNode* fNext = first->next;
            ListNode* sNext = second->next;
            first->next = second;
            second->next = fNext;
            first = fNext;
            second = sNext;
        }
    }
};
```

# LC 86. Partition List
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Partition so all nodes `< x` come before nodes `>= x`. Preserve relative order within each part.

**Example:** `1 → 4 → 3 → 2 → 5 → 2`, x=3 → `1 → 2 → 2 → 4 → 3 → 5`.

## Intuition

Maintain two separate chains (less and greater-or-equal), then concatenate.

## Approach

1. Dummy heads for `less` and `ge`; tails track ends.
2. For each node, append to the appropriate list.
3. Link `less` tail to `ge` head; set `ge` tail’s `next` to null.
4. Return `lessDummy.next`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), geDummy(0);
        ListNode* lessTail = &lessDummy;
        ListNode* geTail = &geDummy;
        while (head) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = lessTail->next;
            } else {
                geTail->next = head;
                geTail = geTail->next;
            }
            head = head->next;
        }
        geTail->next = nullptr;
        lessTail->next = geDummy.next;
        return lessDummy.next;
    }
};
```

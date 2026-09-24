# LC 21. Merge Two Sorted Lists
**Lists:** Blind 75 · Top 150  
**Topic:** Linked List  
**Difficulty:** Easy

## Problem (short + example)

Merge two sorted linked lists into one sorted list. Return the merged list's head.

**Example:** `1 → 2 → 4` and `1 → 3 → 4` → `1 → 1 → 2 → 3 → 4 → 4`.

## Intuition

Always attach the smaller current node to the tail of the result. A dummy head simplifies pointer updates.

## Approach

1. Create dummy node; `tail` points at dummy.
2. While both lists have nodes, link the smaller value to `tail->next` and advance that list.
3. Attach the non-empty remainder.
4. Return `dummy.next`.

## Complexity

- **Time:** O(n + m)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
```

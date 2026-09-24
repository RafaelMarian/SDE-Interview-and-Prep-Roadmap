# LC 148. Sort List

**Lists:** Top 150
**Topic:** Linked List / Merge Sort
**Difficulty:** Medium

## Problem
Given the head of a linked list, sort the list in O(n log n) time and O(1) constant space (ignoring recursion stack). Example: `4 -> 2 -> 1 -> 3` becomes `1 -> 2 -> 3 -> 4`.

## Intuition
Merge sort on a linked list: find middle with slow/fast pointers, recursively sort halves, merge two sorted lists.

## Approach
1. Base: null or single node.
2. Split at middle (second half starts at `slow->next` after finding `slow`).
3. `left = sortList(head)`, `right = sortList(slow->next)`, `slow->next = nullptr`.
4. Return `merge(left, right)` with standard two-pointer merge.

## Complexity
- Time: O(n log n)
- Space: O(log n) recursion depth

## C++ Solution
```cpp
class Solution {
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};
```

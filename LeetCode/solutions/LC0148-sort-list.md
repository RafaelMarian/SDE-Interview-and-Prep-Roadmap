# LC 148. Sort List

**Lists:** Top 150  
**Topic:** Linked List / Merge Sort  
**Difficulty:** Medium

## Problem
Sort a linked list in O(n log n) time and O(1) extra space (merge sort is accepted).

## Intuition
Merge sort: split with slow/fast, sort halves, merge.

## Approach
1. Base: 0/1 node.  
2. Find mid, cut list.  
3. Recurse both halves; merge sorted lists.

## Complexity
- Time: O(n log n)
- Space: O(log n) recursion

## C++ Solution
```cpp
class Solution {
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0), *t = &dummy;
        while (a && b) {
            if (a->val < b->val) { t->next = a; a = a->next; }
            else { t->next = b; b = b->next; }
            t = t->next;
        }
        t->next = a ? a : b;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }
};
```

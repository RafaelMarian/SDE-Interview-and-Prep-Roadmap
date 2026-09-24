# LC 206. Reverse Linked List
**Lists:** Blind 75 · Top 150  
**Topic:** Linked List  
**Difficulty:** Easy

## Problem (short + example)

Reverse a singly linked list and return the new head.

**Example:** `1 → 2 → 3 → 4 → 5` becomes `5 → 4 → 3 → 2 → 1`.

## Intuition

Walk the list once while rewiring each node's `next` to point backward. Keep a pointer to the already-reversed prefix so you never lose the rest of the list.

## Approach

1. Initialize `prev = nullptr`.
2. While `head` is non-null, save `head->next`, set `head->next = prev`, advance `prev` to `head`, advance `head` to the saved next.
3. Return `prev` as the new head.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
// struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};
```

# LC 2. Add Two Numbers
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Add two numbers represented as linked lists (digits in reverse order). Return the sum as a linked list.

**Example:** `2 → 4 → 3` + `5 → 6 → 4` → `7 → 0 → 8` (342 + 465 = 807).

## Intuition

Walk both lists like elementary addition: add digits plus carry, build a new node for each result digit.

## Approach

1. Dummy head; `carry = 0`.
2. While either list has nodes or `carry > 0`, sum digit values + carry, append `sum % 10`, carry `sum / 10`.
3. Return `dummy.next`.

## Complexity

- **Time:** O(max(n, m))  
- **Space:** O(1) extra (output length excluded)

## C++ Solution

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) { carry += l1->val; l1 = l1->next; }
            if (l2) { carry += l2->val; l2 = l2->next; }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return dummy.next;
    }
};
```

# LC 117. Populating Next Right Pointers in Each Node II
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Connect each node to its next right node (same level). The `next` field may already exist on the node type.

**Example:** Perfect or imperfect tree — level 2 nodes all link left-to-right.

## Intuition

For each level, thread children using a `tail` pointer on the next level while walking via `next`.

## Approach

1. `cur` starts at root; while `cur`:
2. Dummy for next level; `tail` builds the linked list of children.
3. For each node on this level (via `next`), attach left/right child to `tail`.
4. `cur = dummy.next` for next iteration.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while (cur) {
            Node dummy(0);
            Node* tail = &dummy;
            for (Node* p = cur; p; p = p->next) {
                if (p->left) {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if (p->right) {
                    tail->next = p->right;
                    tail = tail->next;
                }
            }
            cur = dummy.next;
        }
        return root;
    }
};
```

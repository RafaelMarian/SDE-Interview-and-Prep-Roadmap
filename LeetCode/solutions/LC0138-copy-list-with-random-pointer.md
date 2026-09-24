# LC 138. Copy List with Random Pointer
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Deep copy a linked list where each node has `next` and `random` (random may point to any node or null).

**Example:** `[[7,null],[13,0],[11,4],[10,2],[1,0]]` → a new list with the same structure.

## Intuition

Map each original node to its clone so random pointers can be wired in a second pass.

## Approach

1. First pass: for each node, create clone and store `old → clone` in a hash map.
2. Second pass: set each clone’s `next` and `random` from the map.
3. Return clone of head.

## Complexity

- **Time:** O(n)  
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        for (Node* cur = head; cur; cur = cur->next)
            mp[cur] = new Node(cur->val);
        for (Node* cur = head; cur; cur = cur->next) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];
    }
};
```

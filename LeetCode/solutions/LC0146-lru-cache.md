# LC 146. LRU Cache
**Lists:** Top 150  
**Topic:** Linked List  
**Difficulty:** Medium

## Problem (short + example)

Design an LRU cache: `get(key)` and `put(key, value)` in O(1). Evict least recently used when capacity is exceeded.

**Example:** capacity 2: `put(1,1)`, `put(2,2)`, `get(1)→1`, `put(3,3)` evicts key 2, `get(2)→-1`.

## Intuition

Hash map for O(1) lookup plus doubly linked list for O(1) move-to-front and eviction at the tail.

## Approach

1. `unordered_map<key, list_iterator>` and `list<pair<key,val>>` (front = MRU).
2. `get`: if missing return -1; else move node to front, return value.
3. `put`: if key exists, update and move to front; else push front, if size > capacity erase map entry for list back and pop back.

## Complexity

- **Time:** O(1) per operation  
- **Space:** O(capacity)

## C++ Solution

```cpp
class LRUCache {
    int cap;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        order.push_front(*it->second);
        order.erase(it->second);
        it->second = order.begin();
        return order.begin()->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            order.erase(it->second);
            mp.erase(it);
        } else if ((int)order.size() == cap) {
            mp.erase(order.back().first);
            order.pop_back();
        }
        order.push_front({key, value});
        mp[key] = order.begin();
    }
};
```

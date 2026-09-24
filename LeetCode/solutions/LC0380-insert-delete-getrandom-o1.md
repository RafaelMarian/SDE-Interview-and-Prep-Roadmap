# LC 380. Insert Delete GetRandom O(1)

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Design a set that supports `insert`, `remove`, and `getRandom` in average O(1) time. `getRandom` returns a uniformly random element from the set.

## Intuition
Store elements in a vector for O(1) random access and a hash map from value to index for O(1) lookup. On delete, swap the target with the last element, update the map, and pop the back.

## Approach
- `insert`: append if absent; map value → index.
- `remove`: swap-with-last in the vector; update map; pop back.
- `getRandom`: pick random index in the vector.

## Complexity
- Time: O(1) average per operation
- Space: O(n)

## C++ Solution
```cpp
class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> idx;

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (idx.count(val)) {
            return false;
        }
        idx[val] = static_cast<int>(vals.size());
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) {
            return false;
        }
        int i = it->second;
        int last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(it);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
```

# LC 205. Isomorphic Strings

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Easy

## Problem
Given two strings `s` and `t`, determine if they are isomorphic: there is a one-to-one mapping of characters in `s` to characters in `t` preserving order.

## Intuition
Maintain maps `s → t` and `t → s`; each new pair must agree with existing mappings in both directions.

## Approach
1. For each index `i`, let `a = s[i]`, `b = t[i]`.
2. If `a` is mapped to a different char or `b` is mapped from a different char, return false.
3. Set both mappings and continue.
4. Return true.

## Complexity
- Time: O(n)
- Space: O(alphabet)

## C++ Solution
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        array<int, 256> mapS{}, mapT{};
        fill(mapS.begin(), mapS.end(), -1);
        fill(mapT.begin(), mapT.end(), -1);
        for (size_t i = 0; i < s.size(); ++i) {
            unsigned char a = s[i], b = t[i];
            if (mapS[a] != -1 && mapS[a] != static_cast<int>(b)) {
                return false;
            }
            if (mapT[b] != -1 && mapT[b] != static_cast<int>(a)) {
                return false;
            }
            mapS[a] = b;
            mapT[b] = a;
        }
        return true;
    }
};
```

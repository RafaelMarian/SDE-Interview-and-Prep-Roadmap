# Hash Map & Hash Set

Average O(1) lookup/insert/delete. First tool for “count / seen / complement” problems.

## C++ containers

```cpp
std::unordered_map<Key, Value> mp;  // hash table — prefer in interviews
std::unordered_set<Key> st;

std::map<Key, Value> ordered;       // tree map — O(log n), sorted keys
std::set<Key> ordered_set;
```

Custom hash rarely needed; for `pair` keys use nested maps or encode as `long long`.

## When it shows up

- Two Sum / complementary pairs
- Frequency counting / anagrams
- Prefix-sum + map (subarray sum equals K)
- Grouping (group anagrams)
- Caching DFS results / memo keys
- Graph adjacency as `unordered_map<int, vector<int>>`

## Patterns

### Two Sum
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

### Prefix sum + map
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq{{0, 1}};
    int sum = 0, ans = 0;
    for (int x : nums) {
        sum += x;
        ans += freq[sum - k];
        freq[sum]++;
    }
    return ans;
}
```

## Complexity
`unordered_*`: **O(1)** average, **O(n)** worst (rare with ints/strings).  
`map`/`set`: **O(log n)** always.

## Pitfalls
- `mp[key]` **inserts** default if missing — use `.count()` / `.find()` to test
- Iterating `unordered_map` order is random
- Floating-point keys are a bad idea

## Practice
| # | Problem |
|---|---------|
| LC 1 | Two Sum |
| LC 49 | Group Anagrams |
| LC 128 | Longest Consecutive Sequence |
| LC 560 | Subarray Sum Equals K |
| LC 3 | Longest Substring Without Repeating (map + window) |

See [`HashMap.cpp`](./HashMap.cpp).

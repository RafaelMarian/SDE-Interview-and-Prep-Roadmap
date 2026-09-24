# LC 271. Encode and Decode Strings

**Lists:** Blind 75
**Topic:** Arrays & Hashing
**Difficulty:** Medium

## Problem
Design an encoder/decoder for a list of strings so that `decode(encode(strs))` returns the original list. Strings may contain any characters. Example: `["hello","world"]` encodes to a single string and decodes back unchanged.

## Intuition
Delimiter-only schemes break when strings contain the delimiter. Prefix each substring with its byte length and a separator (e.g. `length#payload`), so the decoder knows exactly how many characters to read next.

## Approach
1. **Encode:** For each string `s`, append `to_string(s.size()) + '#' + s`.
2. **Decode:** Scan with index `i`; read digits until `#`, parse length `L`, take `L` chars after `#` as one string, advance `i`.
3. Repeat until the buffer is consumed.

## Complexity
- Time: O(total characters) encode and decode
- Space: O(total characters) for output

## C++ Solution
```cpp
class Codec {
public:
    string encode(vector<string>& strs) {
        string out;
        for (const string& s : strs) {
            out += to_string(s.size());
            out += '#';
            out += s;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;
        while (i < s.size()) {
            size_t j = i;
            while (s[j] != '#') {
                ++j;
            }
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }
};
```

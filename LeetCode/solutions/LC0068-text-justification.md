# LC 68. Text Justification

**Lists:** Top 150
**Topic:** String
**Difficulty:** Hard

## Problem
Given an array of words and a max width `maxWidth`, format text so each line is exactly `maxWidth` characters long and fully justified. Pack as many words as possible per line; pad with spaces so the last line is left-justified with no extra spaces between words except single spaces.

## Intuition
Greedy line packing: grow a line until the next word would exceed width. Distribute extra spaces evenly between words (extra spaces go to left gaps first), except the last line uses single spaces between words.

## Approach
1. Index `i` over words; for each line, find max `j` such that words `i..j` fit with single spaces.
2. Compute total chars and spaces to distribute; build the line string.
3. Last line or single-word line: left justify with one space between words, pad right.
4. Push line and set `i = j + 1`.

## Complexity
- Time: O(n · maxWidth) over total characters
- Space: O(maxWidth) per line output

## C++ Solution
```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = static_cast<int>(words.size());
        int i = 0;
        while (i < n) {
            int j = i, len = 0;
            while (j < n) {
                int need = len + static_cast<int>(words[j].size()) + (j > i ? 1 : 0);
                if (need > maxWidth) {
                    break;
                }
                len = need;
                ++j;
            }
            int gaps = j - i - 1;
            string line;
            if (j == n || gaps == 0) {
                for (int k = i; k < j; ++k) {
                    if (k > i) {
                        line += ' ';
                    }
                    line += words[k];
                }
                line += string(maxWidth - static_cast<int>(line.size()), ' ');
            } else {
                int totalChars = 0;
                for (int k = i; k < j; ++k) {
                    totalChars += static_cast<int>(words[k].size());
                }
                int spaces = maxWidth - totalChars;
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i; k < j; ++k) {
                    if (k > i) {
                        line += string(spaceEach + (k - i <= extra ? 1 : 0), ' ');
                    }
                    line += words[k];
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};
```

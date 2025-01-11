/*
3. Longest Substring Without Repeating Characters


Description:

Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int out = 0;
        int start_pos = 0;
        unordered_map<char, size_t> last_pos;
        size_t i = 0;
        while (i < s.size())
        {
            unordered_map<char, size_t>::iterator it = last_pos.find(s[i]);
            if (it != last_pos.end() && (it->second >= start_pos))
            {
                if (i - start_pos > out)
                {
                    out = i - start_pos;
                }
                start_pos = it->second + 1;
            }
            last_pos[s[i]] = i;
            ++i;
        }
        if (i - start_pos > out)
        {
            out = i - start_pos;
        }
        return out;
    }
};


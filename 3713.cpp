/*
3713. Longest Balanced Substring I


Description:

You are given a string s consisting of lowercase English letters.

A of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

 

Example 1:

Input: s = "abbac"

Output: 4

Explanation:

The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Example 2:

Input: s = "zzabccy"

Output: 4

Explanation:

The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​

Example 3:

Input: s = "aba"

Output: 2

Explanation:

​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

Constraints:

    1 <= s.length <= 1000
    s consists of lowercase English letters.


*/

class Solution {
    bool checkBalanced(const unordered_map<int, int>& chars) {
        int cnt = chars.begin()->second;
        for (unordered_map<int, int>::const_iterator it = chars.cbegin(); it != chars.cend(); it++) {
            if (it->second != cnt) {
                return false;
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int out = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int> chars;
            for (int j = i; j < s.size(); j++) {
                chars[s[j]] += 1;
                if (checkBalanced(chars)) {
                    out = max(out, j - i + 1);
                }
            }
        }
        return out;
    }
};

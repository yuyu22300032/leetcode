/*
5. Longest Palindromic Substring


Description:

Given a string s, return the longest
palindromic
substring
in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.


*/

class Solution {
public:
    string longestPalindrome(string s) {
        int sidx = 0;
        int len = 1;
        for (int i = 1; i < s.size(); i++)
        {
            int extend = 0;
            while (i - 1 - extend >= 0 && i + extend < s.size())
            {
                if (s[i-1-extend] != s[i+extend])
                {
                    break;
                }
                if (extend * 2 + 2 > len)
                {
                    len = extend * 2 + 2;
                    sidx = i-1-extend;
                }
                extend++;
            }
            extend = 1;
            while (i - extend >= 0 && i + extend < s.size())
            {
                if (s[i-extend] != s[i+extend])
                {
                    break;
                }
                if (extend * 2 + 1 > len)
                {
                    len = extend * 2 + 1;
                    sidx = i-extend;
                }
                extend++;
            }
        }
        return s.substr(sidx, len);
    }
};


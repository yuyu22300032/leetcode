/*
28. Find the Index of the First Occurrence in a String


Description:

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 

Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.


*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            bool is_part = true;
            for (int j = 0; j < needle.size(); ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    is_part = false;
                    break;
                }
            }
            if (is_part)
            {
                return i;
            }
        }
        return -1;
    }
};


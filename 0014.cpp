/*
14. Longest Common Prefix


Description:

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.


*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int plen = strs[0].size();
        for (int i = 1; i < strs.size(); ++i)
        {
            if (plen > strs[i].size())
            {
                plen = strs[i].size();
            }
            for (int j = 0; j < plen; ++j)
            {
                if (strs[0][j] != strs[i][j])
                {
                    plen = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, plen);
    }
};


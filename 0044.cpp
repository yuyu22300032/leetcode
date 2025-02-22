/*
44. Wildcard Matching


Description:

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

 

Constraints:

    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.


*/

class Solution {
public:
    bool cacheTry(string& s, string& p, int s_idx, int p_idx, vector<vector<bool>>& search_table)
    {
        if (search_table[s_idx][p_idx])
        {
            return false;
        }
        if (tryMatch(s, p, s_idx, p_idx, search_table))
        {
            return true;
        }
        search_table[s_idx][p_idx] = true;
        return false;
    }
    bool tryMatch(string& s, string& p, int s_idx, int p_idx, vector<vector<bool>>& search_table)
    {
        if (s_idx == s.size())
        {
            if (p_idx == p.size())
            {
                return true;
            }
            if (p.size() - p_idx > 1)
            {
                return false;
            }
            return p[p_idx] == '*';
        }
        if (p_idx == p.size())
        {
            return false;
        }
        for (int i = p_idx; i < p.size(); ++i)
        {
            if (p[i] == '?')
            {
                s_idx++;
            }
            else if (p[i] == '*')
            {
                for (int j = s_idx; j <= s.size(); ++j)
                {
                    if (cacheTry(s, p, j, i + 1, search_table))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (s[s_idx] != p[i])
                {
                    return false;
                }
                s_idx++;
            }
        }
        return s_idx == s.size();
    }

    bool isMatch(string s, string p) {
        if (! p.empty())
        {
            string new_p;
            new_p.push_back(p[0]);
            for (int i = 1; i < p.size(); ++i)
            {
                if (p[i] == '*' && p[i-1] == '*')
                {
                    continue;
                }
                new_p.push_back(p[i]);
            }
            p = new_p;
        }
        vector<vector<bool>> search_table(s.size() + 1, vector<bool>(p.size() + 1, false));
        return cacheTry(s, p, 0, 0, search_table);
    }
};
/*
10. Regular Expression Matching


Description:

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

 

Constraints:

    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.



*/

class Solution {
public:
    bool isMatch(string s, string p) {
        list< pair<int, int> > idxs;
        idxs.push_back(make_pair(s.size() - 1, p.size() - 1));
        while (idxs.size() > 0)
        {
            pair<int, int> &cur = idxs.front();
            while (cur.second >= 0 && cur.first >= 0)
            {
                switch (p[cur.second])
                {
                    case '*':
                    {
                        cur.second--;
                        if (cur.second > 0)
                        {
                            idxs.push_back(make_pair(cur.first, cur.second-1));
                        }
                        while (p[cur.second] == '.' || s[cur.first] == p[cur.second])
                        {
                            if (cur.first > 0 && cur.second > 0)
                            {
                                idxs.push_back(make_pair(cur.first-1, cur.second-1));
                                cur.first--;
                                continue;
                            }
                            if (cur.first == 0)
                            {
                                if (cur.second % 2 == 0)
                                {
                                    bool yuyu = true;
                                    for (int i = 1; i < cur.second; i += 2)
                                    {
                                        if (p[i] != '*')
                                        {
                                            yuyu = false;
                                            break;
                                        }
                                    }
                                    if (yuyu)
                                    {
                                        return true;
                                    }
                                }
                                break;
                            }
                            cur.first--;
                        }
                        break;
                    }
                    case '.':
                    {
                        if (cur.first == 0 && cur.second == 0)
                        {
                            return true;
                        }
                        if (cur.first == 0)
                        {
                            if (cur.second % 2 == 0)
                            {
                                bool yuyu = true;
                                for (int i = 1; i < cur.second; i+=2)
                                {
                                    if (p[i] != '*')
                                    {
                                        yuyu = false;
                                        break;
                                    }
                                }
                                if (yuyu)
                                {
                                    return true;
                                }
                            }
                        }
                        if (cur.first > 0 && cur.second > 0)
                        {
                            cur.second--;
                            cur.first--;
                            continue;
                        }
                        break;
                    }
                    default:
                    {
                        if (s[cur.first] == p[cur.second])
                        {
                            if (cur.first == 0 && cur.second == 0)
                            {
                                return true;
                            }
                            if (cur.first == 0)
                            {
                                if (cur.second % 2 == 0)
                                {
                                    bool yuyu = true;
                                    for (int i = 1; i < cur.second; i+=2)
                                    {
                                        if (p[i] != '*')
                                        {
                                            yuyu = false;
                                            break;
                                        }
                                    }
                                    if (yuyu)
                                    {
                                        return true;
                                    }
                                }
                            }
                            if (cur.first > 0 && cur.second > 0)
                            {
                                cur.second--;
                                cur.first--;
                                continue;
                            }
                        }
                        break;
                    }
                }
                idxs.pop_front();
                break;
            }
        }
        return false;
    }
};

/*
1358. Number of Substrings Containing All Three Characters


Description:

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1

 

Constraints:

    3 <= s.length <= 5 x 10^4
    s only consists of a, b or c characters.



*/

class Solution {
public:
    int findIndex(int cur_idx, set<int>& a, set<int>& b)
    {
        set<int>::iterator ait = a.lower_bound(cur_idx);
        if (ait == a.end())
        {
            return -1;
        }
        set<int>::iterator bit = b.lower_bound(cur_idx);
        if (bit == b.end())
        {
            return -1;
        }
        return max(*ait, *bit);
    }
    int numberOfSubstrings(string s) {
        set<int> a_idx;
        set<int> b_idx;
        set<int> c_idx;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
                case 'a':
                {
                    a_idx.insert(i);
                    break;
                }
                case 'b':
                {
                    b_idx.insert(i);
                    break;
                }
                case 'c':
                {
                    c_idx.insert(i);
                    break;
                }
                default:
                {
                    // should never get here
                    break;
                }
            }
        }
        int out = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int idx = 0;
            switch (s[i])
            {
                case 'a':
                {
                    idx = findIndex(i, b_idx, c_idx);
                    break;
                }
                case 'b':
                {
                    idx = findIndex(i, a_idx, c_idx);
                    break;
                }
                case 'c':
                {
                    idx = findIndex(i, a_idx, b_idx);
                    break;
                }
                default:
                {
                    // should never get here
                    break;
                }
            }
            if (idx == -1)
            {
                break;
            }
            out += s.size() - idx;
        }
        return out;
    }
};


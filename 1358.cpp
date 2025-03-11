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
    int numberOfSubstrings(string s) {
        vector<int> a_idx(s.size());
        vector<int> b_idx(s.size());
        vector<int> c_idx(s.size());
        int next_a = s.size();
        int next_b = s.size();
        int next_c = s.size();
        for (int i = s.size() - 1; i >= 0; --i)
        {
            switch (s[i])
            {
                case 'a':
                {
                    next_a = i;
                    break;
                }
                case 'b':
                {
                    next_b = i;
                    break;
                }
                case 'c':
                {
                    next_c = i;
                    break;
                }
                default:
                {
                    // never get here
                    break;
                }
            }
            a_idx[i] = next_a;
            b_idx[i] = next_b;
            c_idx[i] = next_c;
        }
        int out = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int idx;
            switch (s[i])
            {
                case 'a':
                {
                    idx = max(b_idx[i], c_idx[i]);
                    break;
                }
                case 'b':
                {
                    idx = max(a_idx[i], c_idx[i]);
                    break;
                }
                case 'c':
                {
                    idx = max(a_idx[i], b_idx[i]);
                    break;
                }
                default:
                {
                    // never get here
                    break;
                }
            }
            if (idx < s.size())
            {
                out += s.size() - idx;
            }
        }
        return out;
    }
};


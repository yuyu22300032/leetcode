/*
1717. Maximum Score From Removing Substrings


Description:

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

    Remove substring "ab" and gain x points.
        For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
        For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

 

Constraints:

    1 <= s.length <= 105
    1 <= x, y <= 104
    s consists of lowercase English letters.


*/

class Solution {
public:
    int helper1(string &s, int x, int y)
    {
        int out = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
                case 'a':
                {
                    a += 1;
                    break;
                }
                case 'b':
                {
                    if (a > 0)
                    {
                        a -= 1;
                        out += x;
                    }
                    else
                    {
                        b += 1;
                    }
                    break;
                }
                default:
                {
                    out += std::min(a, b) * y;
                    a = 0;
                    b = 0;
                    break;
                }
            }
        }
        out += std::min(a, b) * y;
        a = 0;
        b = 0;

        return out;
    }
    int helper2(string &s, int x, int y)
    {
        int out = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
                case 'a':
                {
                    if (b > 0)
                    {
                        b -= 1;
                        out += y;
                    }
                    else
                    {
                        a += 1;
                    }
                    break;
                }
                case 'b':
                {
                    b += 1;
                    break;
                }
                default:
                {
                    out += std::min(a, b) * x;
                    a = 0;
                    b = 0;
                    break;
                }
            }
        }
        out += std::min(a, b) * x;
        a = 0;
        b = 0;

        return out;
    }
    int maximumGain(string s, int x, int y) {
        if (x > y)
        {
            return helper1(s, x, y);
        }
        else
        {
            return helper2(s, x, y);
        }
    }
};

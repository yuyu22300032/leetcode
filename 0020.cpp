/*
20. Valid Parentheses


Description:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                {
                    brackets.push(s[i]);
                    break;
                }
                case ')':
                {
                    if (brackets.empty() || brackets.top() != '(')
                    {
                        return false;
                    }
                    brackets.pop();
                    break;
                }
                case ']':
                {
                    if (brackets.empty() || brackets.top() != '[')
                    {
                        return false;
                    }
                    brackets.pop();
                    break;
                }
                case '}':
                {
                    if (brackets.empty() || brackets.top() != '{')
                    {
                        return false;
                    }
                    brackets.pop();
                    break;
                }
                default:
                {
                    return false;
                }
            }
        }

        if (brackets.size() > 0)
        {
            return false;
        }
        return true;
    }
};




/*
22. Generate Parentheses


Description:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:

    1 <= n <= 8


*/

class Solution {
    struct Forming {
        int opened;
        int open_left;
        string str;

        Forming(int n)
        : opened(0)
        , open_left(n)
        , str() { ; }
    };
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        vector<Forming> generating;
        Forming base(n);
        generating.push_back(base);
        int idx = 0;
        while (idx < generating.size())
        {
            if (generating[idx].opened > 0)
            {
                Forming new_forming = generating[idx];
                new_forming.opened -= 1;
                new_forming.str.push_back(')');
                generating.push_back(new_forming);
            }
            if (generating[idx].open_left > 0)
            {
                Forming new_forming = generating[idx];
                new_forming.open_left -= 1;
                new_forming.opened += 1;
                new_forming.str.push_back('(');
                generating.push_back(new_forming);
            }
            if (generating[idx].opened == 0 && generating[idx].open_left == 0)
            {
                out.push_back(generating[idx].str);
            }
            idx++;
        }
        return out;
    }
};


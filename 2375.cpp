/*
2375. Construct Smallest Number From DI String


Description:

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

    num consists of the digits '1' to '9', where each digit is used at most once.
    If pattern[i] == 'I', then num[i] < num[i + 1].
    If pattern[i] == 'D', then num[i] > num[i + 1].

Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.

Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

 

Constraints:

    1 <= pattern.length <= 8
    pattern consists of only the letters 'I' and 'D'.


*/

class Solution {
public:
    string smallestNumber(string pattern) {
        vector<int> skip_cnt(pattern.size() + 1, 0);
        vector<bool> decrease(pattern.size() + 1, false);
        int cur = 0;
        for (int i = pattern.size() - 1; i >= 0; i--)
        {
            if (pattern[i] == 'D')
            {
                cur++;
                decrease[i] = true;
            }
            else
            {
                cur = 0;
            }
            skip_cnt[i] = cur;
        }
        vector<bool> used(9, false);
        string out;
        cur = 0;
        for (int i = 0; i < skip_cnt.size(); ++i)
        {
            while (skip_cnt[i] > 0)
            {
                if (! used[cur])
                {
                    skip_cnt[i]--;
                }
                cur++;
            }
            while (used[cur])
            {
                cur++;
            }
            out.push_back('1' + cur);
            used[cur] = true;
            if (decrease[i])
            {
                cur = 0;
            }
        }

        return out;
    }
};


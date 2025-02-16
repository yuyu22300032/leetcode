/*
1718. Construct the Lexicographically Largest Valid Sequence


Description:

Given an integer n, find a sequence that satisfies all of the following:

    The integer 1 occurs once in the sequence.
    Each integer between 2 and n occurs twice in the sequence.
    For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.

The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.

Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]

 

Constraints:

    1 <= n <= 20


*/

class Solution {
public:
    bool helper(vector<int>& seq, int val, int idx)
    {
        if (val == 1)
        {
            seq[idx] = 1;
            return true;
        }
        if (idx + val < seq.size())
        {
            if (seq[idx + val] == 0)
            {
                seq[idx] = val;
                seq[idx + val] = val;
                return true;
            }
        }
        return false;
    }
    bool valUsed(vector<int>& seq, int val)
    {
        for (int i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == val)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        stack<vector<int>> search;
        for (int i = 1; i <= n; i++)
        {
            vector<int> out(n*2-1, 0);
            helper(out, i, 0);
            search.push(out);
        }
        while (! search.empty())
        {
            vector<int> out = search.top();
            search.pop();
            bool filled = true;
            for (int i = 0; i < out.size(); ++i)
            {
                if (out[i] != 0)
                {
                    continue;
                }
                filled = false;
                for (int j = 1; j <= n; j++)
                {
                    if (valUsed(out, j))
                    {
                        continue;
                    }
                    vector<int> tmp = out;
                    if (helper(tmp, j, i))
                    {
                        search.push(tmp);
                    }
                }
                break;
            }
            if (filled)
            {
                return out;
            }
        }
        return vector<int>();
    }
};




/*
1780. Check if Number is a Sum of Powers of Three


Description:

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32

Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34

Example 3:

Input: n = 21
Output: false

 

Constraints:

    1 <= n <= 107


*/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int cur_val = 1;
        while (n > cur_val)
        {
            cur_val *= 3;
        }
        while (cur_val > 0)
        {
            if (n >= cur_val)
            {
                n -= cur_val;
            }
            cur_val /= 3;
        }
        return n == 0;
    }
};


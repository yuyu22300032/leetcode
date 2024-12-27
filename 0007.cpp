/*
7. Reverse Integer


Description:

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 

Constraints:

    -231 <= x <= 231 - 1


*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
        {
            return 0;
        }
        bool neg = false;
        if (x < 0)
        {
            if (x == -2147483648)
            {
                return 0;
            }
            x = -x;
            neg = true;
        }
        vector<int> digits;
        int new_num = x;
        while (new_num)
        {
            digits.push_back(new_num % 10);
            new_num /= 10;
        }
        int out = 0;
        for (int i = 0; i < 9; ++i)
        {
            out = out * 10 + digits[i];
            if (i + 1 == digits.size())
            {
                return neg ? -out : out;
            }
        }
        if (out > 214748364)
        {
            return 0;
        }
        if (out == 214748364)
        {
            if (neg)
            {
                if (digits[9] > 8)
                {
                    return 0;
                }
                out = out * 10 + digits[9];
                return -out;
            }
            else
            {
                if (digits[9] > 7)
                {
                    return 0;
                }
                return out * 10 + digits[9];
            }
        }
        out = out * 10 + digits[9];
        return neg ? -out : out;
    }
};


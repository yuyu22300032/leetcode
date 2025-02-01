/*
29. Divide Two Integers


Description:

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

 

Constraints:

    -231 <= dividend, divisor <= 231 - 1
    divisor != 0



*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = true;
        unsigned int dvd;
        unsigned int dvs;
        if (dividend < 0)
        {
            if (dividend == INT_MIN)
            {
                dvd = 1;
                dvd = 1 << 31;
            }
            else
            {
                dvd = -dividend;
            }
            if (divisor < 0)
            {
                neg = false;
                if (divisor == INT_MIN)
                {
                    dvs = 1;
                    dvs = 1 << 31;
                }
                else
                {
                    dvs = -divisor;
                }
            }
            else
            {
                dvs = divisor;
            }
        }
        else
        {
            dvd = dividend;
            if (divisor < 0)
            {
                if (divisor == INT_MIN)
                {
                    dvs = 1;
                    dvs = 1 << 31;
                }
                else
                {
                    dvs = -divisor;
                }
            }
            else
            {
                neg = false;
                dvs = divisor;
            }
        }
        int cnt = 0;
        bool overflow = false;
        while (cnt < 32)
        {
            if (dvd < dvs)
            {
                break;
            }
            unsigned int max_val = 1;
            max_val = max_val << 31;
            cnt++;
            if (dvs >= max_val)
            {
                overflow = true;
                break;
            }
            dvs = dvs << 1;
        }
        unsigned int res = 0;
        for (int i = 0; i < cnt; ++i)
        {
            if (overflow)
            {
                overflow = false;
            }
            else
            {
                dvs = dvs >> 1;
            }
            if (dvd >= dvs)
            {
                res += 1 << (cnt - i - 1);
                dvd -= dvs;
            }
        }
        int out = 0;
        unsigned int max_val = 1;
        if (neg)
        {
            max_val = max_val << 31;
            if (res >= max_val)
            {
                out = INT_MIN;
            }
            else
            {
                out = -res;
            }
        }
        else
        {
            max_val = max_val << 31 - 1;
            if (res >= max_val)
            {
                out = INT_MAX;
            }
            else
            {
                out = res;
            }
        }
        return out;
    }
};


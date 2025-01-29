/*
50. Pow(x, n)


Description:

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    n is an integer.
    Either x is not zero or n > 0.
    -104 <= xn <= 104

*/

class Solution {
public:
    double myPow(double x, int n) {
        double out = 1.0;
        double power;
        bool is_int_min = false;
        if (n < 0)
        {
            power = 1 / x;
            if (n == INT_MIN)
            {
                is_int_min = true;
            }
            else
            {
                n = -n;
            }
        }
        else
        {
            power = x;
        }
        for (int i = 0; i < 31; ++i)
        {
            if (n & (1 << i))
            {
                out *= power;
            }
            power *= power;
        }
        if (is_int_min)
        {
            out = power;
        }

        return out;
    }
};


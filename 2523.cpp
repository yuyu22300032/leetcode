/*
2523. Closest Prime Numbers in Range


Description:

Given two positive integers left and right, find the two integers num1 and num2 such that:

    left <= num1 < num2 <= right .
    Both num1 and num2 are 

    .
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.

Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

 

Constraints:

    1 <= left <= right <= 106

*/

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> out(2, -1);
        vector<bool> is_prime(right, true);
        is_prime[0] = false;
        int check_bound = pow(right, 0.5) + 1;
        for (int i = 2; i <= check_bound; i++)
        {
            if (is_prime[i - 1])
            {
                for (int j = 2 * i; j <= right; j += i)
                {
                    is_prime[j - 1] = false;
                }
            }
        }
        int min_diff = right - left + 1;
        optional<int> prev_prime;
        for (int i = left; i <= right; i++)
        {
            if (is_prime[i - 1])
            {
                if (prev_prime)
                {
                    int cur_diff = i - prev_prime.value();
                    if (cur_diff < min_diff)
                    {
                        out[0] = prev_prime.value();
                        out[1] = i;
                        min_diff = cur_diff;
                    }
                }
                prev_prime = i;
            }
        }
        return out;
    }
};


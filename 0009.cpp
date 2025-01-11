/*
9. Palindrome Number


Description:

Given an integer x, return true if x is a
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 

Constraints:

    -231 <= x <= 231 - 1

 
Follow up: Could you solve it without converting the integer to a string?

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        if (x == 0)
        {
            return true;
        }
        if (x % 10 == 0)
        {
            return false;
        }
        int reverse = 0;
        int cur = x;
        while (cur > 0)
        {
            if (reverse > INT_MAX / 10)
            {
                return false;
            }
            reverse *= 10;
            int n = cur % 10;
            if (INT_MAX - reverse < n)
            {
                return false;
            }
            reverse += n;
            cur /= 10;
        }
        if (reverse == x)
        {
            return true;
        }
        return false;
    }
};

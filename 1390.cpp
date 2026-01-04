/*
1390. Four Divisors


Description:

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:

Input: nums = [21,21]
Output: 64

Example 3:

Input: nums = [1,2,3,4,5]
Output: 0

 

Constraints:

    1 <= nums.length <= 104
    1 <= nums[i] <= 105


*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int out = 0;
        for (int i = 0; i < nums.size(); i++) {
            int end = pow(nums[i], 0.5);
            if (end * end == nums[i]) {
                // no equal square root because it will make it odd number divisors (not 4)
                continue;
            }
            int div = 0;
            for (int j = 2; j <= end; j++) {
                if (nums[i] % j == 0) {
                    if (div > 0) {
                        // more than 4 divisors
                        div = 0;
                        break;
                    }
                    div = j;
                }
            }
            if (div > 0) {
                out += 1 + nums[i] + div + (nums[i] / div);
            }
        }
        return out;
    }
};
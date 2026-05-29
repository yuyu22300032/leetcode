/*
3300. Minimum Element After Replacement With Digit Sum


Description:

You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

 

Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 104


*/

class Solution {
    int getDigitSum(int num) {
        int out = 0;
        int cur = num;
        while (cur > 0) {
            out += cur % 10;
            cur /= 10;
        }
        return out;
    }
public:
    int minElement(vector<int>& nums) {
        int out = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            out = min(out, getDigitSum(nums[i]));
        }
        return out;
    }
};

/*
2342. Max Sum of a Pair With Equal Sum of Digits


Description:

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions. If no such pair of indices exists, return -1.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.

Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109


*/

class Solution {
public:
    struct numPair {
        int big_num;
        int small_num;

        numPair(int num)
        {
            big_num = num;
            small_num = 0;
        }

        bool update(int num)
        {
            if (num <= small_num)
            {
                return false;
            }
            if (num >= big_num)
            {
                small_num = big_num;
                big_num = num;
            }
            else
            {
                small_num = num;
            }
            return true;
        }

        int getSum()
        {
            return big_num + small_num;
        }
    };

    int getDigitSum(int num)
    {
        int digit_sum = 0;
        while (num > 0)
        {
            digit_sum += num % 10;
            num /= 10;
        }
        return digit_sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, numPair> dsum;
        int out = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cur_dsum = getDigitSum(nums[i]);
            unordered_map<int, numPair>::iterator it = dsum.find(cur_dsum);
            if (it == dsum.end())
            {
                dsum.insert(pair<int, numPair>(cur_dsum, numPair(nums[i])));
            }
            else
            {
                if (it->second.update(nums[i]))
                {
                    out = max(out, it->second.getSum());
                }
            }
        }
        return out;
    }
};


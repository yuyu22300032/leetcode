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
    int maximumSum(vector<int>& nums) {
        map<int, pair<int, int>> dsum;
        int out = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cur_dsum = 0;
            int cur = nums[i];
            while (cur > 0)
            {
                cur_dsum += cur % 10;
                cur /= 10;
            }
            map<int, pair<int, int>>::iterator it = dsum.find(cur_dsum);
            if (it == dsum.end())
            {
                dsum.insert(pair<int, pair<int, int>>(cur_dsum, pair<int, int>(nums[i], 0)));
            }
            else
            {
                if (it->second.first > it->second.second)
                {
                    if (nums[i] > it->second.second)
                    {
                        it->second.second = nums[i];
                        out = max(out, nums[i] + it->second.first);
                    }
                }
                else
                {
                    if (nums[i] > it->second.first)
                    {
                        it->second.first = nums[i];
                        out = max(out, nums[i] + it->second.second);
                    }
                }
            }
        }
        return out;
    }
};


/*
16. 3Sum Closest


Description:

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

 

Constraints:

    3 <= nums.length <= 500
    -1000 <= nums[i] <= 1000
    -104 <= target <= 104


*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int out = 0;
        int gap = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int cur_sum = nums[i] + nums[left] + nums[right];
                int cur_gap = abs(cur_sum - target);
                if (cur_gap < gap)
                {
                    out = cur_sum;
                    gap = cur_gap;
                }
                if (cur_sum > target)
                {
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right+1]);
                }
                else if (cur_sum < target)
                {
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left-1]);
                }
                else
                {
                    return cur_sum;
                }
            }
        }
        return out;
    }
};



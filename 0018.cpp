/*
18. 4Sum


Description:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

 

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109


*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
        {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            double max_val = 4.0 * nums[i];
            if (target < max_val)
            {
                break;
            }
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j-1])
                {
                    continue;
                }
                max_val = 3.0 * nums[j] + nums[i];
                if (target < max_val)
                {
                    break;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    double cur_sum = 0.0 + nums[i] + nums[j] + nums[left] + nums[right];
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
                        out.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do {
                            right--;
                        } while (left < right && nums[right] == nums[right+1]);
                        do {
                            left++;
                        } while (left < right && nums[left] == nums[left-1]);
                    }
                }
            }
        }
        return out;
    }
};



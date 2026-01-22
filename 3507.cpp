/*
3507. Minimum Pair Removal to Sort Array I


Description:

Given an array nums, you can perform the following operation any number of times:

    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].

The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

    1 <= nums.length <= 50
    -1000 <= nums[i] <= 1000


*/

class Solution {
    bool checkNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
    void RemoveMinSum(vector<int>& nums) {
        int min_sum = INT_MAX;
        int idx = -1;
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i - 1] + nums[i];
            if (cur < min_sum) {
                min_sum = cur;
                idx = i;
            }
        }
        nums[idx - 1] += nums[idx];
        for (int i = idx + 1; i < nums.size(); i++) {
            nums[i - 1] = nums[i];
        }
        nums.pop_back();
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!checkNonDecreasing(nums)) {
            RemoveMinSum(nums);
            cnt++;
        }
        return cnt;
    }
};

/*
961. N-Repeated Element in Size 2N Array


Description:

You are given an integer array nums with the following properties:

    nums.length == 2 * n.
    nums contains n + 1 unique elements.
    Exactly one element of nums is repeated n times.

Return the element that is repeated n times.

 

Example 1:

Input: nums = [1,2,3,3]
Output: 3

Example 2:

Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:

Input: nums = [5,1,5,2,5,3,5,4]
Output: 5

 

Constraints:

    2 <= n <= 5000
    nums.length == 2 * n
    0 <= nums[i] <= 104
    nums contains n + 1 unique elements and one of them is repeated exactly n times.


*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        /*
        unordered_set<int> showed;
        for (int i = 0; i < nums.size(); i++) {
            if (showed.count(nums[i]) > 0) {
                return nums[i];
            }
            showed.insert(nums[i]);
        }
        return -1;

        O(1) space solution
        */
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                return nums[i];
            }
        }
        if (nums[0] == nums.back()) {
            return nums[0];
        }
        if (nums[0] == nums[2]) {
            return nums[0];
        }
        return nums[1];
    }
};

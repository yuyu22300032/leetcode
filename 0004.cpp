/*
4. Median of Two Sorted Arrays


Description:

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106


*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t_cnt = (nums1.size() + nums2.size() - 1) / 2;
        int l1 = 0;
        int l2 = 0;
        int r1 = nums1.size();
        int r2 = nums2.size();
        while (l1 < r1 && l2 < r2)
        {
            int m1 = (l1 + r1) / 2;
            int m2 = (l2 + r2) / 2;
            if (nums1[m1] <= nums2[m2])
            {
                if (m1 + m2 < t_cnt)
                {
                    l1 = m1 + 1;
                }
                else if (m1 > t_cnt)
                {
                    r1 = m1;
                }
                else
                {
                    r2 = m2;
                }
            }
            else
            {
                if (m1 + m2 < t_cnt)
                {
                    l2 = m2 + 1;
                }
                else if (m2 > t_cnt)
                {
                    r2 = m2;
                }
                else
                {
                    r1 = m1;
                }
            }
        }
        
        if (l2 == r2)
        {
            swap(nums1, nums2);
            swap(l1, l2);
            swap(r1, r2);
        }
        l2 = t_cnt - l1;
        if ((nums1.size() + nums2.size()) % 2 == 1)
        {
            return nums2[l2];
        }
        if (l1 < nums1.size())
        {
            if (l2 + 1 < nums2.size() && nums2[l2+1] <= nums1[l1])
            {
                return 0.5 * (nums2[l2] + nums2[l2+1]);
            }
            else
            {
                return 0.5 * (nums2[l2] + nums1[l1]);
            }
        }
        else
        {
            if (l2 + 1 < nums2.size())
            {
                return 0.5 * (nums2[l2] + nums2[l2+1]);
            }
            else
            {
                return 0.5 * (nums1[l1] + nums2[l2]);
            }
        }

        return 0;
    }
};


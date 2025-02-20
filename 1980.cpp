/*
1980. Find Unique Binary String


Description:

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

 

Constraints:

    n == nums.length
    1 <= n <= 16
    nums[i].length == n
    nums[i] is either '0' or '1'.
    All the strings of nums are unique.


*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> pstr;
        pstr.push_back("0");
        pstr.push_back("1");
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < pstr.size(); ++j)
            {
                bool found = true;
                for (int k = 0; k < nums.size(); ++k)
                {
                    if (nums[k].compare(0, i + 1, pstr[j]) == 0)
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    int missing_len = nums.size() - pstr[j].size();
                    for (int k = 0; k < missing_len; ++k)
                    {
                        pstr[j].push_back('0');
                    }
                    return pstr[j];
                }
            }
            int cur_size = pstr.size();
            for (int j = 0; j < cur_size; ++j)
            {
                pstr.push_back(pstr[j] + "1");
                pstr[j].push_back('0');
            }
        }
        return "";
    }
};


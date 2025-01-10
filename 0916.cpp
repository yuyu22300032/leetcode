/*
916. Word Subsets


Description:

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

    For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

 

Constraints:

    1 <= words1.length, words2.length <= 104
    1 <= words1[i].length, words2[i].length <= 10
    words1[i] and words2[i] consist only of lowercase English letters.
    All the strings of words1 are unique.


*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> out;
        vector<int> target_letter_cnts(26, 0);
        for (int i = 0; i < words2.size(); ++i)
        {
            vector<int> cur_letter_cnts(26, 0);
            for (int j = 0; j < words2[i].size(); ++j)
            {
                cur_letter_cnts[words2[i][j] - 'a'] += 1;
            }
            for (int j = 0; j < 26; ++j)
            {
                if (cur_letter_cnts[j] > target_letter_cnts[j])
                {
                    target_letter_cnts[j] = cur_letter_cnts[j];
                }
            }
        }
        for (int i = 0; i < words1.size(); ++i)
        {
            vector<int> cur_letter_cnts(26, 0);
            for (int j = 0; j < words1[i].size(); ++j)
            {
                cur_letter_cnts[words1[i][j] - 'a'] += 1;
            }
            bool is_universal = true;
            for (int j = 0; j < 26; ++j)
            {
                if (target_letter_cnts[j] > cur_letter_cnts[j])
                {
                    is_universal = false;
                    break;
                }
            }
            if (is_universal)
            {
                out.push_back(words1[i]);
            }
        }
        return out;
    }
};



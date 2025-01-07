/*
1408. String Matching in an Array


Description:

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 30
    words[i] contains only lowercase English letters.
    All the strings of words are unique.


*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> out;
        for (int i = 0; i < words.size(); ++i)
        {
            bool is_substr = false;
            for (int j = 0; j < words.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (words[i].size() > words[j].size())
                {
                    continue;
                }
                for (int k = 0; k < words[j].size() - words[i].size() + 1; ++k)
                {
                    for (int l = 0; l < words[i].size(); ++l)
                    {
                        if (words[j][k+l] != words[i][l])
                        {
                            break;
                        }
                        if (l == words[i].size() - 1)
                        {
                            is_substr = true;
                            break;
                        }
                    }
                    if (is_substr)
                    {
                        break;
                    }
                }
                if (is_substr)
                {
                    break;
                }
            }
            if (is_substr)
            {
                out.push_back(words[i]);
            }
        }
        return out;
    }
};


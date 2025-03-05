/*
30. Substring with Concatenation of All Words


Description:

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

    1 <= s.length <= 104
    1 <= words.length <= 5000
    1 <= words[i].length <= 30
    s and words[i] consist of lowercase English letters.


*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> out;
        if (s.size() < words[0].size())
        {
            return out;
        }
        unordered_map<string, int> words_table;
        for (int i = 0; i < words.size(); ++i)
        {
            unordered_map<string, int>::iterator it = words_table.find(words[i]);
            if (it == words_table.end())
            {
                words_table.insert(pair<string, int>(words[i], 1));
            }
            else
            {
                it->second += 1;
            }
        }

        vector<int> match_word;
        for (unordered_map<string, int>::iterator it = words_table.begin(); it != words_table.end(); ++it)
        {
            match_word.push_back(it->second);
            it->second = match_word.size() - 1;
        }

        vector<int> match_idx;
        for (int i = 0; i < s.size() - words[0].size() + 1; ++i)
        {
            unordered_map<string, int>::iterator it = words_table.find(s.substr(i, words[0].size()));
            if (it == words_table.end())
            {
                match_idx.push_back(-1);
            }
            else
            {
                match_idx.push_back(it->second);
            }
        }

        for (int i = 0; i < s.size() - words[0].size() * words.size() + 1; ++i)
        {
            bool found = true;
            vector<int> cur_match(match_word);
            for (int j = 0; j < words.size(); j++)
            {
                int idx = i + j * words[0].size();
                if (match_idx[idx] < 0)
                {
                    found = false;
                    break;
                }
                if (cur_match[match_idx[idx]] <= 0)
                {
                    found = false;
                    break;
                }
                cur_match[match_idx[idx]] -= 1;
            }
            if (found)
            {
                out.push_back(i);
            }
        }
        return out;
    }
};


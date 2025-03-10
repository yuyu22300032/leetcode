/*
3306. Count of Substrings Containing Every Vowel and K Consonants II


Description:

You are given a string word and a non-negative integer k.

Return the total number of

of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

    word[0..5], which is "ieaouq".
    word[6..11], which is "qieaou".
    word[7..12], which is "ieaouq".

 

Constraints:

    5 <= word.length <= 2 * 105
    word consists only of lowercase English letters.
    0 <= k <= word.length - 5

*/

class Solution {
    struct Cnt {
        int a;
        int e;
        int i;
        int o;
        int u;
        int consonants;
    };
public:
    long long countOfSubstrings(string word, int k) {
        vector<Cnt> counts;
        vector<int> consonants_idx;
        Cnt cur{0};
        counts.push_back(cur);
        for (int i = 0; i < word.size(); ++i)
        {
            switch (word[i])
            {
                case 'a':
                {
                    cur.a += 1;
                    break;
                }
                case 'e':
                {
                    cur.e += 1;
                    break;
                }
                case 'i':
                {
                    cur.i += 1;
                    break;
                }
                case 'o':
                {
                    cur.o += 1;
                    break;
                }
                case 'u':
                {
                    cur.u += 1;
                    break;
                }
                default:
                {
                    cur.consonants += 1;
                    consonants_idx.push_back(i);
                    break;
                }
            }
            counts.push_back(cur);
        }
        consonants_idx.push_back(word.size());

        int idx = 0;
        vector<int> all_vowel_idx(word.size() - 4 - k, INT_MAX);
        for (int i = 0; i < all_vowel_idx.size(); ++i)
        {
            while (idx < counts.size())
            {
                if (counts[idx].a - counts[i].a > 0 &&
                    counts[idx].e - counts[i].e > 0 &&
                    counts[idx].i - counts[i].i > 0 &&
                    counts[idx].o - counts[i].o > 0 &&
                    counts[idx].u - counts[i].u > 0)
                {
                    all_vowel_idx[i] = idx - 1;
                    break;
                }
                idx++;
            }
            if (idx == counts.size())
            {
                break;
            }
        }

        long long out = 0;
        for (int i = 0; i < all_vowel_idx.size(); ++i)
        {
            if (all_vowel_idx[i] == INT_MAX)
            {
                break;
            }
            if (k + counts[i].consonants > consonants_idx.size())
            {
                break;
            }
            int start_idx = 0;
            if (k + counts[i].consonants > 0)
            {
                start_idx = consonants_idx[k + counts[i].consonants - 1];
            }
            int end_idx = word.size();
            if (k + counts[i].consonants < consonants_idx.size())
            {
                end_idx = consonants_idx[k + counts[i].consonants];
            }
            
            if (all_vowel_idx[i] >= end_idx)
            {
                continue;
            }
            out += end_idx - max(all_vowel_idx[i], start_idx);
        }
        return out;
    }
};


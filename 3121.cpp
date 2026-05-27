/*
3121. Count the Number of Special Characters II


Description:

You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.

 

Constraints:

    1 <= word.length <= 2 * 105
    word consists of only lowercase and uppercase English letters.


*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> appears(26);
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                int idx = word[i] - 'a';
                appears[idx] |= 1;
                if (appears[idx] & 2) {
                    appears[idx] |= 4;
                }
            } else {
                int idx = word[i] - 'A';
                appears[idx] |= 2;
            }
        }
        int out = 0;
        for (int i = 0; i < appears.size(); i++) {
            if (appears[i] == 3) {
                out++;
            }
        }
        return out;
    }
};

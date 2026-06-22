/*
1189. Maximum Number of Balloons


Description:

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0

 

Constraints:

    1 <= text.length <= 104
    text consists of lower case English letters only.

 

Note: This question is the same as 2287: Rearrange Characters to Make Target String.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> char_cnt(5, 0); // a, b, l, n, o
        for (int i = 0; i < text.size(); i++) {
            switch (text[i]) {
                case 'a': {
                    char_cnt[0] += 1;
                    break;
                }
                case 'b': {
                    char_cnt[1] += 1;
                    break;
                }
                case 'l': {
                    char_cnt[2] += 1;
                    break;
                }
                case 'n': {
                    char_cnt[3] += 1;
                    break;
                }
                case 'o': {
                    char_cnt[4] += 1;
                    break;
                }
                default: {
                    break;
                }
            }
        }
        int out = min(char_cnt[0], char_cnt[1]);
        out = min(out, char_cnt[3]);
        out = min(out, char_cnt[2] / 2);
        out = min(out, char_cnt[4] / 2);
        return out;
    }
};


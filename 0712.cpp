/*
712. Minimum ASCII Delete Sum for Two Strings


Description:

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

 

Constraints:

    1 <= s1.length, s2.length <= 1000
    s1 and s2 consist of lowercase English letters.


*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> table(s1.size(), vector<int>(s2.size(), 0));
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    table[i][j] = s1[i];
                    if (i > 0 && j > 0) {
                        table[i][j] += table[i-1][j-1];
                    }
                } else {
                    if (i > 0 && j > 0) {
                        table[i][j] = max(table[i-1][j], table[i][j-1]);
                    } else if (i > 0) {
                        table[i][j] = table[i-1][j];
                    } else if (j > 0) {
                        table[i][j] = table[i][j-1];
                    }
                }
            }
        }
        int out = 0;
        for (int i = 0; i < s1.size(); i++) {
            out += s1[i];
        }
        for (int i = 0; i < s2.size(); i++) {
            out += s2[i];
        }
        out -= table.back().back() * 2;
        return out;
    }
};

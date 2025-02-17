/*
1079. Letter Tile Possibilities


Description:

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:

Input: tiles = "AAABBC"
Output: 188

Example 3:

Input: tiles = "V"
Output: 1

 

Constraints:

    1 <= tiles.length <= 7
    tiles consists of uppercase English letters.


*/

class Solution {
public:
    void recursive_search(int& out, vector<int>& char_cnt)
    {
        for (int i = 0; i < char_cnt.size(); ++i)
        {
            if (char_cnt[i] == 0)
            {
                continue;
            }
            out++;
            char_cnt[i] -= 1;
            recursive_search(out, char_cnt);
            char_cnt[i] += 1;
        }
    }
    int numTilePossibilities(string tiles) {
        int out = 0;
        vector<int> char_cnt(26, 0);
        for (int i = 0; i < tiles.size(); ++i)
        {
            char_cnt[tiles[i] - 'A'] += 1;
        }
        recursive_search(out, char_cnt);
        return out;
    }
};


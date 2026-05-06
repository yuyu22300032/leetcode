/*
1861. Rotating the Box


Description:

You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

    A stone '#'
    A stationary obstacle '*'
    Empty '.'

The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:

Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]

Example 2:

Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]

Example 3:

Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]

 

Constraints:

    m == boxGrid.length
    n == boxGrid[i].length
    1 <= m, n <= 500
    boxGrid[i][j] is either '#', '*', or '.'.


*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> out(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        for (int i = 0; i < boxGrid.size(); i++) {
            for (int j = 0; j < boxGrid[i].size(); j++) {
                int idx = boxGrid.size() - 1 - i;
                out[j][idx] = boxGrid[i][j];
            }
        }
        for (int j = 0; j < out[0].size(); j++) {
            for (int i = out.size() - 1; i >= 0; i--) {
                if (out[i][j] != '#') {
                    continue;
                }
                int idx = i;
                while (idx + 1 < out.size() && out[idx + 1][j] == '.') {
                    out[idx + 1][j] = '#';
                    out[idx][j] = '.';
                    idx++;
                }
            }
        }
        return move(out);
    }
};

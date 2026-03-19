/*
3212. Count Submatrices With Equal Frequency of X and Y


Description:

Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of that contain:

    grid[0][0]
    an equal frequency of 'X' and 'Y'.
    at least one 'X'.

 

Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3

Explanation:

Example 2:

Input: grid = [["X","X"],["X","Y"]]

Output: 0

Explanation:

No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]

Output: 0

Explanation:

No submatrix has at least one 'X'.

 

Constraints:

    1 <= grid.length, grid[i].length <= 1000
    grid[i][j] is either 'X', 'Y', or '.'.


*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> xCnts(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> yCnts(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'X') {
                    xCnts[i][j] = 1;
                } else if (grid[i][j] == 'Y') {
                    yCnts[i][j] = 1;
                }
                if (j > 0) {
                    xCnts[i][j] += xCnts[i][j - 1];
                    yCnts[i][j] += yCnts[i][j - 1];
                }
            }
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                xCnts[i][j] += xCnts[i - 1][j];
                yCnts[i][j] += yCnts[i - 1][j];
            }
        }
        int out = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (xCnts[i][j] > 0 && xCnts[i][j] == yCnts[i][j]) {
                    out++;
                }
            }
        }
        return out;
    }
};

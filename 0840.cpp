/*
840. Magic Squares In Grid


Description:

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 10
    0 <= grid[i][j] <= 15


*/

class Solution {
    bool checkRowSum(int target_sum, vector<vector<int>>& grid, int i, int j) {
        for (int col = j - 2; col <= j; col++) {
            int row_sum = 0;
            for (int row = i - 2; row <= i; row++) {
                row_sum += grid[row][col];
            }
            if (row_sum != target_sum) {
                return false;
            }
        }
        return true;
    }
    bool checkColSum(int target_sum, vector<vector<int>>& grid, int i, int j) {
        for (int row = i - 2; row <= i; row++) {
            int col_sum = 0;
            for (int col = j - 2; col <= j; col++) {
                col_sum += grid[row][col];
            }
            if (col_sum != target_sum) {
                return false;
            }
        }
        return true;
    }
    bool checkContain1to9(vector<vector<int>>& grid, int i, int j) {
        vector<bool> all_nums(9, false);
        for (int row = i - 2; row <= i; row++) {
            for (int col = j - 2; col <= j; col++) {
                int num = grid[row][col];
                if (num < 1 || num > 9) {
                    return false;
                }
                if (all_nums[num]) {
                    return false;
                }
                all_nums[num] = true;
            }
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int out = 0;
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[i].size(); j++) {
                if (! checkContain1to9(grid, i, j)) {
                    continue;
                }
                if ((grid[i][j] + grid[i - 2][j - 2]) != (grid[i][j - 2] + grid[i - 2][j])) {
                    continue;
                }
                int target_sum = grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2];
                if (! checkRowSum(target_sum, grid, i, j)) {
                    continue;
                }
                if (! checkColSum(target_sum, grid, i, j)) {
                    continue;
                }
                out++;
            }
        }
        return out;
    }
};

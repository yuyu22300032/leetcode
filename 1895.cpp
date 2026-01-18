/*
1895. Largest Magic Square


Description:

A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

 

Example 1:

Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

Example 2:

Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 106

 
*/

class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int col, int row, int s) {
        int magic = 0;
        for (int i = 0; i < s; i++) {
            magic += grid[col + i][row + i];
        }
        int cur = 0;
        for (int i = 0; i < s; i++) {
            cur += grid[col + i][row + s - i - 1];
        }
        if (cur != magic) {
            return false;
        }
        for (int j = row; j < row + s; j++) {
            cur = 0;
            for (int i = col; i < col + s; i++) {
                cur += grid[i][j];
            }
            if (cur != magic) {
                return false;
            }
        }
        for (int i = col; i < col + s; i++) {
            cur = 0;
            for (int j = row; j < row + s; j++) {
                cur += grid[i][j];
            }
            if (cur != magic) {
                return false;
            }
        }
        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int out = 1;
        for (int s = 2; s <= min(grid.size(), grid[0].size()); s++) {
            for (int i = 0; i + s <= grid.size(); i++) {
                for (int j = 0; j + s <= grid[i].size(); j++) {
                    if (isMagicSquare(grid, i, j, s)) {
                        out = s;
                        break;
                    }
                }
                if (out == s) {
                    break;
                }
            }
        }
        return out;
    }
};

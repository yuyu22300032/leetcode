/*
73. Set Matrix Zeroes



Description:

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

 

Follow up:

    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?


*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_column_zero = false;
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                first_column_zero = true;
                break;
            }
        }
        bool first_row_zero = false;
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                first_row_zero = true;
                break;
            }
        }
        for (size_t i = 1; i < matrix.size(); ++i)
        {
            for (size_t j = 1; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (size_t i = 1; i < matrix.size(); ++i)
        {
            for (size_t j = 1; j < matrix[i].size(); ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_column_zero)
        {
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }
        if (first_row_zero)
        {
            for (size_t j = 0; j < matrix[0].size(); ++j)
            {
                matrix[0][j] = 0;
            }
        }
    }
};


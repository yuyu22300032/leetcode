/*
85. Maximal Rectangle


Description:

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1

 

Constraints:

    rows == matrix.length
    cols == matrix[i].length
    1 <= rows, cols <= 200
    matrix[i][j] is '0' or '1'.


*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            int cur = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    cur++;
                } else {
                    cur = 0;
                }
                table[i][j] = cur;
            }
        }
        int out = 0;
        for (int i = 0; i < table.size(); i++) {
            for (int j = 0; j < table[i].size(); j++) {
                if (table[i][j] == 0) {
                    continue;
                }
                out = max(out, table[i][j]);
                int rec_row = table[i][j];
                for (int k = i - 1; k >= 0; k--) {
                    if (table[k][j] == 0) {
                        break;
                    }
                    rec_row = min(table[k][j], rec_row);
                    out = max(out, rec_row * (i - k + 1));
                }
            }
        }
        return out;
    }
};

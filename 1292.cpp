/*
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold


Description:

Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

Example 1:

Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 300
    0 <= mat[i][j] <= 104
    0 <= threshold <= 105


*/

class Solution {
    bool isSmallSumSquare(vector<vector<int>>& mat, int threshold, int length) {
        for (int i = length - 1; i < mat.size(); i++) {
            for (int j = length - 1; j < mat[i].size(); j++) {
                int out = mat[i][j];
                if (i >= length) {
                    out -= mat[i - length][j];
                }
                if (j >= length) {
                    out -= mat[i][j - length];
                }
                if ((i >= length) && (j >= length)) {
                    out += mat[i - length][j - length];
                }
                if (out <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if ((i > 0) && (j > 0)) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
        int left = 0;
        int right = min(mat.size(), mat[0].size());
        while (left != right) {
            int mid = (left + right + 1) / 2;
            if (isSmallSumSquare(mat, threshold, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

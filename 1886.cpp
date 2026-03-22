/*
1886. Determine Whether Matrix Can Be Obtained By Rotation


Description:

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:

Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

Example 2:

Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.

Example 3:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.

 

Constraints:

    n == mat.length == target.length
    n == mat[i].length == target[i].length
    1 <= n <= 10
    mat[i][j] and target[i][j] are either 0 or 1.


*/

class Solution {
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat) {
        const int n = mat.size();
        vector<vector<int>> out(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out[j][n - i -1] = mat[i][j];
            }
        }
        return move(out);
    }
    bool checkMatrixEqual(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        const int n = mat1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat1[i][j] != mat2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rotateCnt = 0;
        while (!checkMatrixEqual(mat, target)) {
            if (++rotateCnt == 4) {
                return false;
            }
            mat = rotateMatrix(mat);
        }
        return true;
    }
};

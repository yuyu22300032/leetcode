/*
2661. First Completely Painted Row or Column


Description:

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:
image explanation for example 1

Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

Example 2:
image explanation for example 2

Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].

 

Constraints:

    m == mat.length
    n = mat[i].length
    arr.length == m * n
    1 <= m, n <= 105
    1 <= m * n <= 105
    1 <= arr[i], mat[r][c] <= m * n
    All the integers of arr are unique.
    All the integers of mat are unique.


*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> row_idx(arr.size() + 1);
        vector<int> col_idx(arr.size() + 1);
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                row_idx[mat[i][j]] = i;
                col_idx[mat[i][j]] = j;
            }
        }
        vector<int> row_cnt(mat.size(), 0);
        vector<int> col_cnt(mat[0].size(), 0);
        for (int i = 0; i < arr.size(); ++i)
        {
            if (row_cnt[row_idx[arr[i]]] == mat[0].size() - 1 || col_cnt[col_idx[arr[i]]] == mat.size() - 1)
            {
                return i;
            }
            row_cnt[row_idx[arr[i]]] += 1;
            col_cnt[col_idx[arr[i]]] += 1;
        }
        return 0;
    }
};


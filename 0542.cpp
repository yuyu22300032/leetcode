/*
542. 01 Matrix


Description:

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

 

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> out(mat.size(), vector<int>(mat[0].size(), -1));
        vector<pair<int, int>> searching;
        int search_idx = 0;
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == 0)
                {
                    out[i][j] = 0;
                    if (i > 0)
                    {
                        searching.push_back(pair<int, int>(i - 1, j));
                    }
                    if (i < mat.size() - 1)
                    {
                        searching.push_back(pair<int, int>(i + 1, j));
                    }
                    if (j > 0)
                    {
                        searching.push_back(pair<int, int>(i, j - 1));
                    }
                    if (j < mat[0].size() - 1)
                    {
                        searching.push_back(pair<int, int>(i, j + 1));
                    }
                }
            }
        }
        while (search_idx < searching.size())
        {
            pair<int, int> cur = searching[search_idx];
            search_idx++;
            if (out[cur.first][cur.second] != -1)
            {
                continue;
            }
            int min_around = INT_MAX;
            if (cur.first > 0)
            {
                if (out[cur.first - 1][cur.second] == -1)
                {
                    searching.push_back(pair<int, int>(cur.first - 1, cur.second));
                }
                else
                {
                    min_around = min(min_around, out[cur.first - 1][cur.second]);
                }
            }
            if (cur.first < mat.size() - 1)
            {
                if (out[cur.first + 1][cur.second] == -1)
                {
                    searching.push_back(pair<int, int>(cur.first + 1, cur.second));
                }
                else
                {
                    min_around = min(min_around, out[cur.first + 1][cur.second]);
                }
            }
            if (cur.second > 0)
            {
                if (out[cur.first][cur.second - 1] == -1)
                {
                    searching.push_back(pair<int, int>(cur.first, cur.second - 1));
                }
                else
                {
                    min_around = min(min_around, out[cur.first][cur.second - 1]);
                }
            }
            if (cur.second < mat[0].size() - 1)
            {
                if (out[cur.first][cur.second + 1] == -1)
                {
                    searching.push_back(pair<int, int>(cur.first, cur.second + 1));
                }
                else
                {
                    min_around = min(min_around, out[cur.first][cur.second + 1]);
                }
            }
            out[cur.first][cur.second] = min_around + 1;
        }
        return out;
    }
};


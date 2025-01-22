/*
1765. Map of Highest Peak


Description:

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

    If isWater[i][j] == 0, cell (i, j) is a land cell.
    If isWater[i][j] == 1, cell (i, j) is a water cell.

You must assign each cell a height in a way that follows these rules:

    The height of each cell must be non-negative.
    If the cell is a water cell, its height must be 0.
    Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:

Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Example 2:

Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

 

Constraints:

    m == isWater.length
    n == isWater[i].length
    1 <= m, n <= 1000
    isWater[i][j] is 0 or 1.
    There is at least one water cell.

 

Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/

*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> out(isWater.size(), vector<int>(isWater[0].size(), -1));
        vector<pair<int, int>> searching;
        int search_idx = 0;
        for (int i = 0; i < isWater.size(); ++i)
        {
            for (int j = 0; j < isWater[i].size(); ++j)
            {
                if (isWater[i][j] == 1)
                {
                    out[i][j] = 0;
                    if (i > 0)
                    {
                        searching.push_back(pair<int, int>(i - 1, j));
                    }
                    if (i < isWater.size() - 1)
                    {
                        searching.push_back(pair<int, int>(i + 1, j));
                    }
                    if (j > 0)
                    {
                        searching.push_back(pair<int, int>(i, j - 1));
                    }
                    if (j < isWater[0].size() - 1)
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
            if (cur.first < isWater.size() - 1)
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
            if (cur.second < isWater[0].size() - 1)
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




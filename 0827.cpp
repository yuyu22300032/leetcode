/*
827. Making A Large Island


Description:

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 500
    grid[i][j] is either 0 or 1.

*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int x_diff[4] = {0, 0, 1, -1};
        int y_diff[4] = {1, -1, 0, 0};
        vector<int> island_size;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int cur_cnt = 1;
                    int sidx = 0;
                    grid[i][j] = island_size.size() + 2;
                    vector<pair<int, int>> search;
                    search.push_back(pair<int, int>(i, j));
                    while (sidx < search.size())
                    {
                        for (int k = 0; k < 4; ++k)
                        {
                            int new_x = search[sidx].second + x_diff[k];
                            if (new_x < 0 || new_x >= grid[0].size())
                            {
                                continue;
                            }
                            int new_y = search[sidx].first + y_diff[k];
                            if (new_y < 0 || new_y >= grid.size())
                            {
                                continue;
                            }
                            if (grid[new_y][new_x] == 1)
                            {
                                cur_cnt++;
                                grid[new_y][new_x] = island_size.size() + 2;
                                search.push_back(pair<int, int>(new_y, new_x));
                            }
                        }
                        sidx++;
                    }
                    island_size.push_back(cur_cnt);
                }
            }
        }
        int out = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    set<int> island_idx;
                    for (int k = 0; k < 4; ++k)
                    {
                        int new_x = j + x_diff[k];
                        if (new_x < 0 || new_x >= grid[0].size())
                        {
                            continue;
                        }
                        int new_y = i + y_diff[k];
                        if (new_y < 0 || new_y >= grid.size())
                        {
                            continue;
                        }
                        island_idx.insert(grid[new_y][new_x]);
                    }
                    int cur_cnt = 1;
                    for (set<int>::iterator it = island_idx.begin(); it != island_idx.end(); ++it)
                    {
                        if (*it > 1)
                        {
                            cur_cnt += island_size[*it - 2];
                        }
                    }
                    out = max(cur_cnt, out);
                }
            }
        }
        if (out == 0)
        {
            out = grid.size() * grid[0].size();
        }

        return out;
    }
};


/*
2658. Maximum Number of Fish in a Grid


Description:

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

    A land cell if grid[r][c] = 0, or
    A water cell containing grid[r][c] fish, if grid[r][c] > 0.

A fisher can start at any water cell (r, c) and can do the following operations any number of times:

    Catch all the fish at cell (r, c), or
    Move to any adjacent water cell.

Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

Example 1:

Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    0 <= grid[i][j] <= 10


*/

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int out = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }
                int fish = grid[i][j];
                grid[i][j] = 0;
                queue<pair<int, int>> search;
                search.push(pair<int, int>(i, j));
                while (! search.empty())
                {
                    pair<int, int> cur = search.front();
                    search.pop();
                    int x_diff[4] = {0, 0, 1, -1};
                    int y_diff[4] = {1, -1, 0, 0};
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> new_pos(cur.first + x_diff[k], cur.second + y_diff[k]);
                        if (new_pos.first < 0 || new_pos.first >= grid.size() || new_pos.second < 0 || new_pos.second >= grid[i].size())
                        {
                            continue;
                        }
                        if (grid[new_pos.first][new_pos.second] > 0)
                        {
                            fish += grid[new_pos.first][new_pos.second];
                            grid[new_pos.first][new_pos.second] = 0;
                            search.push(new_pos);
                        }
                    }
                }
                out = max(out, fish);
            }
        }
        return out;
    }
};



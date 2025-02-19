/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid


Description:

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

    1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
    2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
    3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
    4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:

Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.

Example 2:

Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).

Example 3:

Input: grid = [[1,2],[4,3]]
Output: 1

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    1 <= grid[i][j] <= 4

*/

class Solution {
public:
    struct Pos {
        int i;
        int j;
    };
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> costs(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        costs[0][0] = 0;
        multimap<int, Pos> searching;
        searching.insert(pair<int, Pos>{0, Pos{0, 0}});
        while (searching.size() > 0)
        {
            multimap<int, Pos>::iterator it = searching.begin();
            Pos cur_pos = it->second;
            int cur_cost = it->first;
            if (cur_cost >= costs[costs.size() - 1][costs[0].size() - 1])
            {
                break;
            }
            searching.erase(it);
            if (cur_pos.j + 1 < grid[0].size())
            {
                int new_cost = cur_cost;
                if (grid[cur_pos.i][cur_pos.j] != 1)
                {
                    new_cost++;
                }
                if (new_cost < costs[cur_pos.i][cur_pos.j + 1])
                {
                    costs[cur_pos.i][cur_pos.j + 1] = new_cost;
                    searching.insert(pair<int, Pos>{new_cost, Pos{cur_pos.i, cur_pos.j + 1}});
                }
            }
            if (cur_pos.j - 1 >= 0)
            {
                int new_cost = cur_cost;
                if (grid[cur_pos.i][cur_pos.j] != 2)
                {
                    new_cost++;
                }
                if (new_cost < costs[cur_pos.i][cur_pos.j - 1])
                {
                    costs[cur_pos.i][cur_pos.j - 1] = new_cost;
                    searching.insert(pair<int, Pos>{new_cost, Pos{cur_pos.i, cur_pos.j - 1}});
                }
            }
            if (cur_pos.i + 1 < grid.size())
            {
                int new_cost = cur_cost;
                if (grid[cur_pos.i][cur_pos.j] != 3)
                {
                    new_cost++;
                }
                if (new_cost < costs[cur_pos.i + 1][cur_pos.j])
                {
                    costs[cur_pos.i + 1][cur_pos.j] = new_cost;
                    searching.insert(pair<int, Pos>{new_cost, Pos{cur_pos.i + 1, cur_pos.j}});
                }
            }
            if (cur_pos.i - 1 >= 0)
            {
                int new_cost = cur_cost;
                if (grid[cur_pos.i][cur_pos.j] != 4)
                {
                    new_cost++;
                }
                if (new_cost < costs[cur_pos.i - 1][cur_pos.j])
                {
                    costs[cur_pos.i - 1][cur_pos.j] = new_cost;
                    searching.insert(pair<int, Pos>{new_cost, Pos{cur_pos.i - 1, cur_pos.j}});
                }
            }
        }
        return costs[costs.size() - 1][costs[0].size() - 1];
    }
};




/*
2812. Find the Safest Path in a Grid


Description:

You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

    A cell containing a thief if grid[r][c] = 1
    An empty cell if grid[r][c] = 0

You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

 

Example 1:

Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).

Example 2:

Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

Example 3:

Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

 

Constraints:

    1 <= grid.length == n <= 400
    grid[i].length == n
    grid[i][j] is either 0 or 1.
    There is at least one thief in the grid.


*/

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // calculate each cell score
        vector<vector<int>> safe_grid(grid.size(), vector<int>(grid[0].size(), -1));
        {
            queue<pair<int, pair<int, int>>> searching;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 1) {
                        searching.push({0, {i, j}});
                        safe_grid[i][j] = 0;
                    }
                }
            }
            while (!searching.empty()) {
                pair<int, pair<int, int>> cur = searching.front();
                searching.pop();
                int x = cur.second.first;
                int y = cur.second.second;
                if (x > 0) {
                    if (safe_grid[x - 1][y] == -1) {
                        safe_grid[x - 1][y] = cur.first + 1;
                        searching.push({safe_grid[x - 1][y], {x - 1, y}});
                    }
                }
                if (x < grid.size() - 1) {
                    if (safe_grid[x + 1][y] == -1) {
                        safe_grid[x + 1][y] = cur.first + 1;
                        searching.push({safe_grid[x + 1][y], {x + 1, y}});
                    }
                }
                if (y > 0) {
                    if (safe_grid[x][y - 1] == -1) {
                        safe_grid[x][y - 1] = cur.first + 1;
                        searching.push({safe_grid[x][y - 1], {x, y - 1}});
                    }
                }
                if (y < grid[0].size() - 1) {
                    if (safe_grid[x][y + 1] == -1) {
                        safe_grid[x][y + 1] = cur.first + 1;
                        searching.push({safe_grid[x][y + 1], {x, y + 1}});
                    }
                }
            }
        }

        // find safest path
        vector<vector<int>> scores(grid.size(), vector<int>(grid[0].size(), -1));
        priority_queue<pair<int, pair<int, int>>> searching;
        searching.push({safe_grid[0][0], {0, 0}});
        while (!searching.empty()) {
            pair<int, pair<int, int>> cur = searching.top();
            searching.pop();
            int x = cur.second.first;
            int y = cur.second.second;
            if ((x == grid.size() - 1) && (y == grid[0].size() - 1)) {
                return cur.first;
            }
            if (cur.first == 0) {
                return 0;
            }
            if (cur.first < scores[x][y]) {
                continue;
            }
            if (x > 0) {
                int next_score = min(cur.first, safe_grid[x - 1][y]);
                if (scores[x - 1][y] < next_score) {
                    scores[x - 1][y] = next_score;
                    searching.push({scores[x - 1][y], {x - 1, y}});
                }
            }
            if (x < grid.size() - 1) {
                int next_score = min(cur.first, safe_grid[x + 1][y]);
                if (scores[x + 1][y] < next_score) {
                    scores[x + 1][y] = next_score;
                    searching.push({scores[x + 1][y], {x + 1, y}});
                }
            }
            if (y > 0) {
                int next_score = min(cur.first, safe_grid[x][y - 1]);
                if (scores[x][y - 1] < next_score) {
                    scores[x][y - 1] = next_score;
                    searching.push({scores[x][y - 1], {x, y - 1}});
                }
            }
            if (y < grid[0].size() - 1) {
                int next_score = min(cur.first, safe_grid[x][y + 1]);
                if (scores[x][y + 1] < next_score) {
                    scores[x][y + 1] = next_score;
                    searching.push({scores[x][y + 1], {x, y + 1}});
                }
            }
        }
        return 0;
    }
};

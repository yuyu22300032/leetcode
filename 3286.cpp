/*
3286. Find a Safe Walk Through a Grid


Description:

You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.

Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.

Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.

Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    2 <= m * n
    1 <= health <= m + n
    grid[i][j] is either 0 or 1.


*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> scores(grid.size(), vector<int>(grid[0].size(), 0));
        priority_queue<pair<int, pair<int, int>>> searching;
        searching.push({health - grid[0][0], {0, 0}});
        while (!searching.empty()) {
            pair<int, pair<int, int>> cur = searching.top();
            searching.pop();
            int& x = cur.second.first;
            int& y = cur.second.second;
            if ((x == grid.size() - 1) && (y == grid[0].size() - 1)) {
                return cur.first > 0;
            }
            if (cur.first == 0) {
                break;
            }
            if (x > 0) {
                if (scores[x - 1][y] == 0) {
                    scores[x - 1][y] = cur.first - grid[x - 1][y];
                    searching.push({scores[x - 1][y], {x - 1, y}});
                }
            }
            if (x < grid.size() - 1) {
                if (scores[x + 1][y] == 0) {
                    scores[x + 1][y] = cur.first - grid[x + 1][y];
                    searching.push({scores[x + 1][y], {x + 1, y}});
                }
            }
            if (y > 0) {
                if (scores[x][y - 1] == 0) {
                    scores[x][y - 1] = cur.first - grid[x][y - 1];
                    searching.push({scores[x][y - 1], {x, y - 1}});
                }
            }
            if (y < grid[0].size() - 1) {
                if (scores[x][y + 1] == 0) {
                    scores[x][y + 1] = cur.first - grid[x][y + 1];
                    searching.push({scores[x][y + 1], {x, y + 1}});
                }
            }
        }
        return false;
    }
};

/*
1559. Detect Cycles in 2D Grid


Description:

Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

 

Example 1:

Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:

Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:

Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid consists only of lowercase English letters.


*/

class Solution {
    struct Node {
        int x;
        int y;
        int prev_x;
        int prev_y;
        Node(int _x, int _y, int _prev_x = -1, int _prev_y = -1) {
            x = _x;
            y = _y;
            prev_x = _prev_x;
            prev_y = _prev_y;
        }
    };
    vector<Node> getNeighbors(Node& cur, vector<vector<char>>& grid) {
        vector<Node> out;
        if (cur.x > 0 && grid[cur.x][cur.y] == grid[cur.x - 1][cur.y]) {
            out.push_back(Node(cur.x - 1, cur.y, cur.x, cur.y));
        }
        if (cur.x + 1 < grid.size() && grid[cur.x][cur.y] == grid[cur.x + 1][cur.y]) {
            out.push_back(Node(cur.x + 1, cur.y, cur.x, cur.y));
        }
        if (cur.y > 0 && grid[cur.x][cur.y] == grid[cur.x][cur.y - 1]) {
            out.push_back(Node(cur.x, cur.y - 1, cur.x, cur.y));
        }
        if (cur.y + 1 < grid[0].size() && grid[cur.x][cur.y] == grid[cur.x][cur.y + 1]) {
            out.push_back(Node(cur.x, cur.y + 1, cur.x, cur.y));
        }
        return move(out);
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j]) {
                    continue;
                }
                queue<Node> search;
                search.push(Node(i, j));
                visited[i][j] = true;
                while (!search.empty()) {
                    Node cur = search.front();
                    search.pop();
                    vector<Node> neighbors = getNeighbors(cur, grid);
                    for (int i = 0; i < neighbors.size(); i++) {
                        if (visited[neighbors[i].x][neighbors[i].y]) {
                            if (neighbors[i].x != cur.prev_x || neighbors[i].y != cur.prev_y) {
                                return true;
                            }
                        } else {
                            search.push(neighbors[i]);
                            visited[neighbors[i].x][neighbors[i].y] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

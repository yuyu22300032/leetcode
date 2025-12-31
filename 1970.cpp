/*
1970. Last Day Where You Can Still Cross


Description:

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:

Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:

Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:

Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

 

Constraints:

    2 <= row, col <= 2 * 104
    4 <= row * col <= 2 * 104
    cells.length == row * col
    1 <= ri <= row
    1 <= ci <= col
    All the values of cells are unique.

*/

class Solution {
    void explore(vector<vector<bool>>& grid, vector<vector<bool>>& visited, pair<int, int>& cur, queue<pair<int, int>>& searching) {
        if (cur.first > 0) {
            if (grid[cur.first - 1][cur.second]) {
                if (! visited[cur.first - 1][cur.second]) {
                    searching.push(pair<int, int>(cur.first - 1, cur.second));
                }
            }
        }
        if (cur.first + 1 < grid.size()) {
            if (grid[cur.first + 1][cur.second]) {
                if (! visited[cur.first + 1][cur.second]) {
                    searching.push(pair<int, int>(cur.first + 1, cur.second));
                }
            }
        }
        if (cur.second > 0) {
            if (grid[cur.first][cur.second - 1]) {
                if (! visited[cur.first][cur.second - 1]) {
                    searching.push(pair<int, int>(cur.first, cur.second - 1));
                }
            }
        }
        if (cur.second + 1 < grid[0].size()) {
            if (grid[cur.first][cur.second + 1]) {
                if (! visited[cur.first][cur.second + 1]) {
                    searching.push(pair<int, int>(cur.first, cur.second + 1));
                }
            }
        }
    }

    bool checkPathExist(vector<vector<bool>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> searching;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i]) {
                searching.push(pair<int, int>(0, i));
            }
        }
        while (searching.size() > 0) {
            pair<int, int> cur = searching.front();
            searching.pop();
            if (cur.first == grid.size() - 1) {
                return true;
            }
            if (visited[cur.first][cur.second]) {
                continue;
            }
            visited[cur.first][cur.second] = true;
            explore(grid, visited, cur, searching);
        }
        return false;
    }

    void updateGrid(vector<vector<bool>>& grid, vector<vector<int>>& cells, int day) {
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = false;
        }
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0;
        int right = cells.size();
        while (left != right) {
            int mid = (left + right) / 2;
            vector<vector<bool>> grid(row, vector<bool>(col, true));
            updateGrid(grid, cells, mid);
            if (checkPathExist(grid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (right == cells.size()) {
            return right;
        }
        return right - 1;
    }
};

/*
1594. Maximum Non Negative Product in a Matrix


Description:

You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.

 

Example 1:

Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example 2:

Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).

Example 3:

Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 15
    -4 <= grid[i][j] <= 4


*/

class Solution {
    struct Node {
        long long maxVal;
        long long minVal;
    };
    void updateVal(Node &node, long long val) {
        node.maxVal = max(node.maxVal, val);
        node.minVal = min(node.minVal, val);
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1000000007;
        vector<vector<Node>> nodes(grid.size(), vector<Node>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    nodes[0][0].maxVal = grid[0][0];
                    nodes[0][0].minVal = grid[0][0];
                    continue;
                }
                nodes[i][j].maxVal = LLONG_MIN;
                nodes[i][j].minVal = LLONG_MAX;
                if (i > 0) {
                    updateVal(nodes[i][j], nodes[i - 1][j].maxVal * grid[i][j]);
                    updateVal(nodes[i][j], nodes[i - 1][j].minVal * grid[i][j]);
                }
                if (j > 0) {
                    updateVal(nodes[i][j], nodes[i][j - 1].maxVal * grid[i][j]);
                    updateVal(nodes[i][j], nodes[i][j - 1].minVal * grid[i][j]);
                }
            }
        }
        if (nodes.back().back().maxVal >= 0) {
            return nodes.back().back().maxVal % mod;
        }
        return -1;
    }
};

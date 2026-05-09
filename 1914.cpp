/*
1914. Cyclically Rotating a Grid


Description:

You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:

Return the matrix after applying k cyclic rotations to it.

 

Example 1:

Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.

Example 2:

Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.

 

Constraints:

    m == grid.length
    n == grid[i].length
    2 <= m, n <= 50
    Both m and n are even integers.
    1 <= grid[i][j] <= 5000
    1 <= k <= 109


*/

class Solution {
    pair<int, int> cntToXY(int cnt, int x_size, int y_size) {
        if (cnt < x_size) {
            return {cnt, 0};
        }
        cnt -= (x_size - 1);
        if (cnt < y_size) {
            return {x_size - 1, cnt};
        }
        cnt -= (y_size - 1);
        if (cnt < x_size) {
            return {x_size - 1 - cnt, y_size - 1};
        }
        cnt -= (x_size - 1);
        return {0, y_size - 1 - cnt};
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> out(grid.size(), vector<int>(grid[0].size(), 0));
        int layers = min(grid.size(), grid[0].size()) / 2;
        for (int l = 0; l < layers; l++) {
            int x_size = grid[0].size() - 2 * l;
            int y_size = grid.size() - 2 * l;
            int cnt = (x_size + y_size) * 2 - 4;
            for (int i = 0; i < cnt; i++) {
                pair<int, int> ori = cntToXY(i, x_size, y_size);
                pair<int, int> tar = cntToXY((i + k) % cnt, x_size, y_size);
                out[ori.second + l][ori.first + l] = grid[tar.second + l][tar.first + l];
            }
        }
        return out;
    }
};

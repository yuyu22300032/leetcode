/*
3546. Equal Sum Grid Partition I


Description:

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

    Each of the two resulting sections formed by the cut is non-empty.
    The sum of the elements in both sections is equal.

Return true if such a partition exists; otherwise return false.

 

Example 1:

Input: grid = [[1,4],[2,3]]

Output: true

Explanation:

A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

Example 2:

Input: grid = [[1,3],[2,4]]

Output: false

Explanation:

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

 

Constraints:

    1 <= m == grid.length <= 105
    1 <= n == grid[i].length <= 105
    2 <= m * n <= 105
    1 <= grid[i][j] <= 105


*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                sum += grid[i][j];
            }
        }
        long long part1 = 0;
        long long part2 = sum;
        for (int i = 0; i < grid.size(); i++) {
            long long row = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                row += grid[i][j];
            }
            part1 += row;
            part2 -= row;
            if (part1 == part2) {
                return true;
            }
        }
        part1 = 0;
        part2 = sum;
        for (int j = 0; j < grid[0].size(); j++) {
            long long col = 0;
            for (int i = 0; i < grid.size(); i++) {
                col += grid[i][j];
            }
            part1 += col;
            part2 -= col;
            if (part1 == part2) {
                return true;
            }
        }
        return false;
    }
};

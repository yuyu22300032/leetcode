/*
1411. Number of Ways to Paint N × 3 Grid


Description:

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.

Example 2:

Input: n = 5000
Output: 30228214

 

Constraints:

    n == grid.length
    1 <= n <= 5000


*/

class Solution {
public:
    int numOfWays(int n) {
        int two_colors = 6;
        int three_colors = 6;
        const int mod = 1000000007;
        for (int i = 1; i < n; i++) {
            // two_color will be two_color * 3 + three_colors * 2
            // three_colors will be two_color * 2 + three_colors * 2
            int new_two_colors = (((two_colors * 2 % mod) + two_colors) % mod + (three_colors * 2 % mod)) % mod;
            three_colors = ((two_colors * 2 % mod) + (three_colors * 2 % mod)) % mod;
            two_colors = new_two_colors;
        }
        return (two_colors + three_colors) % mod;
    }
};

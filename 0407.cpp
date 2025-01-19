/*
407. Trapping Rain Water II


Description:

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:

Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2:

Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10

 

Constraints:

    m == heightMap.length
    n == heightMap[i].length
    1 <= m, n <= 200
    0 <= heightMap[i][j] <= 2 * 104

*/

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        vector<vector<bool>> searched(heightMap.size(), vector<bool>(heightMap[0].size(), false));
        multimap<int, pair<int, int>> bound;  // {height, {x, y}}

        for (int i = 0; i < heightMap.size(); i++)
        {
            bound.insert(pair<int, pair<int, int>>(heightMap[i][0], pair<int, int>(i, 0)));
            bound.insert(pair<int, pair<int, int>>(heightMap[i][heightMap[0].size() - 1], pair<int, int>(i, heightMap[0].size() - 1)));
            searched[i][0] = true;
            searched[i][heightMap[0].size() - 1] = true;
        }
        for (int i = 0; i < heightMap[0].size(); i++)
        {
            bound.insert(pair<int, pair<int, int>>(heightMap[0][i], pair<int, int>(0, i)));
            bound.insert(pair<int, pair<int, int>>(heightMap[heightMap.size() - 1][i], pair<int, int>(heightMap.size() - 1, i)));
            searched[0][i] = true;
            searched[heightMap.size() - 1][i] = true;
        }

        int out = 0;
        while (! bound.empty())
        {
            multimap<int, pair<int, int>>::iterator it = bound.begin();
            int cur_x = it->second.first;
            int cur_y = it->second.second;
            int min_height = it->first;
            bound.erase(it);
            int mod_x[4] = {0, 0, -1, 1};
            int mod_y[4] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                int new_x = cur_x + mod_x[i];
                int new_y = cur_y + mod_y[i];
                if (new_x < 0 || new_x >= heightMap.size() || new_y < 0 || new_y >= heightMap[0].size())
                {
                    continue;
                }
                if (searched[new_x][new_y])
                {
                    continue;
                }

                if (heightMap[new_x][new_y] < min_height) {
                    out += min_height - heightMap[new_x][new_y];
                    bound.insert(pair<int, pair<int, int>>(min_height, pair<int, int>(new_x, new_y)));
                }
                else
                {
                    bound.insert(pair<int, pair<int, int>>(heightMap[new_x][new_y], pair<int, int>(new_x, new_y)));
                }
                searched[new_x][new_y] = true;
            }
        }

        return out;
    }
};


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
    struct Pos {
        int height;
        int x;
        int y;

        Pos(int _height, int _x, int _y)
        : height(_height)
        , x(_x)
        , y(_y) {}

        bool operator<(const Pos& _other) const {
            return height < _other.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap)
    {
        vector<vector<bool>> searched(heightMap.size(), vector<bool>(heightMap[0].size(), false));
        priority_queue<Pos> bound;

        for (int i = 0; i < heightMap.size(); i++)
        {
            bound.push(Pos(-heightMap[i][0], i, 0));
            bound.push(Pos(-heightMap[i][heightMap[0].size() - 1], i, heightMap[0].size() - 1));
            searched[i][0] = true;
            searched[i][heightMap[0].size() - 1] = true;
        }
        for (int i = 0; i < heightMap[0].size(); i++)
        {
            bound.push(Pos(-heightMap[0][i], 0, i));
            bound.push(Pos(-heightMap[heightMap.size() - 1][i], heightMap.size() - 1, i));
            searched[0][i] = true;
            searched[heightMap.size() - 1][i] = true;
        }

        int out = 0;
        while (! bound.empty())
        {
            Pos cur = bound.top();
            bound.pop();
            int min_height = -cur.height;
            int mod_x[4] = {0, 0, -1, 1};
            int mod_y[4] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                int new_x = cur.x + mod_x[i];
                int new_y = cur.y + mod_y[i];
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
                    bound.push(Pos(-min_height, new_x, new_y));
                }
                else
                {
                    bound.push(Pos(-heightMap[new_x][new_y], new_x, new_y));
                }
                searched[new_x][new_y] = true;
            }
        }

        return out;
    }
};


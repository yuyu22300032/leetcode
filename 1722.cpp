/*
1722. Minimize Hamming Distance After Swap Operations


Description:

You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

Example 1:

Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.

Example 2:

Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.

Example 3:

Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0

 

Constraints:

    n == source.length == target.length
    1 <= n <= 105
    1 <= source[i], target[i] <= 105
    0 <= allowedSwaps.length <= 105
    allowedSwaps[i].length == 2
    0 <= ai, bi <= n - 1
    ai != bi


*/

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < allowedSwaps.size(); i++) {
            edges[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            edges[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        int out = 0;
        vector<bool> checked(source.size(), false);
        for (int i = 0; i < source.size(); i++) {
            if (checked[i]) {
                continue;
            }
            queue<int> searching;
            searching.push(i);
            unordered_map<int, int> nums;
            while (!searching.empty()) {
                int cur = searching.front();
                searching.pop();
                if (checked[cur]) {
                    continue;
                }
                nums[source[cur]] += 1;
                nums[target[cur]] -= 1;
                checked[cur] = true;
                for (int j = 0; j < edges[cur].size(); j++) {
                    if (checked[edges[cur][j]]) {
                        continue;
                    }
                    searching.push(edges[cur][j]);
                }
            }
            for (unordered_map<int, int>::iterator it = nums.begin(); it != nums.end(); it++) {
                if (it->second > 0) {
                    out += it->second;
                }
            }
        }
        return out;
    }
};

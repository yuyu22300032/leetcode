/*
3488. Closest Equal Element Queries


Description:

You are given a circular array nums and an array queries.

For each query i, you have to find the following:

    The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.

Return an array answer of the same size as queries, where answer[i] represents the result for query i.

 

Example 1:

Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

Output: [2,-1,3]

Explanation:

    Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
    Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
    Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).

Example 2:

Input: nums = [1,2,3,4], queries = [0,1,2,3]

Output: [-1,-1,-1,-1]

Explanation:

Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.

 

Constraints:

    1 <= queries.length <= nums.length <= 105
    1 <= nums[i] <= 106
    0 <= queries[i] < nums.length


*/

class Solution {
    int findDist(int numsSize, int idx1, int idx2) {
        if (idx1 > idx2) {
            int tmp = idx1;
            idx1 = idx2;
            idx2 = tmp;
        }
        int out = idx2 - idx1;
        out = min(out, idx1 + numsSize - idx2);
        return out;
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, set<int>> numsMap;
        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]].insert(i);
        }
        vector<int> out(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            unordered_map<int, set<int>>::iterator it = numsMap.find(nums[queries[i]]);
            if (it == numsMap.end() || it->second.size() == 1) {
                out[i] = -1;
                continue;
            }
            out[i] = INT_MAX;
            set<int>::iterator cur = it->second.find(queries[i]);
            set<int>::iterator prev = cur;
            if (prev == it->second.begin()) {
                prev = it->second.end();
            }
            prev--;
            if (cur != prev) {
                out[i] = min(out[i], findDist(nums.size(), *cur, *prev));
            }
            set<int>::iterator next = cur;
            next++;
            if (next == it->second.end()) {
                next = it->second.begin();
            }
            if (cur != next) {
                out[i] = min(out[i], findDist(nums.size(), *cur, *next));
            }
        }
        return move(out);
    }
};

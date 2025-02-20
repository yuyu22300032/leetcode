/*
56. Merge Intervals


Description:

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104


*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> sorted_intervals;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (sorted_intervals.count(intervals[i][0]) == 0)
            {
                sorted_intervals.insert(pair<int, int>(intervals[i][0], intervals[i][1]));
            }
            else
            {
                sorted_intervals[intervals[i][0]] = max(sorted_intervals[intervals[i][0]], intervals[i][1]);
            }
        }
        vector<vector<int>> out;
        vector<int> cur(2);
        map<int, int>::iterator it = sorted_intervals.begin();
        cur[0] = it->first;
        cur[1] = it->second;
        it++;
        while (it != sorted_intervals.end())
        {
            if (it->first <= cur[1])
            {
                cur[1] = max(cur[1], it->second);
            }
            else
            {
                out.push_back(cur);
                cur[0] = it->first;
                cur[1] = it->second;
            }
            ++it;
        }
        out.push_back(cur);
        return out;
    }
};

